#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CActor.h"
#include "CEnemy.h"
#include "CEnemy_1.h"
#include "CEnemy_2.h"
#include "EndGameScene.h"


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
	CreateEnemy_1(10);
	CreateEnemy_2(10);

	this->schedule(schedule_selector(GameScene::ReadyToFire_Actor), 0.4f);
	this->schedule(schedule_selector(GameScene::ReadyToFire_Enemy), 1.0f);

	this->schedule(schedule_selector(GameScene::CreateEnemy_1), 10.0f);
	this->schedule(schedule_selector(GameScene::CreateEnemy_1), 15.0f);
	this->schedule(schedule_selector(GameScene::CreateEnemy_2), 20.0f);


	mpScore = Label::createWithTTF("State: 0 and Type: 0", "fonts/Marker Felt.ttf", 24);
	mpScore->retain();
	mpScore->setPosition(Vec2(240, 700));
	mpScore->setString("Score : ");
	this->addChild(mpScore, 2);

	return true;
}

void GameScene::PrintScore()
{
	char tszTemp[512];
	memset(tszTemp, 0, 512);
	std::sprintf(tszTemp, "Score : %d", mScore);
	std::string tString = tszTemp;
	mpScore->setString(tString);
}

void GameScene::SetScore(int tScore)
{
	mScore = mScore + tScore;
}


void GameScene::CreateActor()
{
	mpActor = new CActor();				//  CActor를 동적 할당
	mpActor->Create();					//  Sprite 생성 및 앵커포인트 설정
	mpActor->SetScene(this);			//  CActor가 GameScene(this)을 타겟하도록 설정
	mpActor->setPosition(Vec2(240, 100));	//  SetPosition
	mpActor->Build();					//  addChild
	

}

void GameScene::CreateEnemy(float f)	//Vec 써서 배열로 나오게 한다.

{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mpEnemy[ti] = new CEnemy();				//  CEnemy를 동적 할당
		mpEnemy[ti]->Create();					//  Sprite 생성 및 앵커포인트 설정
		mpEnemy[ti]->SetScene(this);			//  CEnemy가 GameScene(this)을 타겟하도록 설정
		mpEnemy[ti]->setPosition(Vec2(0 - 120 * ti, 450 + 20 * ti));	//  SetPosition
		mpEnemy[ti]->Build();					//  addChild
	}
}

void GameScene::CreateEnemy_1(float f)	//Vec 써서 배열로 나오게 한다.
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mpEnemy_1[ti] = NULL;
		mpEnemy_1[ti] = new CEnemy_1();
		mpEnemy_1[ti]->Create();
		mpEnemy_1[ti]->SetScene(this);			//  CEnemy가 GameScene(this)을 타겟하도록 설정
		mpEnemy_1[ti]->setPosition(Vec2(80 + 120 * ti, 720 + 120 * ti));	//  SetPosition
		mpEnemy_1[ti]->Build();
	}
}

void GameScene::CreateEnemy_2(float f)	//Vec 써서 배열로 나오게 한다.
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mpEnemy_2[ti] = NULL;
		mpEnemy_2[ti] = new CEnemy_2();
		mpEnemy_2[ti]->Create();
		mpEnemy_2[ti]->SetScene(this);			//  CEnemy가 GameScene(this)을 타겟하도록 설정
		mpEnemy_2[ti]->setPosition(Vec2(720 - 120 * ti, 600 + 80 * ti));	//  SetPosition
		mpEnemy_2[ti]->Build();
	}
}

void GameScene::ReadyToFire_Actor(float f)
{
	mpActor->ReadyToFire(f);

}

void GameScene::ReadyToFire_Enemy(float f)
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mpEnemy[ti]->ReadyToFire(f);
	}

	int tj = 0;
	for (tj = 0; tj < 10; tj++)
	{
		mpEnemy_2[tj]->ReadyToFire(f);
	}

}
//배경

void GameScene::SceneChange(Object *pSender)
{
	auto pScene = EndGameScene::createScene();
	//Director::getInstance()->replaceScene(createTransition(1, 1, pScene));
}

void GameScene::GameOver()
{
	mpGameOverLabel = Label::createWithTTF("GAME OVER", "fonts/BMJUA_ttf.ttf", 50);
	mpGameOverLabel->setPosition(Vec2(240, 360));
	this->addChild(mpGameOverLabel, 15);
}

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

//float GameScene::CalcDistance()
float GameScene::CalcDistance()
{
	mDistance = sqrt(((mTouchPosition.x - mpActor->GetVec().x)*(mTouchPosition.x - mpActor->GetVec().x)) + (mTouchPosition.y - mpActor->GetVec().y)*(mTouchPosition.y - mpActor->GetVec().y));

	return mDistance;
}

void GameScene::update(float dt)
{
	mpActor->Update(dt);
	this->PrintScore();
	mpActor->BulletColision();


	int tl = 0;
	for (tl = 0; tl < 10; tl++)
	{
		mpActor->SetEnemyBulletVec(mpEnemy[tl]->GetEnemyBullets());
		mpActor->IsColision();
	}

	//ryu

	int tj = 0;
	for (tj = 0; tj < 10; tj++)
	{
		mpEnemy[tj]->Update(dt);
		mpEnemy[tj]->SetActorBulletVec(mpActor->GetActorBullets());
		mpEnemy[tj]->IsColision();
	}

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mpEnemy_1[ti]->Update(dt);
		mpEnemy_1[ti]->SetActorBulletVec(mpActor->GetActorBullets());
		mpEnemy_1[ti]->IsColision();
	}


	int tk = 0;
	for (tk = 0; tk < 10; tk++)
	{
		mpEnemy_2[tk]->Update(dt);
		mpEnemy_2[tk]->SetActorBulletVec(mpActor->GetActorBullets());
		mpEnemy_2[tk]->IsColision();
	}

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
	this->unscheduleUpdate();

	mTouchPosition = touch->getLocation();

	this->CalcDistance();

	this->scheduleUpdate();

	return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	this->unscheduleUpdate();

	mTouchPosition = touch->getLocation();

	this->CalcDistance();

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