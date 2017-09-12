#include "CEnemy.h"
#include "CActorAniBox.h"
#include "CObjectAniBox.h"

#include "cocos2d.h"
#include "GameScene.h"
#include "CBackgroundLayer.h"

void CEnemy::Clear()
{
	mState = 0;			//Actor ป๓ลย FSM
	mMaxHP = 100;
	mCurHP = mMaxHP;
	mAP = 10;
	mDefence = 5;
	mSpeed = 3;
	mSpeedRatio = 1.0f;
	mVec = Vec2(0, 0);
}

void CEnemy::Create()
{
	mpActorAniBox = new CActorAniBox();
	mpActorAniBox->SetScene(mpScene);
	mpActorAniBox->CreateAniBox("Evil.png", Vec2(0, 0), 64, 64, 0.1f);

	mpObjectAniBox = new CObjectAniBox();
	mpObjectAniBox->SetScene(mpScene);
	mpObjectAniBox->CreateAniBox("Attack.png", Vec2(0, 0), 153, 153, 0.05f, 5);
	mpAttSprite = mpObjectAniBox->GetSprite();

	mpColisionBox = Sprite::create("ColisionCheckBar.png");
	mpColisionBox->retain();
	mpColisionBox->setPosition(mColVec);	
}

void CEnemy::Dir_Selector()
{
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


void CEnemy::MovePatten(float f)
{
	mCountClock = mCountClock + 1;
	Dir_Selector();

	if (mCountClock < 100)
	{
		mDir = Right_Dir;
		mVec.x = mVec.x + 5;
		mVec.y = mVec.y;;
	}
	else if (mCountClock < 200)
	{
		mDir = Left_Dir;
		mVec.x = mVec.x - 5;
		mVec.y = mVec.y;;
	}
	else
	{
		mCountClock = 0;
	}

	setPosition(mVec);
}

Sprite* CEnemy::GetAttackSprite()
{
	return mpAttSprite;
}

void CEnemy::Build()
{
	mpActorAniBox->Build();
	mpObjectAniBox->Build();
	mpScene->addChild(mpColisionBox, 5);
}