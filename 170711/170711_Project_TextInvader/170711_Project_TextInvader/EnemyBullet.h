#pragma once

class CEnemy;

class CEnemyBullet
{
protected:
	int mX = 0;
	int mY = 0;
	bool mBulletLife = false;
	
	int mSpeedPower = 0;
	int mDirX = 0;
	int mDirY = 0;

public:
	CEnemyBullet();
	~CEnemyBullet();

	void Setup();
	void MoveWithInput(CEnemy *tpEnemy);
	void Move();
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
	void SetPositionForFire(CEnemy *tpActor);
	void SetIsLife(bool tIsLife);
};
