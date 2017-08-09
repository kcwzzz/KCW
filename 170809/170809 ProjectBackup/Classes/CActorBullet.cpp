#include "CActorBullet.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActor.h"
#include "CEnemy.h"

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
	mSpeedPower = 5.0f;
	mDamage = 100.0f;
}


void CActorBullet::Build()
{
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
	mVec = tVec;
	mIsLife = true;
	mpScene->addChild(mpUnitImage, 10);
}

void CActorBullet::BulletMove(float dt)
{
//	if (true == mIsLife)
//	{
		mVec.x = mVec.x;
		mVec.y = mVec.y + mSpeedPower;
		setPosition(mVec);
//	}
}

void CActorBullet::BulletDestroy()
{
	if (mVec.y > 800)
	{
		mIsLife = false;
		mpScene->removeChild(mpUnitImage, 10);
		setPosition(mVec);
	}
}

bool CActorBullet::GetIsLife()
{
	return mIsLife;
}

bool CActorBullet::IsColision()
{
	bool tResult = false;
	
	Rect tBulletColisionBox = mpUnitImage->getBoundingBox();
	
	if (true == tBulletColisionBox.intersectsCircle(mVec, mpEnemy->ImageHalfRadius() ))
	{
		tResult = true;
	}

	return tResult;
}