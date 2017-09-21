#pragma once
#include "Unit.h"

class CBullet : public CUnit
{
protected:
	bool mIsLife = false;

public:
	CBullet();
	~CBullet();
	
	virtual void Setup(); //액터의 X,Y 좌표
	virtual void Display(char *tpPixel); // 그래픽 표시
	virtual void SetIsLife(bool tIsLife);
};

