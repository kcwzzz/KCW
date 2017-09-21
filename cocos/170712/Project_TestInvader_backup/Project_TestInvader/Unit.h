#pragma once

class CUnit
{
protected:
	float mX = 0;
	float mY = 0;
	float mDirX = 0;
	float mDirY = 0;
	float mSpeedPower = 0;
	
public:
	virtual void Setup(); //순수 가상 함수
	virtual void Display(char *tpPixel); // 그래픽 표시
	virtual void Clean(char *tpPixel); // 그래픽 클리어

	CUnit();
	virtual ~CUnit();
};