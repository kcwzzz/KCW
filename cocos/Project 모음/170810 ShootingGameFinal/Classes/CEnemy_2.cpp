#include "CEnemy_2.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CEnemyBullet_1.h"
#include "CActorBullet.h"

USING_NS_CC;

void CEnemy_2::Create()
{
	mIsLife = true;
	mpUnitImage = Sprite::create("Enemy2.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mSpeedPower = 100.0f;
	mCharacterHP = 100.0f;
	mScore = 250;
	CEnemyBullet_1 *tpBullet = NULL;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tpBullet = NULL;
		tpBullet = new CEnemyBullet_1();
		tpBullet->Create();

		mEnemyBulletVec_1.push_back(tpBullet);
	}
}

void CEnemy_2::Build()
{
	if (true == mIsLife)
	{
		mpScene->addChild(mpUnitImage, 10);

		int ti = 0;
		for (ti = 0; ti < 10; ti++)
		{
			mEnemyBulletVec_1[ti]->Build();
		}
	}
}

void CEnemy_2::Update(float dt)
{
	if (true == mIsLife)
	{
		mVec.x = mVec.x - mSpeedPower*dt;
		mVec.y = mVec.y - mSpeedPower*dt;

		setPosition(mVec);
	}

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mEnemyBulletVec_1[ti]->BulletMove(dt);
		mEnemyBulletVec_1[ti]->BulletDestroy();
	}
}

void CEnemy_2::ReadyToFire(float dt)
{
	if (true == mIsLife)
	{
		if (false == mEnemyBulletVec_1[mCurBulletIndex]->GetIsLife())
		{
			mEnemyBulletVec_1[mCurBulletIndex]->ReadyToFire(mVec);

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
}

void CEnemy_2::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mEnemyBulletVec_1[ti]->SetScene(tpScene);
	}
}

void CEnemy_2::Destroy()
{

}

Rect CEnemy_2::BulletColisionBox()
{
	Rect tRect = mpUnitImage->getBoundingBox();

	return tRect;
}

bool CEnemy_2::IsColision()
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
				mpScene->SetScore(mScore);
				tResult = true;

				break;
			}
		}
	}

	return tResult;
}

void CEnemy_2::SetActorBulletVec(CActorBulletVec tBulletVec)
{
	mActorBulletVec = tBulletVec;
}

void CEnemy_2::doParticles()
{
	Texture2D *tpTexture = NULL;
	tpTexture = Director::getInstance()->getTextureCache()->addImage("Images/stars.png");

	ParticleSystem *tpParticleSys = NULL;

	tpParticleSys = NULL;
	tpParticleSys = ParticleSun::create();
	tpParticleSys->retain();

	tpParticleSys->setScale(2.0);
	tpParticleSys->setDuration(0.5);
	tpParticleSys->setPosition(mVec);

	mpScene->addChild(tpParticleSys);
}