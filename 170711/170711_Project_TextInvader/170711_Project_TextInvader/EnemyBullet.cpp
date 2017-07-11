#include "stdafx.h"
#include <time.h>
#include <stdlib.h>


#include "Define.h"
#include "Enemy.h"
#include "EnemyBullet.h"

CEnemyBullet::CEnemyBullet()
{

}
CEnemyBullet :: ~CEnemyBullet()
{

}
void CEnemyBullet::Setup()
{
	mX = WIDTH / 2;
	mY = 1;
	mBulletLife = false;
}
void CEnemyBullet::MoveWithInput(CEnemy *tpEnemy)
{
	/*
	
	srand((unsigned int)time(NULL));

	int tFire = rand() % 6 + 1;
	if (1 == tFire)
	{
		//발사지점
		mX = tpEnemy->GetX();
		mY = 1;

		//발사됐는지 여부
		mBulletLife = true;
	}
	*/
}
void CEnemyBullet::Move()
{
	if (true == mBulletLife)
	{
		if (mY < HEIGHT - 1)
		{
			mSpeedPower = 1;
			mDirY = 1;

			mY = mY + mDirY * mSpeedPower;
		}
	}
}
void CEnemyBullet::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void CEnemyBullet::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = '|';
}

void CEnemyBullet ::SetPositionForFire(CEnemy *tpEnemy)
{
	mX = tpEnemy->GetX();
	mY = 1;
}
void CEnemyBullet:: SetIsLife(bool tBulletLife)
{
	mBulletLife = tBulletLife;
}