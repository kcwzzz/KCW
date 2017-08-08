#include "CActor.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActorBullet.h"

USING_NS_CC;

CActor::CActor()
{
	Clear();
}

CActor::~CActor()
{

}


void CActor::Clear()
{
	mVec = Vec2(0, 0);
	mSpeedPower = 0;
	mpUnitImage = NULL;
	mpScene = NULL;
}

void CActor::Create()
{
	//Create
	mpUnitImage = Sprite::create("actor.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mSpeedPower = 300.0f;

	mActorBullet = new CActorBullet();	
	mActorBullet->Create();
}

void CActor::Build()
{
	mpScene->addChild(mpUnitImage, 10);
	mActorBullet->Build();
}

void CActor::Update(float dt)
{
	mVec.x = mVec.x + ((mpScene->GetTouchVec().x - mVec.x) / mpScene->GetDistance()) * mSpeedPower*dt;
	mVec.y = mVec.y + ((mpScene->GetTouchVec().y - mVec.y) / mpScene->GetDistance()) * mSpeedPower*dt;
	setPosition(mVec);

	mActorBullet->ReadyToFire(mVec);

	mActorBullet->Update(dt);
}

void CActor::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);
	

	mActorBullet->SetScene(tpScene);
}