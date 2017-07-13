#pragma once

#include "Bullet.h"
#include "Enemy.h"

class CEnemy;

class CEnemyBullet :public CBullet
{
protected :
	int mFire = 0;

public :
	void Setup();
	void ReadyToFire(CEnemy *tpEnemy); //���� ����
	void Move(CEnemy *tpEnemy );
	void Display(char *tpPixel);
};

