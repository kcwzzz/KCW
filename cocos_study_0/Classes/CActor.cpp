#include "CActor.h"
#include "cocos2d.h"
#include "GameScene.h"
#include "CVirtualPad.h"
#include "CBackgroundLayer.h"
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
	mpActorAniBox->CreateAniBox("Hero_1.png", Vec2(0, 0), 64, 64, 0.1f);

	mpObjectAniBox = new CObjectAniBox();
	mpObjectAniBox->SetScene(mpScene);
	mpObjectAniBox->CreateAniBox("Attack.png", Vec2(0, 0), 153, 153, 0.05f, 5);

	mSpeed = 10.0f;
}

void CActor::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}

void CActor::FSM_Selector()
{
	


	/*
	mState = mpVirtualPad->GetActorFSM();

	if (mCurState == mState)
	{

	}
	else
	{

		switch (mState)
		{
		case IDLE:			//mstate 가 0
		{
			IdleState();
		}
		break;

		case MOVE:			//mstate 가 1
		{
			MoveState();
		}
		break;

		case ATTACK:
		{
			AttackState();
		}
		break;

		case DEAD:
		{
			DeadState();
		}
		}
	}
	*/
	
}

void CActor::IdleState()
{
	mpActorAniBox->Show();
	mpActorAniBox->StopMoveAnimation();
	log("Idle");
	mCurState = IDLE;
}

void CActor::MoveState()
{
	log("Move");
	mCurState = MOVE;
}

void CActor::AttackState()
{
	Vec2 tVec = Vec2(0, 0);
	mpObjectAniBox->Show();

	switch (mDir)
	{
	case Up_Dir:
	{
		tVec.x = mVec.x;
		tVec.y = mVec.y + 64;
		mpObjectAniBox->Rotation(-90);
	}
	break;

	case Down_Dir:
	{
		tVec.x = mVec.x;
		tVec.y = mVec.y - 64;
		mpObjectAniBox->Rotation(90);
	}
	break;

	case Left_Dir:
	{
		tVec.x = mVec.x - 64;
		tVec.y = mVec.y;
		mpObjectAniBox->Rotation(180);
	}
	break;

	case Right_Dir:
	{
		tVec.x = mVec.x + 64;
		tVec.y = mVec.y;
		mpObjectAniBox->Rotation(0);
	}
	break;

	}

	mpObjectAniBox->SetPosition(tVec);
	//ryu
	//mpObjectAniBox->RunAniObject();
	//mpObjectAniBox->RunAniWithCallback();
	mpObjectAniBox->RunAniWithCallback(
		CallFunc::create(CC_CALLBACK_0(CActor::OnCompleteAni, this))
	);

	log("Attack");
	mCurState = ATTACK;
}




void CActor::OnCompleteAni()
{	
	//SetState
	mCurState = IDLE;


	//DoitWithState
	mpObjectAniBox->Hide();
	
}




void CActor::AttackEndState()
{
	mpObjectAniBox->Hide();
	mpObjectAniBox->StopAnimation();
	log("Attack");
	mCurState = IDLE;
}

void CActor::DeadState()
{

	mpActorAniBox->StopMoveAnimation();
	mpActorAniBox->Hide();
	log("Dead");
	mCurState = DEAD;
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
	mpScene->runAction(Follow::create(mpActorAniBox->GetSprite(), Rect(0, 0, Map_Width, Map_Height)));
}

int CActor::GetDir()
{
	return mDir;
}