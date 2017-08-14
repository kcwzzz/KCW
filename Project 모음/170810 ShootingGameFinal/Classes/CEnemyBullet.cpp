#include "CEnemyBullet.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActor.h"
#include "CEnemy.h"

USING_NS_CC;

CEnemyBullet::CEnemyBullet()
{
	Clear();
}
CEnemyBullet:: ~CEnemyBullet()
{

}

void CEnemyBullet::Create()
{
	mpUnitImage = Sprite::create("EnemyBullet1.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mSpeedPower = 3.0f;
	mDamage = 100.0f;
}

void CEnemyBullet::BulletMove(float dt)
{
	mVec.x = mVec.x;
	mVec.y = mVec.y - mSpeedPower;
	setPosition(mVec);
}

/*
void CEnemyBullet::BulletMove_1(float dt)
{
	mVec_1.x = mVec_1.x - mSpeedPower;
	mVec_1.y = mVec_1.y - mSpeedPower;
	setPosition(mVec_1);
}
*/

void CEnemyBullet::BulletDestroy()
{
	if (mVec.y < 0)
	{
		mIsLife = false;
		mpScene->removeChild(mpUnitImage, 10);
		setPosition(mVec);
	}
}

