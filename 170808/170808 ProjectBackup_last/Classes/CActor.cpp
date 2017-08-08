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


	//mActorBullet = new CActorBullet();	
	//mActorBullet->Create();



	CActorBullet *tpBullet = NULL;
	int ti = 0;

	for (ti = 0; ti < 10; ti++)
	{
		tpBullet = NULL;
		tpBullet = new CActorBullet();
		tpBullet->Create();

		mActorBulletVec.push_back(tpBullet);
	}
}

void CActor::Build()
{
	mpScene->addChild(mpUnitImage, 10);
	//mActorBullet->Build();

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mActorBulletVec[ti]->Build();
	}
}

void CActor::Update(float dt)
{
	mVec.x = mVec.x + ((mpScene->GetTouchVec().x - mVec.x) / mpScene->GetDistance()) * mSpeedPower*dt;
	mVec.y = mVec.y + ((mpScene->GetTouchVec().y - mVec.y) / mpScene->GetDistance()) * mSpeedPower*dt;
	setPosition(mVec);

	//mActorBullet->ReadyToFire(mVec);
	//mActorBullet->Update(dt);
	//mActorBulletVec.push_back(mActorBullet);


	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mActorBulletVec[ti]->ReadyToFire(mVec);
		mActorBulletVec[ti]->Update(dt);
	}

}

void CActor::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);

	//mActorBullet->SetScene(tpScene);


	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mActorBulletVec[ti]->SetScene(tpScene);
	}
}
