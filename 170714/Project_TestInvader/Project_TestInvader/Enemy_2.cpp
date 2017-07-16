#include "stdafx.h"

#include <windows.h>
#include "Define.h"

#include "Enemy_2.h"
#include "EnemyBullet_2.h"

CEnemy_2::CEnemy_2()
{
	int ti = 0;
	for (ti = 0; ti < 10;ti++)
	{
		tEnemyBullet_2[ti] = new CEnemyBullet_2();
	}
}

CEnemy_2 ::~CEnemy_2()
{
	int  ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		if (NULL != tEnemyBullet_2[ti])
		{
			delete tEnemyBullet_2[ti];
			tEnemyBullet_2[ti] = NULL;
		}
	}
}

void CEnemy_2::Setup(int tShift) //액터의 X,Y 좌표
{
	mDir = DIR_LEFT;
	mX = (WIDTH / 4) +tShift;
	mY = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet_2[ti]->Setup();
	}
}

void CEnemy_2::MoveWithInput() //조정
{

	if (DIR_RIGHT == mDir)
	{
		if (mX< WIDTH *3/4)
		{
			mDirX = 1;
			mSpeedPower = 3;
			mX = mX + mDirX*mSpeedPower;
		}
		else
		{
			mDir = DIR_LEFT;
		}
	}

	if (DIR_LEFT == mDir)
	{
		if (mX > WIDTH /4)
		{
			mDirX = -1;
			mSpeedPower = 3;
			mX = mX + mDirX*mSpeedPower;
		}
		else
		{
			mDir = DIR_RIGHT;
		}
	}
}
void CEnemy_2::Clean(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + mY*WIDTH + mX) = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet_2[ti]->Clean(tpPixel);
	}
}

void CEnemy_2::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + mY*WIDTH + mX) = '@';
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet_2[ti]->Display(tpPixel);
	}
}

void CEnemy_2::Fire()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet_2[ti]->Fire(this);
	}
}

void CEnemy_2::Update()
{
	int ti = 0;
	if (0 == tDelay)
	{
		tDelay = GetTickCount();
	}

	tTemp = GetTickCount();

	if (tTemp - tDelay > 5000)
	{

		tEnemyBullet_2[mCurBulletIndex]->SetPositionForFire(this);
		tEnemyBullet_2[mCurBulletIndex]->SetIsLife(this);

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

float CEnemy_2::EnemyBulletX(int tBulletNum)
{
	return tEnemyBullet_2[tBulletNum]->GetX();

}

float CEnemy_2::EnemyBulletY(int tBulletNum)
{
	return tEnemyBullet_2[tBulletNum]->GetY();
}
