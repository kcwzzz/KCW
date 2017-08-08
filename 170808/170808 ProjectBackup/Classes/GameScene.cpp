#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CActor.h"
#include "CEnemy.h"

USING_NS_CC;

#define Map_Height 853
#define Map_Height_Reverse -853

Scene* GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CloseGame();	
	TitleBackGround();
	CreateActor();	
	CreateEnemy(10);
	CalcDistance();

	return true;
}

void GameScene::CreateActor()
{
	mpActor = new CActor();				//  CActor를 동적 할당
	mpActor->Create();					//  Sprite 생성 및 앵커포인트 설정
	mpActor->SetScene(this);			//  CActor가 GameScene(this)을 타겟하도록 설정
	mpActor->setPosition(Vec2(240, 300));	//  SetPosition
	mpActor->Build();					//  addChild

}

void GameScene::CreateEnemy(int EnemyCount)	//Vec 써서 배열로 나오게 한다.
											
{
	mpEnemy = new CEnemy();				//  CEnemy를 동적 할당
	mpEnemy->Create();					//  Sprite 생성 및 앵커포인트 설정
	mpEnemy->SetScene(this);			//  CEnemy가 GameScene(this)을 타겟하도록 설정
	mpEnemy->setPosition(Vec2(240, 600));	//  SetPosition
	mpEnemy->Build();					//  addChild
}

//배경
void  GameScene::TitleBackGround()
{
	//동일 이미지를 위아래로 뒤집어서 반복하게 노출
	mpSpriteA = Sprite::create("GameImage.jpg");
	mpSpriteA->retain();
	this->addChild(mpSpriteA, 0);

	mVecBackgroundA.x = 0;
	mVecBackgroundA.y = 0;
	mpSpriteA->setAnchorPoint(Vec2(0, 0));
	mpSpriteA->setPosition(mVecBackgroundA);
		
	mpSpriteB = Sprite::create("GameImage.jpg");
	mpSpriteB->setFlippedY(true);
	mpSpriteB->retain();

	mpSpriteB->setAnchorPoint(Vec2(0, 0));
	this->addChild(mpSpriteB, 0);

	mVecBackgroundB.x = 0;
	mVecBackgroundB.y = Map_Height;
	mpSpriteB->setPosition(mVecBackgroundB);
	
	ActionInterval *tAction = MoveBy::create(4, Vec2(0, Map_Height_Reverse));

	auto tSequence = Sequence::create(tAction,
		CallFunc::create(CC_CALLBACK_0(GameScene::OnCompleteAction, this)), NULL);

	RepeatForever *tRepeatForever = RepeatForever::create(tSequence);

	mpSpriteA->runAction(tRepeatForever);
	mpSpriteB->runAction(tRepeatForever->clone());
}
//배경이동에 따른 다른 이미지 이동
void GameScene::OnCompleteAction()
{
	if (mpSpriteA->getPositionY() <= Map_Height_Reverse)
	{
		mpSpriteA->setPositionY(Map_Height);
	}

	if (mpSpriteB->getPositionY() <= Map_Height_Reverse)
	{		
		mpSpriteB->setPositionY(Map_Height);
	}
}

void GameScene::onEnter()
{
	Scene::onEnter();// 장면 진입

					 //마우스 이벤트 등록

	mpListener = EventListenerTouchOneByOne::create();

	mpListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	mpListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	mpListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	mpListener->onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);
}

void GameScene::onExit()
{
	//마우스 이벤트 등록 해지
	_eventDispatcher->removeEventListener(mpListener);

	Scene::onExit();
}

float GameScene::CalcDistance()
{
	mDistance = sqrt(((mTouchPosition.x - mpActor->GetVec().x)*(mTouchPosition.x - mpActor->GetVec().x)) + (mTouchPosition.y - mpActor->GetVec().y)*(mTouchPosition.y - mpActor->GetVec().y));

	return mDistance;
}



void GameScene::update(float dt)
{		
	mpActor->Update(dt);	
	
}

Vec2 GameScene::GetTouchVec()
{
	return mTouchPosition;
}

float GameScene::GetDistance()
{
	return mDistance;
}


bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	mTouchPosition = touch->getLocation();

	CalcDistance();

	this->unscheduleUpdate();

	this->scheduleUpdate();

	return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

	mTouchPosition = touch->getLocation();

	CalcDistance();

	this->unscheduleUpdate();

	this->scheduleUpdate();
}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
}

void GameScene::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
}

void GameScene::CloseGame()
{
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(450, 25));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
}

void GameScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


