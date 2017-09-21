#pragma once

#include "cocos2d.h"

USING_NS_CC;

class GameScene;

class CUnit
{	
protected:

	Vec2 mVec;
	float mSpeedPower = 0;
	Sprite *mpUnitImage;	
	GameScene *mpScene = NULL;

public:

	CUnit();
	virtual ~CUnit();

public:
	virtual void Create();
	virtual void setPosition(Vec2 tVec);
	virtual void SetScene(GameScene *tpScene);
	virtual void Build();
	virtual void Clear();

	virtual Vec2 GetVec();
	virtual void SetVec(Vec2 tVec);
	virtual float GetSpeedPower();
};