#pragma once
#include "Unit.h"

class CBullet : public CUnit
{
protected :
	bool mIsLife = false;

public:
	CBullet();
	~CBullet();
	
	void SetIsLife(bool tIsLife);
	virtual void ReadyToFire() = 0;
};

