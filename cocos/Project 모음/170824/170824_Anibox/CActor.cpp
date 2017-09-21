#include "cocos2d.h"
#include "CActor.h"
#include "Define.h"
#include "HelloWorldScene.h"
#include "CActorAniBox.h"
#include "CObjectAniBox.h"


void CActor::Create()
{
	mpActorAniBox = new CActorAniBox();
	mpActorAniBox->SetScene(mpScene);
	mpActorAniBox->CreateAniBox("Hero_1.png", Vec2(200, 100), 64, 64, 0.3f);

	mpObjectAniBox = new CObjectAniBox();
	mpObjectAniBox->SetScene(mpScene);
	mpObjectAniBox->CreateAniBox("Attack.png", Vec2(200, 100), 153, 153, 0.05f, 5);
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
		mpObjectAniBox->RunAniObject();
		//mpObjectAniBox->Hide();
	}
	break;

	case Dead : 
	{
		mpActorAniBox->StopMoveAnimation();
		mpActorAniBox->Hide();
		
	}
	}

}

void CActor::Dir_Selector()
{
	//계속 반복하는 것은 제어가 필요함.

	mpActorAniBox->StopMoveAnimation();

	if (Idle != mState)
	{
		switch (mDir)
		{
		case Up_Dir:
		{
			mpActorAniBox->RunMoveAniUp();
		}
		break;

		case Down_Dir:
		{
			mpActorAniBox->RunMoveAniDown();
		}
		break;

		case Left_Dir:
		{

			mpActorAniBox->RunMoveAniLeft();
		}
		break;

		case Right_Dir:
		{

			mpActorAniBox->RunMoveAniRight();
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
