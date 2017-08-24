#pragma once

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

#define Idle 0
#define Move 1
#define Attack 2
#define Dead 3

class GameScene;
class CBackgroundLayer;
class CVirtualPad;

class CActorAniBox;
class CObjectAniBox;

class CActor
{	
private :

protected:	

	//Actor Status
	int mLevel = 0;
	float mEXP = 0.0f;
	float mHP = 0.0f;
	float mAP = 0.0f;
	float mDefence = 0.0f;
	float mSpeed = 0.0f;
	float mSpeedRatio = 1.0f;
	
	//Sprite *mpActor = NULL;
	//Sprite *mpAttackEffect;

	CActorAniBox *mpActorAniBox = NULL;
	CObjectAniBox *mpObjectAniBox = NULL;
	Node *mpScene = NULL;
	CVirtualPad *mpVirtualPad = NULL;

	Vec2 mVec;

	int mState = Idle;
	
	int mDir = 0;		//0:up, 1: down, 2: left, 3: right
	
	float mDirX = 0.0f;
	float mDirY = 0.0f;
			



public:
	virtual void Clear();
	

	/////////////////AniBox 관련한 곳//////////////////
	void Create();
	void SetScene(Node *tpScene);

	void FSM_Selector();
	void Dir_Selector(int tDir);
	void SetmDir(int tDir);
	void SetFsm(int tFsm);

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

	float GetDirectionX();
	float GetDirectionY();

	void AttackDirSelector();

	Sprite* GetSprite();

public:
	CActor();
	virtual ~CActor();
};