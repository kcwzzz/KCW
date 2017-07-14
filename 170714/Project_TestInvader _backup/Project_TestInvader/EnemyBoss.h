#pragma once
#include "Enemy.h"

class CEnemyBoss : public CEnemy
{
protected:
	CEnemyBullet *tEnemyBullet[10];

public:
	CEnemyBoss();
	~CEnemyBoss();
	void Setup(); //액터의 X,Y 좌표
	void Display(char *tpPixel);
};

