
#include "stdafx.h"

#include <windows.h>
#include "Define.h"

#include "Enemy.h"
#include "EnemyBullet.h"

CEnemy::CEnemy() 
{
	int ti = 0;
	for (ti = 0; ti < 10;ti++)
	{
		tEnemyBullet[ti] = new CEnemyBullet();
	}
}

CEnemy ::~CEnemy()
{
	int  ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		if (NULL != tEnemyBullet[ti])
		{
			delete tEnemyBullet[ti];
			tEnemyBullet[ti] = NULL;
		}
	}
}

void CEnemy::Setup(int tShift) //������ X,Y ��ǥ
{
	mDir = DIR_LEFT;
	mX = (WIDTH / 10)+ tShift;
	mY = 3;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
	 	tEnemyBullet[ti]->Setup();
	}
}
void CEnemy::MoveWithInput() //����
{
	if (DIR_RIGHT == mDir)
	{
		if (mX< WIDTH - 1)
		{
			mDirX = 1;
<<<<<<< HEAD
			mSpeedPower = 1;
=======
//			mSpeedPower = 2;
			mSpeedPower = 0;

>>>>>>> parent of 18a83f7... no message
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
<<<<<<< HEAD
			mSpeedPower = 1;
=======
//			mSpeedPower = 2;

			mSpeedPower = 0;
>>>>>>> parent of 18a83f7... no message
			mX = mX + mDirX*mSpeedPower;
		}
		else
		{
			mDir = DIR_RIGHT;
		}
	}
}
void CEnemy::Clean(char *tpPixel) // �׷��� Ŭ����
{
	CCharacter::Clean(tpPixel);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti]->Clean(tpPixel);
	}
}

void CEnemy::Display(char *tpPixel) // �׷��� ǥ��
{
	if (STATE_DEAD == mState)
	{
		CCharacter::Clean(tpPixel);
	}
	else
	{
	*(tpPixel + mY*WIDTH + mX) = '#';
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti]->Display(tpPixel);

	}
	}
}

void CEnemy::Fire()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti]->Fire(this);
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

	if (tTemp - tDelay > 3000)
	{

		tEnemyBullet[mCurBulletIndex]->SetPositionForFire(this);
		tEnemyBullet[mCurBulletIndex]->SetIsLife(this);

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

float CEnemy::EnemyBulletX(int tBulletNum)
{
	return tEnemyBullet[tBulletNum]->GetX();

}

float CEnemy::EnemyBulletY(int tBulletNum)
{
	return tEnemyBullet[tBulletNum]->GetY();
}
