#pragma once
#include "Unit.h"

class CBullet : public CUnit
{
protected:
	bool mIsLife = false;
	/*
	int mX = 0;
	int mY = 0;
	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;
	*/
public:
	CBullet();
	~CBullet();
	
	virtual void Setup(); //������ X,Y ��ǥ
	virtual void Display(char *tpPixel); // �׷��� ǥ��
	virtual void SetIsLife(bool tIsLife);

};

