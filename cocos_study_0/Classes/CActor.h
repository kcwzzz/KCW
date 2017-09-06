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
	string mImageSpriteFile;
	
	CActorAniBox *mpActorAniBox = NULL;
	Vec2 mVec;


	CObjectAniBox *mpObjectAniBox = NULL;
	Sprite *mpAttSprite = NULL;
	Sprite *mpColisionBox = NULL;
	Vec2 mAttackVec;//충돌박스의 위치


	CVirtualPad *mpVirtualPad = NULL;
	CGuageHP *mpGuageHP = NULL;

	Node *mpScene = NULL;
	TMXTiledMap *mpTiledMap = NULL;
	CBackgroundLayer *mpBGLayer = NULL;
	
	int mState = IDLE;
	int mCurState = IDLE;

	int mDir = Up_Dir  ;		//0:up, 1: down, 2: left, 3: right
	int mCurDir = Up_Dir;
		
	float mDirX = 0.0f;
	float mDirY = 0.0f;

public:
	virtual void Clear();
	
	/////////////////AniBox 관련한 곳//////////////////
	virtual void Create();

	virtual void SetScene(Node *tpScene);
	virtual void ActorHPGauge(Node *tpNode);
	virtual void Dir_Selector();
	virtual void SetmDir(int tDir);
	virtual void SetFsm(int tFsm);
	virtual void SetDamaged(int tint);
	virtual void FollowObject();

	virtual void SetVirtualPad(CVirtualPad *tpVirtualPad);
	///////////////////////////////////////////////////
	
	virtual void Build();

	virtual void CalcDir();
	void FollowActor();

	virtual void setPosition(Vec2 tVec);
	int ColisionGeometry();

	virtual void MoveActor(float dt);
	virtual float IncreaseSpeed(float dt);
	
	Sprite* GetSprite();
	
	//Actor FSM에 사용(예정)
	virtual void IdleState();
	virtual void MoveState();
	virtual void AttackState();
	virtual void AttackEndState();
	virtual void DeadState();
	//

	//CGuageHP : HP bar 노출에 사용
	virtual float GetMaxHP();
	virtual float GetCurHP();
	virtual Sprite* GetAttackSprite();
	
public:
	CActor();
	virtual ~CActor();
};