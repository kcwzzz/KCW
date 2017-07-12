#include "stdafx.h"
#include "EnemyBullet.h"
#include "Define.h"
#include "Enemy.h"
#include "Unit.h"

#include <stdlib.h>
#include <time.h>

void CEnemyBullet::  Setup() //������ X,Y ��ǥ
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
			//�߻�����
			mX = tpEnemy->GetX();
			mY = tpEnemy->GetY();

			//�߻�ƴ��� ����
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
void  CEnemyBullet::Clean(char *tpPixel) // �׷��� Ŭ����
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void  CEnemyBullet::Display(char *tpPixel) // �׷��� ǥ��
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