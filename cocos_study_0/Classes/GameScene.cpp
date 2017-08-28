
#include "GameScene.h"
#include "SimpleAudioEngine.h"

#include "CActor.h"

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
	
	CreateActor();	
	this->scheduleUpdate();

	

	return true;
}

void GameScene::CreateUILayer()
{
	mpUILayer = new CUILayer();
	mpUILayer = CUILayer::create();
	mpUILayer->CreateLayer();
	mpUILayer->VirtualPad();
	mpUILayer->CreateBtnClose();
	mpUILayer->GetDir();

	mpUILayer->SetScene(this);

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
	mpActor->SetScene(mpBackgroundLayer);
	mpActor->Create();

	mpActor->SetVirtualPad(mpUILayer->GetVirtualPad());

	mpActor->FollowActor();
	mpActor->setPosition(Vec2(300, 300));
	mpActor->Build();


}

void GameScene::update(float dt)
{

	mpActor->Dir_Selector();
	mpActor->MoveActor(dt);
	mpActor->FSM_Selector();


	
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

//ryu
void GameScene::TestActorBehavior()
{
	mpActor->AttackState();
}