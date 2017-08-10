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
	mpUnitImage = Sprite::create("CloseSelected.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mSpeedPower = 5.0f;
	mDamage = 100.0f;
}



void CEnemyBullet_1::BulletMove(float dt)
{
	mVec_0.x = mVec_0.x - mSpeedPower *2 ;
	mVec_0.y = mVec_0.y - mSpeedPower;
	setPosition(mVec_0);

	mVec_1.x = mVec_1.x - mSpeedPower;
	mVec_1.y = mVec_1.y - mSpeedPower;
	setPosition(mVec_1);

	mVec_2.x = mVec_2.x;
	mVec_2.y = mVec_2.y - mSpeedPower;
	setPosition(mVec_2);
	
	mVec_3.x = mVec_3.x + mSpeedPower;
	mVec_3.y = mVec_3.y - mSpeedPower;
	setPosition(mVec_3);

	mVec_4.x = mVec_4.x + mSpeedPower * 2;
	mVec_4.y = mVec_4.y - mSpeedPower;
	setPosition(mVec_4);
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

