#include "cocos2d.h"
#include "CActor.h"
#include "Define.h"
#include "HelloWorldScene.h"
#include "CActorAniBox.h"


void CActor::Create()
{
	mpActorAniBox = new CActorAniBox();
	mpActorAniBox->SetScene(mpScene);
	mpActorAniBox->CreateAniBox("Hero_1.png", Vec2(200, 100), 64, 64, 0.3f);
}

void CActor::SetSecne(Node *tpScene)
{
	mpScene = tpScene;
}


void CActor::FSM_Selector()
{

	switch (mState)
	{
	case Idle:			//mstate 가 0
	{
		mpActorAniBox->StopAnimation();
	}
	break;

	case Move:			//mstate 가 1
	{
		Dir_Selector();
	}
	break;

	}

}

void CActor::Dir_Selector()
{
	//계속 반복하는 것은 제어가 필요함.
	if (Idle != mState)
	{
		switch (mDir)
		{
		case Up_Dir:
		{
			mpActorAniBox->RunAniUp();
		}
		break;

		case Down_Dir:
		{

			mpActorAniBox->RunAniDown();
		}
		break;

		case Left_Dir:
		{

			mpActorAniBox->RunAniLeft();
		}
		break;

		case Right_Dir:
		{

			mpActorAniBox->RunAniRight();
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
