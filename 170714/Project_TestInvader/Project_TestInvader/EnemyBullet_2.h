#pragma once
#include "EnemyBullet.h"

class CEnemy_2;

class CEnemyBullet_2 : public CEnemyBullet
{
protected:
	int mFire = 0;

public:
	void Clean(char *tpPixel);
	void Setup(); //액터의 X,Y 좌표
	void Fire(CEnemy_2 *tpEnemy_2);
	void Display(char *tpPixel); // 그래픽 표시
	void SetPositionForFire(CEnemy_2 *tpEnemy_2);
};

