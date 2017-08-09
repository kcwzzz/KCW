#include "CEnemy.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CEnemyBullet.h"

USING_NS_CC;


CEnemy::CEnemy()
{
	Clear();
}

CEnemy::~CEnemy()
{

}

void CEnemy::Create()
{
	mpUnitImage = Sprite::create("coin.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mSpeedPower = 100.0f;
	mCharacterHP = 100.0f;

	CEnemyBullet *tpBullet = NULL;

	int ti = 0;

	for (ti = 0; ti < 10; ti++)
	{
		tpBullet = NULL;
		tpBullet = new CEnemyBullet();
		tpBullet->Create();

		mEnemyBulletVec.push_back(tpBullet);
	}
}

void CEnemy::Build()
{
	mpScene->addChild(mpUnitImage, 10);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mEnemyBulletVec[ti]->Build();
	}
}


void CEnemy::Update(float dt)
{
	mVec.x = mVec.x + mSpeedPower*dt;
	
	setPosition(mVec);


	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mEnemyBulletVec[ti]->BulletMove(dt);
		mEnemyBulletVec[ti]->BulletDestroy();
	}
}

void CEnemy::ReadyToFire(float dt)
{
	if (false == mEnemyBulletVec[mCurBulletIndex]->GetIsLife())
	{
		mEnemyBulletVec[mCurBulletIndex]->ReadyToFire(mVec);

		if (mCurBulletIndex < 9)
		{
			mCurBulletIndex++;
		}
		else
		{
			mCurBulletIndex = 0;
		}
	}
}

void CEnemy::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mEnemyBulletVec[ti]->SetScene(tpScene);
	}
}

void CEnemy::Destroy()
{

	mpScene->removeChild(mpUnitImage, 10);
}