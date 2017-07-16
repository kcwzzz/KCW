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
	virtual void Setup(int tShift); //������ X,Y ��ǥ
	virtual void MoveWithInput(); //����
	virtual void Clean(char *tpPixel); // �׷��� Ŭ����
	virtual void Display(char *tpPixel); // �׷��� ǥ��

	virtual void Fire();
	virtual void Update();

	virtual float EnemyBulletX(int tBulletNum);
	virtual float EnemyBulletY(int tBulletNum);


};


