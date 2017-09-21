#include "CActorBullet.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActor.h"

USING_NS_CC;

CActorBullet::CActorBullet()
{
	Clear();
}
CActorBullet:: ~CActorBullet()
{

}

void CActorBullet::Create()
{
	//Create

	mpUnitImage = Sprite::create("CloseNormal.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mSpeedPower = 300.0f;
}


void CActorBullet::Build()
{
	mpScene->addChild(mpUnitImage, 10);
}

void CActorBullet::Clear()
{
	mVec = Vec2(0, 0);
	mSpeedPower = 0;
	mpUnitImage = NULL;
	mpScene = NULL;
}

void CActorBullet::ReadyToFire(Vec2 tVec)
{
	if (false == mIsLife)
	{
		mVec = tVec;
		mIsLife = true;
	}

}

void CActorBullet::Update(float dt)
{
	if (true == mIsLife)
	{
		mVec.x = mVec.x + mSpeedPower * 0 * dt;
		mVec.y = mVec.y + mSpeedPower*(+1)*dt;
		setPosition(mVec);

		if (800 < mVec.y)
		{
			mIsLife = false;
		}
	}
}