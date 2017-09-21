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
	 mVec = Vec2(0, 0);
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
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpSprite->setPosition(mVec);
}

Vec2 CActor::GetVec()
{
	return mVec;
}

Sprite* CActor::GetSprite()
{
	return mpSprite;
}
void CActor::SetVec(Vec2 tVec)
{
	mVec = tVec;
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
	Vec2 tVec = mpScene->GetTouchPosition();
	float tDistance = mpScene->GetDistance();

//	this->GetDistance();
	
	if (((tVec.x - mVec.x) / tDistance) < 0.005 &&
		((tVec.x - mVec.x) / tDistance) > -0.005)
	{
		mDirX = 0;
	}
	else
	{
		mDirX = (tVec.x - mVec.x) / tDistance;
	}

	if (((tVec.y - mVec.y) / tDistance)< 0.005 && 
		((tVec.y - mVec.y) / tDistance) >-0.005)
	{
		mDirY = 0;
	}
	else
	{
		mDirY = (tVec.y - mVec.y) / tDistance;
	}
		
	mVec.x = mVec.x + mDirX * mSpeed;// *dt;
	mVec.y = mVec.y + mDirY * mSpeed;// *dt;

	setPosition(mVec);

	log("%f,%f,%f,%f,%f", mDirX, mDirY, mVec.x, mVec.y, tDistance);
}

float CActor::GetDirectionX()
{
	return mDirX;

}


float CActor::GetDirectionY()
{
	return mDirY;

}