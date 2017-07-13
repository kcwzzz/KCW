#pragma once
class CUnit
{
protected:
	int mX = 0;
	int mY = 0;
	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;

public:
	CUnit();
	~CUnit();

	virtual void Setup(); //액터의 X,Y 좌표
	virtual void Clean(char *tpPixel); // 그래픽 클리어
	virtual void Display(char *tpPixel); // 그래픽 표시
};

