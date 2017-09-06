
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CSound.h"

#include "CActor.h"
#include "CEnemy.h"

#include "CBackgroundLayer.h"
#include "CUILayer.h"
#include "Define.h"
#include "rapidjson\document.h"
#include "rapidjson\reader.h"


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

	CreateBackgroundLayer();
	CreateUILayer();
	CreateActor();
	CreateEnemy();

	CSound::Getinstance()->Create();
	//CSound::Getinstance()->PlayBGM(0);

	this->scheduleUpdate();

	return true;
}

void GameScene::CreateUILayer()
{
	mpUILayer = new CUILayer();
	mpUILayer = CUILayer::create();
	mpUILayer->CreateLayer();
	mpUILayer->VirtualPad();
	mpUILayer->CreateBtnAttack();
	mpUILayer->GetDir();
	mpUILayer->CreateBtnTestDamaged();

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
	mpActor->ActorHPGauge(mpUILayer);
	mpActor->SetVirtualPad(mpUILayer->GetVirtualPad());

	mpActor->FollowActor();
	mpActor->setPosition(Vec2(300, 300));
	mpActor->Build();
}

void GameScene::CreateEnemy()
{
	mpEnemy = new CEnemy();
	mpEnemy->SetScene(mpBackgroundLayer);
	mpEnemy->Create();
	mpEnemy->setPosition(Vec2(300, 300));
	mpEnemy->Build();
}

void GameScene::update(float dt)
{
	mpActor-> FSM_Selector();
	mpActor->MoveActor(dt);
	mpActor->Dir_Selector();

	mpEnemy->MovePatten(dt);
	this->Colision();
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

void GameScene::AttackBehavior()
{
	mpActor->AttackState();
}

void GameScene::MoveBehavior()
{
	mpActor->MoveState();
}

void GameScene::IdleBehavior()
{
	mpActor->IdleState();
}

void GameScene::DamagedActor()
{
	mpActor->SetDamaged(5);

}

void GameScene::Colision()
{
	CActor *tpActor = NULL;
	tpActor = mpActor;

	CEnemy *tpEnemy = NULL;
	tpEnemy = mpEnemy;

	Rect tRectActor = tpActor->GetSprite()->getBoundingBox();
	Rect tRectActorAttack = tpActor->GetAttackSprite()->getBoundingBox();
	Rect tRectEnemy = tpEnemy->GetSprite()->getBoundingBox();
	Rect tRectEnemyAttack = tpEnemy->GetAttackSprite()->getBoundingBox();

	// Actor의 공격이 Enemy를 맞출 경우
	if (true == mpActor->GetAttackSprite()->isVisible())
	{
		if (true == tRectActorAttack.intersectsRect(tRectEnemy))
		{
			//log("good");
		}
		else
		{
			//log("fuck");
		}
	}
	else
	{
		//log("invisible");
	}

	// Actor와 Enemy가 부딫히는 경우
	if (true == tRectActor.intersectsRect(tRectEnemy))
	{
		//log("crush");
	}
	else
	{
		//log("normal");
	}

}