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
	virtual void Setup(int tShift); //액터의 X,Y 좌표
	virtual void MoveWithInput(); //조정
	virtual void Clean(char *tpPixel); // 그래픽 클리어
	virtual void Display(char *tpPixel); // 그래픽 표시

	virtual void Fire();
	virtual void Update();

	virtual float EnemyBulletX(int tBulletNum);
	virtual float EnemyBulletY(int tBulletNum);


};


