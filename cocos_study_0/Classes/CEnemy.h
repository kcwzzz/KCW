#pragma once

#include "cocos2d.h"
#include "Define.h"
#include "CActor.h"

USING_NS_CC;

using namespace std;

class CEnemy : public CActor
{

protected:
	int mCountClock = 0;
	Sprite *mpAttSprite = NULL;

public:
	void Clear();
	void Create();
	void MovePatten(float f);
	void Dir_Selector();
	Sprite* GetAttackSprite();
	void Build();
};