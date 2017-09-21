#pragma once
#include "EnemyBullet.h"
#include "Enemy.h"

class CEnemyBoss : public CEnemy
{
protected:
	int mX = 0;
	int mY = 0;
	int mDir = 0;

	int mCurBulletIndex = 0;
	unsigned int tDelay = 0;
	unsigned int tTemp = 0;

	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;

	CEnemyBullet tEnemyBullet[10];

public:
	void Setup(); //액터의 X,Y 좌표
	void MoveWithInput(); //조정
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
	void Fire();
	void Update();

	int GetX();
	int GetY();
};

