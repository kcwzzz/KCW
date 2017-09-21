#include "stdafx.h"
#include "Actor.h"
#include "Define.h"

CActor::CActor()
{
	mX = 0;
	mY = 0;
}
CActor::~CActor()
{

}

void CActor::Setup()
{
	mX = WIDTH / 2;
	mY = HEIGHT - 1;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti].Setup();
	}

}
void CActor::MoveWithInput(char tKey)
{
	//��
	switch (tKey)
	{
	case 'Z':
	case 'z':
	{
		if (mX > 0)
		{
			mSpeedPower = 1;
			mDirX = -1;

			mX = mX + mDirX* mSpeedPower;
		}

	}
	break;

	//��
	case 'X':
	case 'x':
	{
		if (mX < WIDTH - 1)
		{
			mSpeedPower = 1;
			mDirX = 1;
			mX = mX + mDirX* mSpeedPower;
		}

	}
	break;

	case 'M':
	case 'm':
	{
		//�߻�����				
		tActorBullet[mCurBulletIndex].SetPositionForFire(this);

		//�߻�ƴ��� ����		
		tActorBullet[mCurBulletIndex].SetIsLife(true);

		if (mCurBulletIndex < 10 - 1)
		{
			mCurBulletIndex++;
		}
		else
		{
			mCurBulletIndex = 0;
		}
	}
	break;
	}
}

void CActor::Move()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti].Move();
	}
}
void CActor::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti].Clean(tpPixel);
	}
}
void CActor::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 'A';
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti].Display(tpPixel);
	}
}
int CActor::GetX()
{
	return mX;
}