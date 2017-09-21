#pragma once
#include "Unit.h"

class CCharacter : public CUnit 
{
protected:
	int mCurBulletIndex = 0;
	/*
	int mX = 0;
	int mY = 0;

	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;
	*/

public:
	CCharacter();
	~CCharacter();

	virtual void Setup(); //액터의 X,Y 좌표
	virtual void MoveWithInput(); //조정
	virtual void Clean(char *tpPixel); // 그래픽 클리어
	virtual void Display(char *tpPixel); // 그래픽 표시
	
	int GetX();
	int GetY();
};