#include "stdafx.h"
#include "EnemyBullet.h"
#include "Define.h"
#include "Enemy.h"

#include <stdlib.h>
#include <time.h>

void CEnemyBullet::  Setup() //액터의 X,Y 좌표
{
	mX = WIDTH / 2;
	mY = 1;
	tIsLife = false;
}
void CEnemyBullet::Fire(CEnemy *tpEnemy)
{
	srand((unsigned int)time(NULL));

	if (false == tIsLife)
	{
		mFire = rand() % 6 + 1;
		if (1 == mFire)
		{
			//발사지점
			mX = tpEnemy->GetX();
			mY = tpEnemy->GetY();

			//발사됐는지 여부
			tIsLife  = true;
		}
	}

	else if (true == tIsLife)
	{
		if (mY < HEIGHT - 1)
		{
			mY = mY + 1;
		}
		else
		{
			mY = mY;
			tIsLife = false;
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