#include "stdafx.h"
#include "Define.h"

#include "EnemyBullet.h"
#include "Enemy.h"
#include "Actor.h"

void CEnemyBullet::  Setup() //������ X,Y ��ǥ
{
	mX = WIDTH / 2;
	mY = 1;
	mIsLife = false;
}
void CEnemyBullet::Fire(CEnemy *tpEnemy)
{
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
	else
	{
		SetPositionForFire(tpEnemy);
	}
	
}

void  CEnemyBullet::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + mY*WIDTH + mX) = '|';
}

void CEnemyBullet::SetPositionForFire(CEnemy *tpEnemy)
{
	mX = tpEnemy->GetX();
	mY = tpEnemy->GetY()+1;
}

