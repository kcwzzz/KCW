
#include "stdafx.h"
#include "EnemyBullet.h"
#include "Define.h"
#include "Enemy.h"

#include <stdlib.h>
#include <time.h>

void CEnemyBullet::Setup() //액터의 X,Y 좌표
{
	mX = WIDTH / 2;
	mY = 1;
	mIsLife = false;
}

void CEnemyBullet::ReadyToFire(CEnemy *tpEnemy) //시작지점 세팅
{
	//switch (tKey)
	//{
	//case 'M':
	//case 'm':
	//{
	//발사지점
	mX = tpEnemy->GetX();
	mY = tpEnemy->GetY() + 1;

	//발사됐는지 여부

	mIsLife = true;
	//	break;
	//}
	//}	
}


void CEnemyBullet::Move(CEnemy *tpEnemy)
{
	//srand((unsigned int)time(NULL));
	if (false == mIsLife)
	{
		//mFire = rand() % 6 + 1;
		//if (1 == mFire)
		//{
			//발사지점
		mX = tpEnemy->GetX();
		mY = tpEnemy->GetY();
		mIsLife = true;
		//발사됐는지 여부			
	//}
	}

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


void  CEnemyBullet::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = '|';
}