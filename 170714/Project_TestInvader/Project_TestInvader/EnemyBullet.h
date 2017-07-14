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
	void Setup(); //������ X,Y ��ǥ
	void Fire(CEnemy *tpEnemy );
	void Display(char *tpPixel); // �׷��� ǥ��
	void SetPositionForFire(CEnemy *tpEnemy);
};

