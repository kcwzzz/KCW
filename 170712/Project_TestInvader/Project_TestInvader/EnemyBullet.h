#pragma once
//class CEnemy;
//#include "Enemy.h"

class CEnemyBullet //: public CEnemy
{

protected :
	int mFire = 0;

	bool mIsLife = false;

	int mSpeedPower = 0;

public :

	void Fire(CEnemy *tpEnemy );

	void SetPositionForFire(CEnemy *tpEnemy);
	void SetIsLife(bool tBulletLife);
};

