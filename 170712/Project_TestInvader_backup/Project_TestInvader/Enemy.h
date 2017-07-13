#pragma once

#include "Character.h"
#include "EnemyBullet.h"

class CEnemyBullet;

class CEnemy : public CCharacter
{
protected :
	int mDir = 0;
	unsigned int tDelay = 0;
	unsigned int tTemp = 0;

	CEnemyBullet tEnemyBullet[10];

public:
	void Setup();
	void MoveWithInput(); //Á¶Á¤
	void Fire();
	void Update();

	void Display(char *tpPixel);
};