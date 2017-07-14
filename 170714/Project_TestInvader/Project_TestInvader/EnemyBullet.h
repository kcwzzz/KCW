#pragma once
#include "Bullet.h"

class CEnemy;

class CEnemyBullet : public CBullet
{

protected :
	int mX1 = 0;
	int mY1 = 0;

	int mX2 = 0;
	int mY2 = 0;

	int mFire = 0;
	
public :
	void Setup(); //액터의 X,Y 좌표
	void Fire(CEnemy *tpEnemy );
	void Display(char *tpPixel); // 그래픽 표시
	void SetPositionForFire(CEnemy *tpEnemy);
};

