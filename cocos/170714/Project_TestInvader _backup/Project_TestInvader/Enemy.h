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
	void Setup(); //������ X,Y ��ǥ
	void MoveWithInput(); //����
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	void Fire();
	void Update();
};


