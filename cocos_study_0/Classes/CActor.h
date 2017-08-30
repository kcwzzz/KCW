#pragma once

#include "cocos2d.h"
#include "Define.h"

USING_NS_CC;

using namespace std;

class GameScene;
class CBackgroundLayer;
class CVirtualPad;

class CActorAniBox;
class CObjectAniBox;
class CGuageHP;

class CActor
{	
private :

protected:	

	//Actor Status
	int mLevel = 0;
	float mEXP = 0.0f;
	float mMaxHP = 0.0f;
	float mCurHP = 0.0f;
	float mAP = 0.0f;
	float mDefence = 0.0f;
	float mSpeed = 0.0f;
	float mSpeedRatio = 1.0f;
	
	Sprite *mpColisionBox = NULL;
	CActorAniBox *mpActorAniBox = NULL;
	CObjectAniBox *mpObjectAniBox = NULL;
	Node *mpScene = NULL;
	CGuageHP *mpGuageHP = NULL;
	CVirtualPad *mpVirtualPad = NULL;

	Vec2 mAttackVec;
	Vec2 mVec;

	int mState = IDLE;
	int mCurState = IDLE;

	int mDir = Up_Dir  ;		//0:up, 1: down, 2: left, 3: right
	int mCurDir = Up_Dir;

	
	float mDirX = 0.0f;
	float mDirY = 0.0f;

public:
	virtual void Clear();
	

	/////////////////AniBox 관련한 곳//////////////////
	void Create();
	void SetScene(Node *tpScene);

	void ActorHPGauge(Node *tpNode);

	void FSM_Selector();
	void Dir_Selector();
	void SetmDir(int tDir);
	void SetFsm(int tFsm);
	void SetDamaged(int tint);
	void FollowObject();

	virtual void SetVirtualPad(CVirtualPad *tpVirtualPad);
	///////////////////////////////////////////////////
	
	virtual void Build();

	virtual void CalcDir();
	void FollowActor();

	virtual void setPosition(Vec2 tVec);
	virtual Vec2 GetVec();
	virtual void SetVec(Vec2 tVec);
	virtual float GetSpeedPower();

	virtual void MoveActor(float dt);
	virtual float IncreaseSpeed(float dt);



	Sprite* GetSprite();

	void IdleState();
	void MoveState();
	void AttackState();
	void AttackEndState();
	void DeadState();

	float GetDirectionX();
	float GetDirectionY();
	int GetDir();
	float GetMaxHP();
	float GetCurHP();
	
public:
	CActor();
	virtual ~CActor();
};