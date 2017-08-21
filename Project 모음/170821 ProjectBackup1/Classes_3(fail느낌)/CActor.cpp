#include "CActor.h"
#include "cocos2d.h"
#include "GameScene.h"
#include "CVirtualPad.h"
#include "CBackgroundLayer.h"
#include "Define.h"

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
	mSpeedRatio = 1.0f;
	mVec = Vec2(0, 0);
}

void CActor::create()
{
	mpSprite = Sprite::create("actor.png");
	mpSprite->retain();
	mSpeed = 5.0f;
}

void CActor::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}


void CActor::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpSprite->setPosition(mVec);
}

void CActor::CalcDir()
{
	if(true == mpVirtualPad->GetStateJoyStic())
	{
		mDirX = mpVirtualPad->GetVecResult().x / mpVirtualPad->GetResultDistance();
		mDirY = mpVirtualPad->GetVecResult().y / mpVirtualPad->GetResultDistance();
	}
	else
	{
		mDirX = 0;
		mDirY = 0;
	}
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

void CActor::MoveActor(float dt)
{
	this->CalcDir();

	if(mVec.x >0 && mVec.x <Map_Width)
	{
		mVec.x = mVec.x + mDirX * mSpeed * IncreaseSpeed(dt);// *dt;
	}
	else if (mVec.x <= 0)
	{
		mVec.x = 1;
	}
	else
	{
		mVec.x = Map_Width-1;
	}

	if (mVec.y >0 && mVec.y <Map_Height)
	{

		mVec.y = mVec.y + mDirY * mSpeed * IncreaseSpeed(dt);// *dt;
	}
	else if (mVec.y <= 0)
	{
		mVec.y = 1;
	}
	else
	{
		mVec.y = Map_Height-1;
	}
		
	//log("%f,%f", mDirX, mDirY);

	setPosition(mVec);	
}


float CActor:: IncreaseSpeed(float dt)
{
	while (true)
	{		
	
	mSpeedRatio = mSpeedRatio + 0.001;

	if (2 == mSpeedRatio)
	{
		break;
	}

	return mSpeedRatio;

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

void CActor::SetVirtualPad(CVirtualPad *tpVirtualPad)
{	
	mpVirtualPad = tpVirtualPad;
}

void CActor::FollowActor()
{
	mpScene->runAction(Follow::create(mpSprite, Rect(0, 0, Map_Width, Map_Height)));
}