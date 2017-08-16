#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CActor.h"
#include "CVirtualPad.h"

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

	mpUILayer = new Layer();
	mpUILayer->create();
	mpUILayer->setPosition(Vec2(0, 0));
	mpUILayer->addChild(this, 8);

	mpVirtualPad = new CVirtualPad();
	mpVirtualPad->create(mpUILayer, Vec2(200, 200));

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
	mDistance = sqrt(((mTouchPosition.x - mpActor->GetVec().x)*(mTouchPosition.x - mpActor->GetVec().x)) + (mTouchPosition.y - mpActor->GetVec().y)*(mTouchPosition.y - mpActor->GetVec().y));

	return mDistance;
}


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

	mpListener = EventListenerTouchAllAtOnce::create();

	mpListener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
	mpListener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
	mpListener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
	mpListener->onTouchesCancelled = CC_CALLBACK_2(GameScene::onTouchesCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);
}

void GameScene::onExit()
{
	//마우스 이벤트 등록 해지
	_eventDispatcher->removeEventListener(mpListener);
	
	Scene::onExit();
}

void  GameScene::onTouchesBegan(const vector<Touch*>&touches, cocos2d::Event *unused_event)
{
	this->unscheduleUpdate();
	
	mpVirtualPad->TouchesBegan(touches, unused_event);

	this->CalcDistance();
	this->scheduleUpdate();

}

void GameScene::onTouchesMoved(const vector<Touch*>&touches, cocos2d::Event *unused_event)
{
	this->unscheduleUpdate();
	mpVirtualPad->TouchesMoved(touches, unused_event);
	this->CalcDistance();
	this->scheduleUpdate();
}

void GameScene::onTouchesEnded(const vector<Touch*>&touches, cocos2d::Event* unused_event)
{
	mpVirtualPad->TouchesEnded(touches, unused_event);
}

void GameScene::onTouchesCancelled(const vector<Touch*>&touches, cocos2d::Event* unused_event)
{
	mpVirtualPad->TouchesCancelled(touches, unused_event);
}

Vec2 GameScene:: GetTouchPosition()
{

	return mTouchPosition;
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