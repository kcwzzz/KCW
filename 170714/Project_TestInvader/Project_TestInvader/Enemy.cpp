#include "stdafx.h"
#include "Enemy.h"
#include "Define.h"
#include <windows.h>


void CEnemy::Setup() //액터의 X,Y 좌표
{
	mDir = DIR_LEFT;
	mX = (WIDTH / 2);
	mY = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Setup();
	}
}
void CEnemy::MoveWithInput() //조정
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
void CEnemy::Clean(char *tpPixel) // 그래픽 클리어
{
	CCharacter::Clean(tpPixel);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Clean(tpPixel);
	}
}
void CEnemy::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + mY*WIDTH + mX) = '#';
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Display(tpPixel);
	}
}

void CEnemy::Fire()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Fire(this);
	}
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
