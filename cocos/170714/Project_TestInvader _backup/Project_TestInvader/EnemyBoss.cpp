#include "stdafx.h"
#include "Define.h"

#include <windows.h>

#include "EnemyBoss.h"
#include "EnemyBullet.h"

CEnemyBoss::CEnemyBoss()
{
	int ti = 0;
	for (ti = 0; ti < 10;ti++)
	{
		tEnemyBullet[ti] = new CEnemyBullet();
	}
}

CEnemyBoss ::~CEnemyBoss()
{
	int  ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		if (NULL != tEnemyBullet[ti])
		{
			delete tEnemyBullet[ti];
			tEnemyBullet[ti] = NULL;
		}
	}
}

void CEnemyBoss::Setup() //액터의 X,Y 좌표
{
	mDir = DIR_LEFT;
	mX = WIDTH / 4;
	mY = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti]->Setup();
	}
}
/*
void CEnemyBoss::MoveWithInput() //조정
{

	if (DIR_RIGHT == mDir)
	{
		if (mX< WIDTH - 1)
		{
			mDirX = 1;
			mSpeedPower = 1;
			mX = mX + mDirX*mSpeedPower;
		}
		else
		{
			mDir = DIR_LEFT;
		}
	}

	if (DIR_LEFT == mDir)
	{
		if (mX > 1)
		{
			mDirX = -1;
			mSpeedPower = 1;
			mX = mX + mDirX*mSpeedPower;
		}
		else
		{
			mDir = DIR_RIGHT;
		}
	}
}
void CEnemyBoss::Clean(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + mY*WIDTH + mX) = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Clean(tpPixel);
	}
}
*/
void CEnemyBoss::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + mY*WIDTH + mX) = '@';
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti]->Display(tpPixel);
	}
}
/*
int CEnemyBoss::GetX()
{
	return mX;
}
int CEnemyBoss::GetY()
{
	return mY;
}

void CEnemyBoss::Fire()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Fire(this);
	}
}

void CEnemyBoss::Update()
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
*/