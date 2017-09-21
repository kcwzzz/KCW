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
	virtual void Setup() = 0;		//   ���� ���� �Լ�
	//virtual void Display(char *tpPixel) = 0; // �׷��� ǥ��
	//virtual void Clean(char *tpPixel); // �׷��� Ŭ����

	CUnit();
	virtual ~CUnit();

};