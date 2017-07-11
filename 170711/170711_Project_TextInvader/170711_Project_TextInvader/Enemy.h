#pragma once
#include "EnemyBullet.h"

class CEnemy
{
protected:
	int mX = 0;
	int mY = 0;
	int mDir = 0;

	int mCurBulletIndex = 0;
	unsigned int tDelay = 0;
	unsigned int tTemp = 0;

	int mSpeedPower = 0;
	int mDirX = 0;
	int mDirY = 0;

	CEnemyBullet tEnemyBullet[10];

public:
	CEnemy();
	~CEnemy();

	void Setup();
	void Move();
	void MoveWithInput(CEnemy *tpEnemy);
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
	int GetX();

	void Update();
	
};