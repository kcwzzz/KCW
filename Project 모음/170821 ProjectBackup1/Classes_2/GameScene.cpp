
#include "GameScene.h"
#include "SimpleAudioEngine.h"

#include "CActor.h"
#include "CAniBox.h"


#include "CBackgroundLayer.h"
#include "CUILayer.h"

#include "Define.h"


USING_NS_CC;



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
	
	winSize = Director::getInstance()->getWinSize();

	CreateUILayer();
	CreateBackgroundLayer();
	

	//CreateAnimation();
	CreateActor();
	/*
	float tVecX = 0.0f;
	float tVecY = 0.0f;

	tVecX = mpActor->GetDirectionX();
	tVecY = mpActor->GetDirectionY();

	if (tVecX >= -0.5 && tVecX < 0.5 && tVecY >= 0 && tVecY < 0.5)
	{

	}
	*/
	this->scheduleUpdate();
	//ScheduleUpdate를 init에서 하자.

	return true;
}

void GameScene::CreateAnimation()
{
	mpSprAni = Sprite::create("Hero.png");
	mpTexture = mpSprAni->getTexture();

	mpAnimation = Animation::create();
	mpAnimation->setDelayPerUnit(0.3f);
}

void GameScene::AniMoveDown()
{
	for (int i = 0; i < 3;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void GameScene::AniMoveLeft()
{
	for (int i = 3; i < 6;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void GameScene::AniMoveRight()
{
	for (int i = 7; i < 9;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void GameScene::AniMoveUp()
{
	for (int i = 9; i < 12;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}


void GameScene::Build()
{
	this->addChild(mpSprAni, 10);
}

void GameScene::RunAnimation()
{
	mpAnimate = Animate::create(mpAnimation);
	mpSprAni->runAction(mpAnimate);
}

void GameScene::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpActor->setPosition(mVec);
}

void GameScene::SetState(int tState)
{
	mState = tState;
}

void GameScene::Execute()
{
	(this->*mArray[mState])();
}






















void GameScene::CreateUILayer()
{
	mpUILayer = new CUILayer();
	mpUILayer = CUILayer::create();
	mpUILayer->CreateLayer();
	mpUILayer->VirtualPad();
	mpUILayer->CloseGame();

	this->addChild(mpUILayer, 100);
}

void GameScene::CreateBackgroundLayer()
{
	mpBackgroundLayer = new CBackgroundLayer();
	mpBackgroundLayer->Create();
	mpBackgroundLayer->SetScene(this);
	mpBackgroundLayer->SetActor(mpActor);
	mpBackgroundLayer->SetAnchorPoint(Vec2(0, 0));
	mpBackgroundLayer->SetPosition();
	mpBackgroundLayer->ParallaxBackground();
	mpBackgroundLayer->Build();
}

void GameScene::CreateActor()
{
	mpActor = new CActor();
	mpActor->create();
	mpActor->SetScene(mpBackgroundLayer);	
	mpActor->SetVirtualPad(mpUILayer->GetVirtualPad());
	mpActor->FollowActor();
	mpActor->setPosition(Vec2(0, 0));
	mpActor->Build();
}
/*
void GameScene::CreateAnimation()
{
	mpAniBox = new CAniBox();
	mpAniBox->Create();
	mpAniBox->SetScene(this);
	mpAniBox->Build();
	mpAniBox->setPosition(Vec2(240, 100));
	mpAniBox->RunAnimation();
}
*/

void GameScene::update(float dt)
{
	mpActor->MoveActor(dt);
}

void GameScene::onEnter()
{
	Scene::onEnter();// 장면 진입
	mpUILayer->SetUpListener();
}

void GameScene::onExit()
{
	mpUILayer->RemoveListener();
	Scene::onExit();
}