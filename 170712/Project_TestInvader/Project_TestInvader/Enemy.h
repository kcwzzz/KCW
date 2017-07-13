#pragma once

#include "EnemyBullet.h"
#include "Unit.h"

class CEnemy : public CUnit
{
protected :
	int mDir = 0;

	int mCurBulletIndex = 0;
	unsigned int tDelay = 0;
	unsigned int tTemp = 0;
	int mSpeedPower = 0;

	CEnemyBullet tEnemyBullet[10];

public:

	void MoveWithInput(); //����

	void Fire();
	void Update();

	int GetX();
	int GetY();
};