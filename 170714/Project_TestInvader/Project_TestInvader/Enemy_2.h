#pragma once
#include "Enemy.h"

class CEnemyBullet_2;

class CEnemy_2 : public CEnemy
{
protected:
	CEnemyBullet_2 *tEnemyBullet_2[10];

public:
	CEnemy_2();
	~CEnemy_2();
	void Setup(int tShift); //액터의 X,Y 좌표
	void MoveWithInput(); //조정
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
	void Update();
	void Fire();
	float CEnemy_2::EnemyBulletX(int tBulletNum);
	float CEnemy_2::EnemyBulletY(int tBulletNum);

};