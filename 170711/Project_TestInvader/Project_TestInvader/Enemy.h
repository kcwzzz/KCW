#pragma once
#include "Character.h"
#include "EnemyBullet.h"

class CEnemy : public CCharacter
{
protected :
	/*
	int mX = 0;
	int mY = 0;
	int mCurBulletIndex = 0;
	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;
	*/
	int mDir = 0;
	CEnemyBullet tEnemyBullet[10];
	unsigned int tDelay = 0;
	unsigned int tTemp = 0;

public:
	void Setup(); //������ X,Y ��ǥ
	void MoveWithInput(); //����
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	void Fire();
	void Update();
};


