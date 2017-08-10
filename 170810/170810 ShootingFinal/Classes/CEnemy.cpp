#include "CEnemy.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CEnemyBullet.h"
#include "CActorBullet.h"

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
	mIsLife = true;
	mpUnitImage = Sprite::create("Enemy.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mScore = 100;
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
	if(true == mIsLife)
	{
	mpScene->addChild(mpUnitImage, 10);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mEnemyBulletVec[ti]->Build();
	}
	}
}


void CEnemy::Update(float dt)
{
	if (true == mIsLife)
	{
		mVec.x = mVec.x + mSpeedPower*dt;

		setPosition(mVec);
	}

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mEnemyBulletVec[ti]->BulletMove(dt);
		//mEnemyBulletVec[ti]->BulletMove_1(dt);
		mEnemyBulletVec[ti]->BulletDestroy();
	}
	
}

void CEnemy::ReadyToFire(float dt)
{
	if (true == mIsLife)
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

	//setPosition(mVec);

}

Rect CEnemy::BulletColisionBox()
{
	Rect tRect = mpUnitImage->getBoundingBox();

	return tRect;
}

bool CEnemy::IsColision()
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

void CEnemy::SetActorBulletVec(CActorBulletVec tBulletVec)
{
	mActorBulletVec = tBulletVec;
}

void CEnemy::doParticles()
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

CEnemyBulletVec CEnemy::GetEnemyBullets()
{
	return mEnemyBulletVec;
}