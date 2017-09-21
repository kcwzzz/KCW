#include "CActor.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActorBullet.h"
#include "CEnemyBullet.h"

USING_NS_CC;

CActor::CActor()
{
	Clear();
}

CActor::~CActor()
{

}


void CActor::Clear()
{
	mVec = Vec2(0, 0);
	mSpeedPower = 0;
	mpUnitImage = NULL;
	mpScene = NULL;
}

void CActor::Create()
{
	//Create
	mIsLife = true;
	mpUnitImage = Sprite::create("actor.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mSpeedPower = 600.0f;

	CActorBullet *tpBullet = NULL;

	int ti = 0;

	for (ti = 0; ti < 10; ti++)
	{
		tpBullet = NULL;
		tpBullet = new CActorBullet();
		tpBullet->Create();

		mActorBulletVec.push_back(tpBullet);
	}
}

void CActor::Build()
{
	if (true == mIsLife)
	{
		mpScene->addChild(mpUnitImage, 10);

		int ti = 0;
		for (ti = 0; ti < 10; ti++)
		{
			mActorBulletVec[ti]->Build();
		}
	}
}


void CActor::Update(float dt)
{
	if (true == mIsLife)
	{
		if (mVec.x < 0 || mVec.x >480 || mVec.y < 0 || mVec.y >720)
		{
			mVec.x = mpScene->GetTouchVec().x;
			mVec.y = mpScene->GetTouchVec().y;
		}
		else
		{
			mVec.x = mVec.x + ((mpScene->GetTouchVec().x - mVec.x) / mpScene->GetDistance()) * mSpeedPower*dt;
			mVec.y = mVec.y + ((mpScene->GetTouchVec().y - mVec.y) / mpScene->GetDistance()) * mSpeedPower*dt;
		}

		setPosition(mVec);

	}
	
		int ti = 0;
		for (ti = 0; ti < 10; ti++)
		{
			mActorBulletVec[ti]->BulletMove(dt);
			mActorBulletVec[ti]->BulletDestroy();
		}
	
}

void CActor::ReadyToFire(float dt)
{
	if (true == mIsLife)
	{
		if (false == mActorBulletVec[mCurBulletIndex]->GetIsLife())
		{
			mActorBulletVec[mCurBulletIndex]->ReadyToFire(mVec);

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

void CActor::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		mActorBulletVec[ti]->SetScene(tpScene);
	}
}

void CActor::Destroy()
{
	mpScene->removeChild(mpUnitImage, 10);
}

void CActor::BulletColision()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		//mActorBulletVec[ti]->IsColision();
	}
}

Rect CActor::BulletColisionBox()
{
	Rect tRect = mpUnitImage->getBoundingBox();

	return tRect;
}

Rect CActor::ActorColisionBox()
{
	Rect tRect = mpUnitImage->getBoundingBox();

	return tRect;
}


CActorBulletVec CActor::GetActorBullets()
{
	return mActorBulletVec;
}




bool CActor::IsColision()
{
	bool tResult = false;

	if (true == mIsLife)
	{
		CEnemyBullet *tEnemyBullet = NULL;


		int ti = 0;
		int tCount = mEnemyBulletVec.size();

		for (ti = 0; ti < tCount; ti++)
		{
			tEnemyBullet = NULL;
			tEnemyBullet = mEnemyBulletVec[ti];

			Rect tRectA = tEnemyBullet->BulletColisionBox();
			Rect tRectB = this->ActorColisionBox();

			if (true == tRectA.intersectsRect(tRectB))
			{
				mpScene->removeChild(mpUnitImage, 10);

				setPosition(mVec);

				mIsLife = false;

				this->doParticles();

				tResult = true;
				mpScene->GameOver();
				break;
			}

		}
	}

	return tResult;
}

void CActor::SetEnemyBulletVec(CEnemyBulletVec tBulletVec)
{
	mEnemyBulletVec = tBulletVec;
}

void CActor::doParticles()
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

