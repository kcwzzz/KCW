#pragma once
#include "Character.h"

class CEnemyBullet;

class CEnemy : public CCharacter
{
protected :
	int mDir = 0;
	CEnemyBullet *tEnemyBullet[10];
	unsigned int tDelay = 0;
	unsigned int tTemp = 0;

public:
	CEnemy();
	~CEnemy();
	void Setup(); //액터의 X,Y 좌표
	void MoveWithInput(); //조정
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
	void Fire();
	void Update();
};


