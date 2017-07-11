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
	void Setup(); //액터의 X,Y 좌표
	void Fire(CEnemy *tpEnemy );
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
	void SetPositionForFire(CEnemy *tpEnemy);
	void SetIsLife(bool tBulletLife);
};

