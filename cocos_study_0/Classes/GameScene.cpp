
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

	CreateBackgroundLayer();
	CreateUILayer();
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

void GameScene::update(float dt)
{
	mpActor->MoveActor(dt);	
	mpActor->Dir_Selector();

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

Vec2 GameScene::ColisionGeometry()
{
	int tDir = 0;
	Vec2 tVec = Vec2(0,0);
	tDir = mpActor->GetDir();

	switch (tDir)
	{
	case Up_Dir:
	case Down_Dir:
	{
		if(mpActor->GetColisionBox()->getBoundingBox() && 

	}
	break;

	case Left_Dir:
	case Right_Dir:
	{


	}
	break;
	}

	return tVec;
}

/*

//터치를 받아서 tcol, trow를 구하는 것임.
//Actor의 위치에 따라서 tCol, tRow를 구하면 될 것 같다.
//트리거는 Move

//auto tPos = tMap->convertTouchToNodeSpace(touch);

float tTileW = tMap->getTileSize().width;
float tTileH = tMap->getTileSize().height;

float tTotalRowCount = tMap->getMapSize().height;

int tCol = tPos.x / tTileW;
int tRow = tTotalRowCount - tPos.y / tTileH;

log("Row : %d, Col : %d ", tRow, tCol);
log("tTileW : %f, tTileH : %f ", tTileW, tTileH);

int tResult = GetAttributeWith(tRow, tCol);
log("GetAttributeWith : %d", tResult);

return true;
}



*/