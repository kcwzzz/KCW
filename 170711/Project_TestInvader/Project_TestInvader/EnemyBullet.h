#pragma once
class CEnemy;

class CEnemyBullet
{

protected :
	int mFire = 0;
	int mX = 0;
	int mY = 0;
	bool mIsLife = false;

	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;

public :
	void Setup(); //������ X,Y ��ǥ
	void Fire(CEnemy *tpEnemy );
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	void SetPositionForFire(CEnemy *tpEnemy);
	void SetIsLife(bool tBulletLife);
};

