#include "stdafx.h"
#include "EnemyBullet.h"
#include "Define.h"
#include "Enemy.h"
#include "Unit.h"

#include <stdlib.h>
#include <time.h>

void CEnemyBullet::  Setup() //액터의 X,Y 좌표
{
	mX = WIDTH / 2;
	mY = 1;
	mIsLife = false;
}
void CEnemyBullet::Fire(CEnemy *tpEnemy)
{
	/*
	srand((unsigned int)time(NULL));

	if (false == mIsLife)
	{
		mFire = rand() % 6 + 1;
		if (1 == mFire)
		{
			//발사지점
			mX = tpEnemy->GetX();
			mY = tpEnemy->GetY();

			//발사됐는지 여부
			mIsLife = true;
		}
	}
	*/
	if (true == mIsLife)
	{
		if (mY < HEIGHT - 1)
		{
			mDirY = 1;
			mSpeedPower = 1;
			mY = mY + mDirY*mSpeedPower;
		}
		else
		{
			mY = mY;
			mIsLife = false;
		}
	}
	
}
void  CEnemyBullet::Clean(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void  CEnemyBullet::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + mY*WIDTH + mX) = '|';
}

void CEnemyBullet::SetPositionForFire(CEnemy *tpEnemy)
{
	mX = tpEnemy->GetX();
	mY = 1;
}
void CEnemyBullet::SetIsLife(bool tIsLife)
{
	mIsLife = tIsLife;
}