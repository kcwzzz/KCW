#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"
#include "Define.h"

#include <windows.h>


CEnemy::CEnemy()
{
	mX = 0;
	mY = 0;
}
CEnemy::~CEnemy()
{

}
void CEnemy::Setup()
{
	mX = WIDTH / 2;
	mY = 0;
	mDir = DIR_RIGHT;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Setup();
	}
}
void CEnemy::Move()
{
	if (DIR_RIGHT == mDir)
	{
		if (mX < WIDTH - 1)
		{
			mSpeedPower = 1;
			mDirX = 1;
			mX = mX + mDirX* mSpeedPower;
		}
		else
		{
			mDir = DIR_LEFT;
		}
	}

	if (DIR_LEFT == mDir)
	{
		if (mX > 0)
		{
			mSpeedPower = 1;
			mDirX = -1;

			mX = mX + mDirX* mSpeedPower;
		}
		else
		{
			mDir = DIR_RIGHT;
		}
	}
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Move();
	}
}

void CEnemy::MoveWithInput(CEnemy *tpEnemy)
{

	tEnemyBullet[mCurBulletIndex].MoveWithInput(tpEnemy);

	if (mCurBulletIndex < 10 - 1)
	{
		mCurBulletIndex++;
	}
	else
	{
		mCurBulletIndex = 0;
	}
}

void CEnemy::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Clean(tpPixel);
	}
}
void CEnemy::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = '#';

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Display(tpPixel);
	}
}
int CEnemy::GetX()
{
	return mX;
}

void CEnemy::Update()
{
	int ti = 0;
	if (0 == tDelay)
	{
		tDelay = GetTickCount();
	}

	tTemp = GetTickCount();

	if (tTemp - tDelay > 2000)
	{

		tEnemyBullet[mCurBulletIndex].SetPositionForFire(this);
		tEnemyBullet[mCurBulletIndex].SetIsLife(this);

		if (mCurBulletIndex < 10 - 1)
		{
			mCurBulletIndex++;
		}
		else
		{
			mCurBulletIndex = 0;
		}

		tDelay = tTemp;
	}
}
