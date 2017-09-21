#pragma once

#include "Unit.h"
#include "EnemyBullet.h"

class CBullet : public CUnit
{
protected :
	bool mIsLife = false;

	//CEnemyBullet tEnemyBullet[10];

public:
	CBullet();
	~CBullet();
	
	void SetIsLife(bool tIsLife);
	virtual void ReadyToFire();
};

