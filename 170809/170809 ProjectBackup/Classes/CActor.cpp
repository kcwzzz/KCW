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

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mActorBulletVec[ti]->Build();
	}
}


void CActor::Update(float dt)
{
	if(mpScene->GetDistance() > 0.1)
	{
		mVec.x = mVec.x + ((mpScene->GetTouchVec().x - mVec.x) / mpScene->GetDistance()) * mSpeedPower*dt;
		mVec.y = mVec.y + ((mpScene->GetTouchVec().y - mVec.y) / mpScene->GetDistance()) * mSpeedPower*dt;
	}
	else
	{
		mVec.x = mVec.x + ((mpScene->GetTouchVec().x - mVec.x) /0.1) * mSpeedPower*dt;
		mVec.y = mVec.y + ((mpScene->GetTouchVec().y - mVec.y) / 0.1) * mSpeedPower*dt;
	}

	setPosition(mVec);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{		
		mActorBulletVec[ti]->BulletMove(dt);
		mActorBulletVec[ti]->BulletDestroy();
	}	
}

void CActor::ReadyToFire(float dt)
{
	if (false == mActorBulletVec[mCurBulletIndex]->GetIsLife())
	{
		mActorBulletVec[mCurBulletIndex]->ReadyToFire(mVec);

		if (mCurBulletIndex < 9 )
		{
			mCurBulletIndex++;
		}
		else
		{
			mCurBulletIndex = 0;
		}
	}
}

void CActor::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mActorBulletVec[ti]->SetScene(tpScene);
	}
}

void CActor::Destroy()
{

}