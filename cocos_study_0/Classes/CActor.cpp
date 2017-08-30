#include "CActor.h"
#include "cocos2d.h"
#include "GameScene.h"
#include "CVirtualPad.h"
#include "CBackgroundLayer.h"
#include "CActorAniBox.h"
#include "CObjectAniBox.h"
#include "CGuageHP.h"


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
	mLevel = 1;
	mEXP = 0;
	mMaxHP = 100;
	mCurHP = mMaxHP;
	mAP = 10;
	mDefence = 5;
	mSpeed = 10;
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

	mpColisionBox = Sprite::create("coin.png");
	mpColisionBox->retain();
	mpColisionBox->setPosition(mVec);

}

void CActor::ActorHPGauge(Node *tpNode)
{
	mpGuageHP = new CGuageHP();
	mpGuageHP->Create(mCurHP, mMaxHP);
	mpGuageHP->SetScene(tpNode);
	mpGuageHP->SetPosition(Vec2(50, 730));
	mpGuageHP->AddToScene();

}

void CActor::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}

void CActor::FSM_Selector()
{

}

void CActor::IdleState()
{
	mpObjectAniBox->Hide();
	mpActorAniBox->Show();
	mpActorAniBox->StopMoveAnimation();
	mCurState = IDLE;
}

void CActor::MoveState()
{
	mCurState = MOVE;
	Dir_Selector();
}

void CActor::AttackState()
{
	mpObjectAniBox->Show();

	/*
		Vec2 tVec = Vec2(0, 0);

		switch (mDir)
		{
		case Up_Dir:
		{
		tVec.x = mVec.x;
		tVec.y = mVec.y + 64;
		mpObjectAniBox->setRotation(-90);
		}
		break;

		case Down_Dir:
		{
			tVec.x = mVec.x;
			tVec.y = mVec.y - 64;
			mpObjectAniBox->setRotation(90);
		}
		break;

		case Left_Dir:
		{
			tVec.x = mVec.x - 64;
			tVec.y = mVec.y;
			mpObjectAniBox->setRotation(180);
		}
		break;

		case Right_Dir:
		{
			tVec.x = mVec.x + 64;
			tVec.y = mVec.y;
			mpObjectAniBox->setRotation(0);
		}
		break;

		}
		*/

	mpObjectAniBox->RunAniWithCallback(
		CallFunc::create(CC_CALLBACK_0(CActor::IdleState, this))
	);

	mCurState = ATTACK;
}

void CActor::AttackEndState()
{
	mpObjectAniBox->Hide();
	mpObjectAniBox->StopAnimation();
	mCurState = IDLE;
}

void CActor::DeadState()
{
	mpActorAniBox->StopMoveAnimation();
	mpActorAniBox->Hide();
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
			mpObjectAniBox->setRotation(-90);
			mpColisionBox->setRotation(-90);

			mCurDir = 0;
		}
		break;

		case Down_Dir:
		{
			mpActorAniBox->RunMoveAniDown();
			mpObjectAniBox->setRotation(90);
			mpColisionBox->setRotation(90);

			mCurDir = 1;
		}
		break;

		case Left_Dir:
		{
			mpActorAniBox->RunMoveAniLeft();
			mpObjectAniBox->setRotation(180);
			mpColisionBox->setRotation(-180);

			mCurDir = 2;
		}
		break;

		case Right_Dir:
		{
			mpActorAniBox->RunMoveAniRight();
			mpObjectAniBox->setRotation(0);
			mpColisionBox->setRotation(0);

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
	mpScene->addChild(mpColisionBox, 5);
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
	this->FollowObject();

	/*
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
	*/
	
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
	mpColisionBox->setPosition(mAttackVec);
	mpObjectAniBox->SetPosition(mAttackVec);

}

void CActor::FollowObject()
{
	switch (mDir)
	{
	case Up_Dir:
	{
		mAttackVec.x = mVec.x;
		mAttackVec.y = mVec.y + 64;

	}
	break;

	case Down_Dir:
	{
		mAttackVec.x = mVec.x;
		mAttackVec.y = mVec.y - 64;
	}
	break;

	case Left_Dir:
	{
		mAttackVec.x = mVec.x - 64;
		mAttackVec.y = mVec.y;
	}
	break;

	case Right_Dir:
	{
		mAttackVec.x = mVec.x + 64;
		mAttackVec.y = mVec.y;
	}
	break;

	}
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

float CActor::GetMaxHP()
{
	return mMaxHP;
}

float CActor::GetCurHP()
{
	return mCurHP;
}

void CActor::SetDamaged(int tint)
{
	mCurHP = mCurHP - tint;
	mpGuageHP->BuildGuageWithDamage(tint);
}