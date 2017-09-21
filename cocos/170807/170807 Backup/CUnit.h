#pragma once

#include "cocos2d.h"

USING_NS_CC;

class CUnit
{	
protected:

	Vec2 mVec;
	float mSpeedPower = 0;
	Sprite *mpUnitImage;

	int mUnitHP = 0;
	
	//float mX = 0;
	//float mY = 0;
	//float mDirX = 0;
	//float mDirY = 0;
	
public:

	CUnit();
	virtual ~CUnit();
	Vec2 GetVec();
	void SetVec(Vec2 tVec);


};