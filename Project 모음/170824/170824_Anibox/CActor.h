#pragma once

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

#define Idle 0
#define Move 1
#define Attack 2
#define Dead 3

class CActorAniBox;
class CObjectAniBox;

class CActor 
{
protected:		
	CActorAniBox *mpActorAniBox = NULL;
	CObjectAniBox *mpObjectAniBox = NULL;

	int mState = Idle;
	int mCurState = Idle;
	int mDir = 0;
	int mCurDir = 0;

	Vec2 mVec;
	Node *mpScene = NULL;

public:

	void Create();
	void SetSecne(Node *tpScene);
	
	void FSM_Selector();
	void Dir_Selector();
	void SetmDir(int tDir);
	void SetFsm(int tFsm);

};