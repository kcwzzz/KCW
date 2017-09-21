#include "CEnemy_1.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CEnemyBullet.h"

USING_NS_CC;


CEnemy_1::CEnemy_1()
{
	Clear();
}

CEnemy_1::~CEnemy_1()
{

}

void CEnemy_1::Create()

{
	mIsLife = true;
	mpUnitImage = Sprite::create("coin.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mSpeedPower = 300.0f;
	mCharacterHP = 100.0f;
}

void CEnemy_1::Build()
{
	if (true == mIsLife)
	{
		mpScene->addChild(mpUnitImage, 10);
	}
}


void CEnemy_1::Update(float dt)
{
	if (true == mIsLife)
	{
		mVec.y = mVec.y - mSpeedPower*dt;

		setPosition(mVec);
	}
}

void CEnemy_1::ReadyToFire(float dt)
{

}

void CEnemy_1::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);
}

void CEnemy_1::Destroy()
{
	mpScene->removeChild(mpUnitImage, 10);
}

bool CEnemy_1::GetIsLife()
{
	return mIsLife;
}


bool CEnemy_1::IsColision()
{

	bool tResult = false;

	if (true == mIsLife)
	{
		CActorBullet *tActorBullet = NULL;


		int ti = 0;
		int tCount = mActorBulletVec.size();

		for (ti = 0; ti < tCount; ti++)
		{
			tActorBullet = NULL;
			tActorBullet = mActorBulletVec[ti];



			Rect tRectA = tActorBullet->BulletColisionBox();
			Rect tRectB = this->BulletColisionBox();

			if (true == tRectA.intersectsRect(tRectB))
			{
				mpScene->removeChild(mpUnitImage, 10);
				setPosition(mVec);
				mIsLife = false;
				this->doParticles();
				//this->Clear();

				tResult = true;

				break;
			}

		}
	}

	return tResult;
}

void CEnemy_1::SetActorBulletVec(CActorBulletVec tBulletVec)
{
	mActorBulletVec = tBulletVec;
}

Rect CEnemy_1::BulletColisionBox()
{
	Rect tRect = mpUnitImage->getBoundingBox();

	return tRect;
}