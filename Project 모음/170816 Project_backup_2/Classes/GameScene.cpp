#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CActor.h"

USING_NS_CC;

#define Map_Height 768
#define Map_Height_Reverse -768
#define Map_Width 1024
#define Map_Width_Reverse -1024


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
	CameraAction();
	CreateActor();
	//CreateAnimation();
	CreateBackground();

	return true;
}

void GameScene::CreateActor()
{
	mpActor = new CActor();
	mpActor->Create();
	mpActor->SetScene(this);
	mpActor->setPosition(Vec2(240, 100));
	mpActor->Build();
}


void GameScene::CreateAnimation()
{
	mpAniBox = new CAniBox();
	mpAniBox->Create();
	mpAniBox->SetScene(this);
	mpAniBox->Build();
	mpAniBox->setPosition(Vec2(240, 100));
	mpAniBox->RunAnimation();
}

void GameScene::CreateBackground()
{
	mpBackground = new CBackground();
	mpBackground->Create();
	mpBackground->SetScene(this);
	mpBackground->SetActor(mpActor);
	mpBackground->SetAnchorPoint(Vec2(0,0));
	mpBackground->SetPosition();
	mpBackground->ParallaxBackground();
	mpBackground->Build();
}


void GameScene::GameOver()
{
	mpGameOverLabel = Label::createWithTTF("GAME OVER", "fonts/BMJUA_ttf.ttf", 50);
	mpGameOverLabel->setPosition(Vec2(240, 360));
	this->addChild(mpGameOverLabel, 15);
}

void GameScene::CameraAction()
{
	mpCamera = new ActionCamera();
	mpCamera->startWithTarget(this);

}

float GameScene::CalcDistance()
{
	mDistance = sqrt(((mTouchX - mpActor->GetVecX())*(mTouchX - mpActor->GetVecX())) 
		+ (mTouchY - mpActor->GetVecY())*(mTouchY - mpActor->GetVecY()));

	return mDistance;
}


//배경이동에 따른 다른 이미지 이동
/*
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
*/

void GameScene::update(float dt)
{
	mpActor->MoveActor(dt);
	mpBackground->MoveBackground(dt);	
}

float GameScene::GetDistance()
{
	return mDistance;
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

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	this->unscheduleUpdate();
	
	mTouchX = touch->getLocation().x;
	mTouchY = touch->getLocation().y;

	this->CalcDistance();

	this->scheduleUpdate();

	//mpAniBox->AniMoveDown();


	return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	this->unscheduleUpdate();

	mTouchX = touch->getLocation().x;
	mTouchY = touch->getLocation().y;

	this->CalcDistance();

	this->scheduleUpdate();
}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
}

void GameScene::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
}

int GameScene::GetTouchX()
{
	return mTouchX;
}

int GameScene::GetTouchY()
{
	return mTouchY;
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