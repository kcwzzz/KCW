#pragma once
#include "Enemy.h"

class CEnemyBoss : public CEnemy
{
protected:
	CEnemyBullet *tEnemyBullet[10];

public:
	CEnemyBoss();
	~CEnemyBoss();
	void Setup(); //������ X,Y ��ǥ
	void Display(char *tpPixel);
};

