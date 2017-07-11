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
	void Setup(); //������ X,Y ��ǥ
	void MoveWithInput(); //����
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	void Fire();

	int GetX();
	int GetY();
};


