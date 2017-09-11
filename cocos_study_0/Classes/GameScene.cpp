
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CSound.h"

#include "CActor.h"
#include "CEnemy.h"
#include "CGuageHP.h"

#include "CBackgroundLayer.h"
#include "CUILayer.h"
#include "Define.h"
#include "rapidjson\document.h"
#include "rapidjson\reader.h"

#include "FSM_Manager.h"


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
	CSound::Getinstance()->PlayBGM(2);

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

void GameScene::CreateEnemy()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mpEnemy[ti] = new CEnemy();				//  CEnemy를 동적 할당
		mpEnemy[ti]->SetScene(mpBackgroundLayer);
		mpEnemy[ti]->Create();					//  Sprite 생성 및 앵커포인트 설정
		mpEnemy[ti]->setPosition(Vec2(0 + 120 * ti, 450 + 20 * ti));	//  SetPosition
		mpEnemy[ti]->Build();					//  addChild
	}
}

void GameScene::update(float dt)
{
	mpActor->FSM_Selector();
	mpActor->MoveActor();

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mpEnemy[ti]->MovePatten(dt);
	}

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
	mRectActor = mpActor->GetSprite()->getBoundingBox();
	mRectActorAttack = mpActor->GetAttackSprite()->getBoundingBox();

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mRectEnemy[ti] = mpEnemy[ti]->GetSprite()->getBoundingBox();
		mRectEnemyAttack[ti] = mpEnemy[ti]->GetAttackSprite()->getBoundingBox();
	

	// Actor의 공격이 Enemy를 맞출 경우
	if (true == mpActor->GetAttackSprite()->isVisible())
	{
		if (true == mRectActorAttack.intersectsRect(mRectEnemy[ti]))
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
	if (true == mRectActor.intersectsRect(mRectEnemy[ti]))
	{
		mpActor->SetDamaged(mpEnemy[ti]->GetAP());
		FSM_Manager::Getinstance()->SetNowState(DAMAGED);

		int tEnemyDir = mpEnemy[ti]->GetmDir();
		if (Up_Dir == tEnemyDir)
		{
			mpActor->setPosition(Vec2(mpActor->GetVec().x, mpActor->GetVec().y + 96));
		}
		else if (Down_Dir == tEnemyDir)
		{
			mpActor->setPosition(Vec2(mpActor->GetVec().x, mpActor->GetVec().y - 96));
		}
		else if (Left_Dir == tEnemyDir)
		{
			mpActor->setPosition(Vec2(mpActor->GetVec().x - 96, mpActor->GetVec().y));
		}
		else if (Right_Dir == tEnemyDir)
		{
			mpActor->setPosition(Vec2(mpActor->GetVec().x + 96, mpActor->GetVec().y));
		}
	}
	else
	{
		//log("normal");
	}
	}
}
