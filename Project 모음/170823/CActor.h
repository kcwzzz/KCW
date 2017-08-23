#pragma once

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

#define Idle 0
#define Move 1

class CActorAniBox;

class CActor 
{
protected:		
	CActorAniBox *mpActorAniBox = NULL;

	int mState = Idle;
	int mCurState = Idle;
	int mDir = 0;
	int mCurDir = 0;

	Node *mpScene = NULL;

public:

	void Create();
	void SetSecne(Node *tpScene);
	
	void FSM_Selector();
	void Dir_Selector();
	void SetmDir(int tDir);
	void SetFsm(int tFsm);

};