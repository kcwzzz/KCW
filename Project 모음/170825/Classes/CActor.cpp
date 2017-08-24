#include "CActor.h"
#include "cocos2d.h"
#include "GameScene.h"
#include "CVirtualPad.h"
#include "CBackgroundLayer.h"
#include "Define.h"
#include "CActorAniBox.h"
#include "CObjectAniBox.h"


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
	mState = 0;			//Actor 상태 FSM
	mLevel = 0;
	mEXP = 0;
	mHP = 0;
	mAP = 0;
	mDefence = 0;
	mSpeed = 0;
	mSpeedRatio = 1.0f;
	mVec = Vec2(0, 0);
}

void CActor::Create()
{
	mpActorAniBox = new CActorAniBox();
	mpActorAniBox->SetScene(mpScene);
	mpActorAniBox->CreateAniBox("Hero_1.png", Vec2(0, 0), 64, 64, 0.3f);

	mpObjectAniBox = new CObjectAniBox();
	mpObjectAniBox->SetScene(mpScene);
	mpObjectAniBox->CreateAniBox("Attack.png", Vec2(0, 0), 153, 153, 0.05f, 5);

	mSpeed = 5.0f;
}

void CActor::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}

void CActor::FSM_Selector()
{
	switch (mState)
	{
	case Idle:			//mstate 가 0
	{
		mpActorAniBox->Show();
		mpActorAniBox->StopMoveAnimation();
	}
	break;

	case Move:			//mstate 가 1
	{

	}
	break;

	case Attack:
	{
		mpObjectAniBox->Show();
		mpObjectAniBox->StopAnimation();
		//mpObjectAniBox->RunAniObject();
	}
	break;

	case Dead:
	{
		mpActorAniBox->StopMoveAnimation();
		mpActorAniBox->Hide();
	}
	}

}

void CActor::Dir_Selector()
{
	mDir = mpVirtualPad->GetDir();

	if (mCurDir == mDir)
	{

	}
	else
	{
		mpActorAniBox->StopMoveAnimation();

		switch (mDir)
		{
		case Up_Dir:
		{
			mpActorAniBox->RunMoveAniUp();
			mCurDir = 0;
		}
		break;

		case Down_Dir:
		{
			mpActorAniBox->RunMoveAniDown();
			mCurDir = 1;
		}
		break;

		case Left_Dir:
		{
			mpActorAniBox->RunMoveAniLeft();
			mCurDir = 2;
		}
		break;

		case Right_Dir:
		{
			mpActorAniBox->RunMoveAniRight();
			mCurDir = 3;
		}
		break;

		}
	}
}

void CActor::SetmDir(int tDir)
{
	mDir = tDir;
}

void CActor::SetFsm(int tFsm)
{
	mState = tFsm;
}


void CActor::AttackDirSelector()
{

	if (true == mpVirtualPad->GetAttackButton())
	{
		
		mpObjectAniBox->RunAniObject();

		mState = Attack;

		/*
		switch (mDir)
		{
		case Up_Dir:
		{

		}
		break;

		case Down_Dir:
		{
		}
		break;

		case Left_Dir:
		{
		}
		break;

		case Right_Dir:
		{
		}

		break;
		}
		*/
	}
}

void CActor::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpActorAniBox->GetSprite()->setPosition(mVec);
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

void CActor::Build()
{
	mpActorAniBox->Build();
	mpObjectAniBox->Build();
}

Vec2 CActor::GetVec()
{
	return mVec;
}

Sprite* CActor::GetSprite()
{

	return mpActorAniBox->GetSprite();
}

void CActor::SetVec(Vec2 tVec)
{
	mVec = tVec;
}

float CActor::GetSpeedPower()
{
	return mSpeed;
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
		//mSpeedRatio = mSpeedRatio + 0.001;
		mSpeedRatio;

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
	//mpScene->runAction(Follow::create(mpActor, Rect(0, 0, 1024, 768)));
	mpScene->runAction(Follow::create(mpActorAniBox->GetSprite(), Rect(0, 0, Map_Width, Map_Height)));
}