#include "CBullet.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActor.h"
#include "CEnemy.h"

USING_NS_CC;

CBullet::CBullet()
{
	Clear();
}

CBullet::~CBullet()
{

}


void CBullet::ReadyToFire(Vec2 tVec)
{
	mVec = tVec;
	mIsLife = true;
	mpScene->addChild(mpUnitImage, 10);
}


void CBullet::BulletMove(float dt)
{
	mVec.x = mVec.x;
	mVec.y = mVec.y + mSpeedPower;
	setPosition(mVec);
}

void CBullet::BulletDestroy()
{

}

bool CBullet::GetIsLife()
{
	return mIsLife;
}

