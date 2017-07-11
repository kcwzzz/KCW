#pragma once

#include "EnemyBullet.h"

class CEnemy
{
protected :
	int mX = 0;
	int mY = 0;
	int mDir = 0;

	CEnemyBullet tEnemyBullet[10];

public:
	void Setup(); //액터의 X,Y 좌표
	void MoveWithInput(); //조정
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
	void Fire();

	int GetX();
	int GetY();
};


