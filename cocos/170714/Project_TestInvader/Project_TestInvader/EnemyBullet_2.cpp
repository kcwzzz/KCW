#include "stdafx.h"
#include "Define.h"

#include "EnemyBullet_2.h"
#include "Enemy_2.h"

void CEnemyBullet_2::Setup() //액터의 X,Y 좌표
{
	mX = WIDTH / 2;
	mY = 1;
	mIsLife = false;
}

void CEnemyBullet_2::Fire(CEnemy_2 *tpEnemy)
{
	if (true == mIsLife)
	{
		if (mY < HEIGHT - 1)
		{
			mDirY = 1;
			mSpeedPower = 1;
			mX1 = mX1 + mSpeedPower;

			mX2 = mX2 - mSpeedPower;

			mY = mY + mDirY*mSpeedPower;
		}
		else
		{
			mY = mY;
			mIsLife = false;
		}
	}
	else
	{
		SetPositionForFire(tpEnemy);
	}
}

void CEnemyBullet_2::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
	*(tpPixel + mY*WIDTH + mX1) = 0;
	*(tpPixel + mY*WIDTH + mX2) = 0;
}

void  CEnemyBullet_2::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + mY*WIDTH + mX) = '$';
	*(tpPixel + mY*WIDTH + mX1) = '$';
	*(tpPixel + mY*WIDTH + mX2) = '$';
}

void CEnemyBullet_2::SetPositionForFire(CEnemy_2 *tpEnemy_2)
{
	mX = tpEnemy_2->GetX();
	mX1 = tpEnemy_2->GetX();
	mX2 = tpEnemy_2->GetX();
	mY = tpEnemy_2->GetY()+1;
}