#pragma once
#include "Unit.h"

class CBullet : public CUnit
{
protected:
	bool mIsLife = false;

public:
	CBullet();
	~CBullet();
	
	virtual void Setup(); //������ X,Y ��ǥ
	virtual void Display(char *tpPixel); // �׷��� ǥ��
	virtual void SetIsLife(bool tIsLife);
};

