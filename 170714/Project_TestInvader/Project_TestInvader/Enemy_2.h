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
	void Setup(int tShift); //������ X,Y ��ǥ
	void MoveWithInput(); //����
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	void Update();
	void Fire();
	float CEnemy_2::EnemyBulletX(int tBulletNum);
	float CEnemy_2::EnemyBulletY(int tBulletNum);

};