#include "CEnemyBullet_1.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActor.h"
#include "CEnemy.h"

USING_NS_CC;

CEnemyBullet_1::CEnemyBullet_1()
{
	Clear();
}
CEnemyBullet_1:: ~CEnemyBullet_1()
{

}

void CEnemyBullet_1::Create()
{
	mIsLife = true;
	mpUnitImage = Sprite::create("EnemyBullet2.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mSpeedPower = 4.0f;
	mDamage = 100.0f;
}

void CEnemyBullet_1::BulletMove(float dt)
{
	mVec.x = mVec.x - mSpeedPower *2 ;
	mVec.y = mVec.y - mSpeedPower *2;
	setPosition(mVec);

}

void CEnemyBullet_1::BulletDestroy()
{
	if (mVec.y < 0)
	{
		mIsLife = false;
		mpScene->removeChild(mpUnitImage, 10);
		setPosition(mVec);
	}
}

