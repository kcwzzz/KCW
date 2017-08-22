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

void CActor::CreateTexture()
{
	mpTexture = Director::getInstance()->getTextureCache()->addImage("Hero.png");
	mSpeed = 5.0f;
}

void CActor::CreateAnimation()
{
	mpAnimationDown = Animation::create();
	mpAnimationDown->setDelayPerUnit(0.3f);

	mpAnimationLt = Animation::create();
	mpAnimationLt->setDelayPerUnit(0.3f);

	mpAnimationUp = Animation::create();
	mpAnimationUp->setDelayPerUnit(0.3f);

	mpAnimationRt = Animation::create();
	mpAnimationRt->setDelayPerUnit(0.3f);

}

void CActor::CreateSprite()
{
	mpActor = Sprite::createWithTexture(mpTexture, Rect(0, 0, 32, 32));
	
	CreateAniMoveDown();
	CreateAniMoveUp();
	CreateAniMoveLeft();
	CreateAniMoveRight();
	
}

void CActor::CreateAniMoveDown()
{
	for (int i = 0; i < 3;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationDown->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}


	mpAnimateDown = Animate::create(mpAnimationDown);
	mpAnimateDown->retain();
}

void CActor::CreateAniMoveLeft()
{
	for (int i = 3; i < 6;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationLt->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}

	mpAnimateLt = Animate::create(mpAnimationLt);
	mpAnimateLt->retain();
}

void CActor::CreateAniMoveRight()
{
	for (int i = 6; i < 9;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationRt->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
	mpAnimateRt = Animate::create(mpAnimationRt);
	mpAnimateRt->retain();
}


void CActor::CreateAniMoveUp()
{
	for (int i = 9; i < 12;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationUp->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}

	mpAnimateUp = Animate::create(mpAnimationUp);
	mpAnimateUp->retain();

}


void CActor::RunAnimation()
{
	if (NULL != mpCurAnimate)
	{
		mpActor->stopAction(mpCurAnimate);
	}

	//0:up, 1: down, 2: left, 3: right
	switch (mDir)
	{
	case 0:
	{
		mpCurAnimate = mpAnimateUp;
		//mpCurAnimate = mpAnimateLt;

		log("RunAniamteion Up");
	}
	break;
	case 1:
	{
		mpCurAnimate = mpAnimateDown;
		//mpCurAnimate = mpAnimateLt;

		log("RunAniamteion Down");
	}
	break;
	case 2:
	{
		mpCurAnimate = mpAnimateLt;

		log("RunAniamteion Lt");
	}
	break;
	case 3:
	{
		mpCurAnimate = mpAnimateRt;
		//mpCurAnimate = mpAnimateLt;

		log("RunAniamteion Rt");
	}
	break;
	}
	mpActor->runAction(mpCurAnimate);
}

void CActor::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}


void CActor::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpActor->setPosition(mVec);
}

void CActor::CalcDir()
{
	if (true == mpVirtualPad->GetStateJoyStic())
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
	return mpActor;
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
	mpScene->addChild(mpActor, 10);
}

void CActor::MoveActor(float dt)
{
	this->CalcDir();

	if (mVec.x > 0 && mVec.x < Map_Width)
	{
		mVec.x = mVec.x + mDirX * mSpeed * IncreaseSpeed(dt);// *dt;
	}
	else if (mVec.x <= 0)
	{
		mVec.x = 1;
	}
	else
	{
		mVec.x = Map_Width - 1;
	}

	if (mVec.y > 0 && mVec.y < Map_Height)
	{

		mVec.y = mVec.y + mDirY * mSpeed * IncreaseSpeed(dt);// *dt;
	}
	else if (mVec.y <= 0)
	{
		mVec.y = 1;
	}
	else
	{
		mVec.y = Map_Height - 1;
	}
	setPosition(mVec);
}


float CActor::IncreaseSpeed(float dt)
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
	mpScene->runAction(Follow::create(mpActor, Rect(0, 0, Map_Width, Map_Height)));
}

void CActor::AnimationFSMSelector()
{
	this->CalcDir();

	if (mDirY >= 0 && mDirX < mDirY && mDirY > -mDirX)
	{
		if (0 != mDir)
		{
			this->RunAnimation();

			mDir = 0;
		}
	}

	else if (mDirY < 0 && mDirX > mDirY && mDirY < -mDirX)
	{
		if (1 != mDir)
		{
			this->RunAnimation();

			mDir = 1;
		}
	}

	else if (mDirX < 0 && mDirX < mDirY && mDirY < -mDirX)
	{
		if (2 != mDir)
		{
			this->RunAnimation();

			mDir = 2;
		}
	}

	else if (mDirX >= 0 && mDirX > mDirY && mDirY > -mDirX)
	{
		if (3 != mDir)
		{
			this->RunAnimation();

			mDir = 3;
		}
	}
}