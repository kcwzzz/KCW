
#include "stdafx.h"
#include "EnemyBullet.h"
#include "Define.h"
#include "Enemy.h"

#include <stdlib.h>
#include <time.h>

void CEnemyBullet::Setup() //������ X,Y ��ǥ
{
	mX = WIDTH / 2;
	mY = 1;
	mIsLife = false;
}

void CEnemyBullet::ReadyToFire(CEnemy *tpEnemy) //�������� ����
{
	//switch (tKey)
	//{
	//case 'M':
	//case 'm':
	//{
	//�߻�����
	mX = tpEnemy->GetX();
	mY = tpEnemy->GetY() + 1;

	//�߻�ƴ��� ����

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
			//�߻�����
		mX = tpEnemy->GetX();
		mY = tpEnemy->GetY();
		mIsLife = true;
		//�߻�ƴ��� ����			
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


void  CEnemyBullet::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = '|';
}