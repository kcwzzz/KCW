#include "CActor.h"
#include "cocos2d.h"
#include "GameScene.h"

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
	 mState = 0;			//Actor ป๓ลย FSM
	 mLevel = 0;

	 mEXP = 0;
	 mHP = 0;
	 mAP = 0;
	 mDefence = 0;
	 mSpeed = 0;
	 mVecX = 0;
	 mVecY = 0;
}

void CActor::Create()
{
	mpSprite = Sprite::create("actor.png");
	mpSprite->retain();
	mSpeed = 5.0f;
}

void CActor::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CActor::setPosition(Vec2 tVec)
{
	mVecX = tVec.x;
	mVecY = tVec.y;
	mpSprite->setPosition(Vec2(mVecX, mVecY));
}

int CActor::GetVecX()
{
	return mVecX;
}

int CActor::GetVecY()
{
	return mVecY;
}

Sprite* CActor::GetSprite()
{
	return mpSprite;
}
void CActor::SetVec(Vec2 tVec)
{
	mVecX = tVec.x;
	mVecY = tVec.y;

}

float CActor::GetSpeedPower()
{
	return mSpeed;
}
void CActor::Build()
{
	mpScene->addChild(mpSprite, 10);
}

float CActor::GetDistance()
{
	mDistance = mpScene->GetDistance();
	return mDistance;
}

void CActor::CalcDir()
{

}


void CActor::MoveActor(float dt)
{

	int tVecx = mpScene->GetTouchX();
	int tVecy = mpScene->GetTouchY();
	
	float tDistance = mpScene->GetDistance();

	mDirX = (tVecx - mVecX) / tDistance;
	mDirY = (tVecy - mVecY) / tDistance;
	
	mVecX = mVecX + mDirX * mSpeed;// *dt;
	mVecY = mVecY + mDirY * mSpeed;// *dt;

	setPosition(Vec2(mVecX,mVecY));

	log("%f,%f,%f,%f,%f", mDirX, mDirY, mVecX, mVecY, tDistance);

	if (mVecX == mpScene->GetTouchX())
	{
		mpScene->unscheduleUpdate();
	}
}

float CActor::GetDirectionX()
{
	return mDirX;

}


float CActor::GetDirectionY()
{
	return mDirY;

}