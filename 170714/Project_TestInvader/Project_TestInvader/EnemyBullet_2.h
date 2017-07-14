#pragma once
#include "EnemyBullet.h"

class CEnemy_2;

class CEnemyBullet_2 : public CEnemyBullet
{
protected:
	int mFire = 0;

public:
	void Clean(char *tpPixel);
	void Setup(); //������ X,Y ��ǥ
	void Fire(CEnemy_2 *tpEnemy_2);
	void Display(char *tpPixel); // �׷��� ǥ��
	void SetPositionForFire(CEnemy_2 *tpEnemy_2);
};

