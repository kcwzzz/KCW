#include "CActor.h"
#include "cocos2d.h"
#include "GameScene.h"
#include "CVirtualPad.h"
#include "CBackgroundLayer.h"
#include "CActorAniBox.h"
#include "CObjectAniBox.h"
#include "CGuageHP.h"
#include "CSound.h"
#include "DataDriven.h"
#include "CActorInfoList.h"
#include "CActorStatus.h"
#include "FSM_Manager.h"
#include "Define.h"
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
	CActorInfoList *tpInfo = NULL;
	tpInfo = DataDriven::GetInstance()->GetCurActorInfo();

	mImageSpriteFile = tpInfo->mImageFileName;
	mAttImageFileName = tpInfo->mAttImageFileName;

	if (NULL != tpInfo)
	{
		int tCount = 0;
		tCount = tpInfo->mActorStatusVec.size();

		for (int ti = 0; ti < tCount; ti++)
		{
			mState = 0;
			mDefence = 5;
			mVec = Vec2(0, 0);

			mLevel = tpInfo->mActorStatusVec[ti]->mLevel;
			mEXP = tpInfo->mActorStatusVec[ti]->mExp;
			mMaxHP = tpInfo->mActorStatusVec[ti]->mMaxHP;
			mAP = tpInfo->mActorStatusVec[ti]->mAP;
			mSpeed = tpInfo->mActorStatusVec[ti]->mSpeed;;
			mSpeedRatio = tpInfo->mActorStatusVec[ti]->mSpeedRatio;

			mCurHP = mMaxHP;
		}
	}
}
//생성

void CActor::Create()
{
	mpActorAniBox = new CActorAniBox();
	mpActorAniBox->SetScene(mpScene);
	mpActorAniBox->CreateAniBox(mImageSpriteFile, Vec2(0, 0), 64, 64, 0.1f);

	mpObjectAniBox = new CObjectAniBox();
	mpObjectAniBox->SetScene(mpScene);
	mpObjectAniBox->CreateAniBox(mAttImageFileName, Vec2(0, 0), 153, 153, 0.05f, 5);
	mpAttSprite = mpObjectAniBox->GetSprite();

	mpColisionBox = Sprite::create("Coin_1.png");
	mpColisionBox->retain();
	mpColisionBox->setPosition(mColVec);
	mpColisionBox->setVisible(0);

	mpBGLayer = new CBackgroundLayer();
	mpBGLayer->Create();
	mpBGLayer->retain();

	CGuageHP::Getinstance()->Create(mCurHP, mMaxHP);
	CGuageHP::Getinstance()->PrintScore();
	CGuageHP::Getinstance()->SetPosition(Vec2(50, 730));
	CGuageHP::Getinstance()->AddToScene();
}

void CActor::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}

void CActor::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpActorAniBox->GetSprite()->setPosition(mVec);
}

void CActor::Build()
{
	mpActorAniBox->Build();
	mpObjectAniBox->Build();
	mpScene->addChild(mpColisionBox, 5);
}
// 생성

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
			//mpColisionBox->setRotation(-90);

			mCurDir = 0;
		}
		break;

		case Down_Dir:
		{
			mpActorAniBox->RunMoveAniDown();
			mpObjectAniBox->setRotation(90);
			//mpColisionBox->setRotation(90);

			mCurDir = 1;
		}
		break;

		case Left_Dir:
		{
			mpActorAniBox->RunMoveAniLeft();
			mpObjectAniBox->setRotation(180);
			//mpColisionBox->setRotation(-180);

			mCurDir = 2;
		}
		break;

		case Right_Dir:
		{
			mpActorAniBox->RunMoveAniRight();
			mpObjectAniBox->setRotation(0);
			//mpColisionBox->setRotation(0);

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

Sprite* CActor::GetSprite()
{
	return mpActorAniBox->GetSprite();
}

void CActor::MoveActor()
{
	this->CalcDir();
	this->FollowObject();

	int tValueX = 0;
	int tValueY = 0;

	setPosition(mVec);
	mpColisionBox->setPosition(mColVec);
	mpObjectAniBox->SetPosition(mAttVec);

	if (mVec.x > 0 && mVec.x < Map_Width)
	{
		if (1 == ColisionGeometry() || 2 == ColisionGeometry())
		{
			tValueX = 0;
		}
		else
		{
			tValueX = 1;
		}
		mVec.x = mVec.x + mDirX * mSpeed * IncreaseSpeed()*tValueX;// *dt;
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
		if (1 == ColisionGeometry() || 2 == ColisionGeometry())
		{
			tValueY = 0;

		}
		else
		{

			tValueY = 1;

		}

		mVec.y = mVec.y + mDirY * mSpeed * IncreaseSpeed()*tValueY;// *dt;
	}

	else if (mVec.y <= 0)
	{
		mVec.y = 1;
	}

	else
	{
		mVec.y = Map_Height - 1;
	}
}

void CActor::FollowObject()
{
	switch (mDir)
	{
	case Up_Dir:
	{
		mAttVec.x = mVec.x;
		mAttVec.y = mVec.y + 64;
		mColVec.x = mVec.x;
		mColVec.y = mVec.y + 32;
	}
	break;

	case Down_Dir:
	{
		mAttVec.x = mVec.x;
		mAttVec.y = mVec.y - 64;
		mColVec.x = mVec.x;
		mColVec.y = mVec.y - 32;

	}
	break;

	case Left_Dir:
	{
		mAttVec.x = mVec.x - 64;
		mAttVec.y = mVec.y;
		mColVec.x = mVec.x - 32;
		mColVec.y = mVec.y;
	}
	break;

	case Right_Dir:
	{
		mAttVec.x = mVec.x + 64;
		mAttVec.y = mVec.y;
		mColVec.x = mVec.x + 32;
		mColVec.y = mVec.y;
	}
	break;
	}
}

float CActor::IncreaseSpeed()
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

void CActor::SetVirtualPad(CVirtualPad *tpVirtualPad)
{
	mpVirtualPad = tpVirtualPad;
}

void CActor::FollowActor()
{
	mpScene->runAction(Follow::create(mpActorAniBox->GetSprite(), Rect(0, 0, Map_Width, Map_Height)));
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
	CGuageHP::Getinstance()->SetCurHP(mCurHP);
	CGuageHP::Getinstance()->BuildGuageWithDamage(tint);
	//mpGuageHP->BuildGuageWithDamage(tint);
}

int CActor::ColisionGeometry()
{
	//충돌 관련해서는 세부 좌표를 맞출 필요가 있어보인다.
	//정확한 이유는 찍히는 위치와 타일이나 이런게 올림, 내림 판정 문제일듯
	mpTiledMap = mpBGLayer->GetTileMap();

	float tTileW = mpTiledMap->getTileSize().width;
	float tTileH = mpTiledMap->getTileSize().height;

	float tTotalRowCount = mpTiledMap->getMapSize().height;

	int tCol = mpColisionBox->getPosition().x / tTileW;
	int tRow = tTotalRowCount - mpColisionBox->getPosition().y / tTileH;

	int tWidth = 64 / tTileW;
	int tHeight = 64 / tTileH;

	int tResult = mpBGLayer->GetAttributeWith(tRow, tCol, tWidth, tHeight);

	return tResult;
}

// FSM 상태 모음

void CActor::FSM_Selector()
{
	int tState = FSM_Manager::Getinstance()->GetNowState();

	if (tState !=mCurState)
	{
		switch (tState)
		{
		case IDLE:
		{
			IdleState();
		}
		break;
		
		case MOVE:
		{
			MoveState();
		}
		break;
		
		case ATTACK:
		{
			AttackState();
		}
		break;
		
		case DAMAGED:
		{
			DamagedState();
		}
		break;

		case DEAD:
		{
			DeadState();
		}
		break;
		}
	}
}

void CActor::IdleState()
{
	auto action = Sequence::create(
		CallFunc ::create(CC_CALLBACK_0(CActor ::IdleStateStart,this)),
		CallFunc::create(CC_CALLBACK_0(CActor::IdleStateExcute, this)),
		CallFunc::create(CC_CALLBACK_0(CActor::IdleStateEnd, this)), NULL);

	mpScene->runAction(action);
}	

void CActor::IdleStateStart()
{
	mpObjectAniBox->Hide();
	mpObjectAniBox->StopAnimation();
	mpActorAniBox->Show();	
	mpActorAniBox->StopMoveAnimation();
	log("idle start");
}

void CActor::IdleStateExcute()
{
	log("idle Excute");

}
void CActor::IdleStateEnd()
{
	log("idle End");
	mCurState = IDLE;
}

void CActor::MoveState()
{
	auto action = Sequence::create(
		CallFunc::create(CC_CALLBACK_0(CActor::MoveStateStart, this)),
		CallFunc::create(CC_CALLBACK_0(CActor::MoveStateExcute, this)),
		CallFunc::create(CC_CALLBACK_0(CActor::MoveStateEnd, this)), NULL);

	mpScene->runAction(action);
}

void CActor::MoveStateStart()
{

}

void CActor::MoveStateExcute()
{
	this->Dir_Selector();
	log("move");
}


void CActor::MoveStateEnd()
{
	mCurState = MOVE;
}

void CActor::AttackState()
{
	auto action = Sequence::create(
		CallFunc::create(CC_CALLBACK_0(CActor::AttackStateStart, this)),
		CallFunc::create(CC_CALLBACK_0(CActor::AttackStateExcute, this)),
		CallFunc::create(CC_CALLBACK_0(CActor::AttackStateEnd, this)), NULL);

	mpScene->runAction(action);
}

void CActor::AttackStateStart()
{
	mpObjectAniBox->Show();
}

void CActor::AttackStateExcute()
{
	mpObjectAniBox->RunAniObject();
	CSound::Getinstance()->PlayEffect(0);
	log("attack");
}

void CActor::AttackStateEnd()
{
	mpObjectAniBox->StopAnimation();
	mCurState = ATTACK;	
	mpObjectAniBox->RunAniWithCallback(
		CallFunc::create(CC_CALLBACK_0(CActor ::ChangeIdleState, this))
	);
}

void CActor::ChangeIdleState()
{
	FSM_Manager::Getinstance()->SetNowState(IDLE);
}

void CActor::DeadState()
{
	mpActorAniBox->StopMoveAnimation();
	mpActorAniBox->Hide();
	mCurState = DEAD;
}

void CActor::DamagedState()
{
	FSM_Manager::Getinstance()->SetNowState(IDLE);
	mpActorAniBox->ChangeColorDamaged();
	//색이 변하도록
}

int CActor::GetmDir()
{
	return mDir;
}

Sprite* CActor::GetAttackSprite()
{
	return mpAttSprite;
}

int CActor::GetAP()
{
	return mAP;
}

Vec2 CActor::GetVec()
{
	return mVec;
}