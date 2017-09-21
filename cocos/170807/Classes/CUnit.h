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
	virtual void Setup() = 0;		//   순수 가상 함수
	//virtual void Display(char *tpPixel) = 0; // 그래픽 표시
	//virtual void Clean(char *tpPixel); // 그래픽 클리어

	CUnit();
	virtual ~CUnit();

};