#pragma once

#include <stdio.h>
#include <vector>
#include "cocos2d.h"

using namespace std;

class FSM_Manager
{
private:

	static FSM_Manager *mpInstance;

	int mActorState = 0;
	int mEnemyState = 0;

protected:

public:
	static FSM_Manager *Getinstance();

	int GetNowState();
	void SetNowState(int tNowState);


};