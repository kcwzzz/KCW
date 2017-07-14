#pragma once
#include "Bullet.h"

class CEnemy;

class CEnemyBullet : public CBullet
{

protected :
	int mFire = 0;
	
public :
	void Setup(); //������ X,Y ��ǥ
	void Fire(CEnemy *tpEnemy );
	//void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	void SetPositionForFire(CEnemy *tpEnemy);
	//void SetIsLife(bool tBulletLife);
};

