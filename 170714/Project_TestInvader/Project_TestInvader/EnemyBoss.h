#pragma once
#include "EnemyBullet.h"
#include "Enemy.h"

class CEnemyBoss : public CEnemy
{
protected:
	CEnemyBullet tEnemyBullet[10];

public:
	void Setup(); //������ X,Y ��ǥ
	void Display(char *tpPixel);
};

