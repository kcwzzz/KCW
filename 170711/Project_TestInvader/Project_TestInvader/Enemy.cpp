#include "stdafx.h"
#include "Enemy.h"
#include "Define.h"


void CEnemy::Setup() //������ X,Y ��ǥ
{
	mDir = DIR_LEFT;
	mX = WIDTH / 2;
	mX = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Setup();
	}
}
void CEnemy::MoveWithInput() //����
{

	if (DIR_RIGHT == mDir)
	{
		if (mX< WIDTH - 1)
		{
			mX = mX + 15;
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
			mX = mX - 15;
		}
		else
		{
			mDir = DIR_RIGHT;
		}
	}
}
void CEnemy::Clean(char *tpPixel) // �׷��� Ŭ����
{
	*(tpPixel + mY*WIDTH + mX) = 0;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Clean(tpPixel);
	}
}
void CEnemy::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + mY*WIDTH + mX) = '#';
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Display(tpPixel);
	}
}
int CEnemy::GetX()
{
	return mX;
}
int CEnemy::GetY()
{
	return mY;
}

void CEnemy::Fire()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tEnemyBullet[ti].Fire(this);
	}
}