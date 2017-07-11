#include "stdafx.h"
#include "EnemyBullet.h"
#include "Define.h"
#include "Enemy.h"

#include <stdlib.h>
#include <time.h>

void CEnemyBullet::  Setup() //������ X,Y ��ǥ
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
			//�߻�����
			mX = tpEnemy->GetX();
			mY = tpEnemy->GetY();

			//�߻�ƴ��� ����
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
void  CEnemyBullet::Clean(char *tpPixel) // �׷��� Ŭ����
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void  CEnemyBullet::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + mY*WIDTH + mX) = '|';
}