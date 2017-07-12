#include "stdafx.h"
#include "Actor.h"
#include "Define.h"


void CActor ::Setup()
{
	mX = WIDTH / 2;
	mY = HEIGHT - 1;
}
void CActor::MoveWithInput(char tKey, CEnemy *tpEnemy)
{
	switch (tKey)
	{
	case 'Z':
	case 'z':
	{
		if (mX > 0)
		{
			mDirX = -1;
			mSpeedPower = 1;
			mX = mX + mDirX*mSpeedPower;
		}
		else
		{
			mSpeedPower = 0;
			mX = mX + mDirX*mSpeedPower;
		}
		break;
	}

	//우
	case 'C':
	case 'c':
	{
		if (mX < WIDTH - 1)
		{
			mDirX = 1;
			mSpeedPower = 1;
			mX = mX + mDirX*mSpeedPower;
		}
		else
		{
			mSpeedPower = 0;
			mX = mX + mDirX*mSpeedPower;
		}
		break;
	}

	case 'S':
	case 's':
	{
		if (mY < HEIGHT - 1)
		{
			mDirY = 1;
			mSpeedPower = 1;
			mY = mY + mDirY*mSpeedPower;
		}
		else
		{
			mDirY = 1;
			mSpeedPower = 0;
			mY = mY + mDirY*mSpeedPower;
		}
		break;
	}

	case 'X':
	case 'x':
	{
		if (mY < HEIGHT - 1)
		{
			mDirY = -1;
			mSpeedPower = 1;
			mY = mY + mDirY*mSpeedPower;
		}
		else
		{
			mDirY = -1;
			mSpeedPower = 0;
			mY = mY + mDirY*mSpeedPower;
		}
		break;
	}
	case 'M':
	case 'm':
	{
		//발사지점
		tActorBullet[mCurBulletIndex].ReadyToFire(this, tpEnemy);
		tActorBullet[mCurBulletIndex].SetIsLife(true);

		if (mCurBulletIndex < 10 - 1)
		{
			mCurBulletIndex++;
		}
		else
		{
			mCurBulletIndex = 0;
		}
		//발사됐는지 여부
		break;
	}
	}
}
void CActor::Move(CEnemy *tpEnemy)
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti].Move(tpEnemy);
	}
}
void CActor::Clean(char *tpPixel)
{/*
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti].Clean(tpPixel);
	}
	*/
}
void CActor::Display(char *tpPixel)
{
	/*
	*(tpPixel + (int)mY*WIDTH + (int)mX) = 'A';

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti].Display(tpPixel);	
	}
	*/
}
int CActor::GetX()
{
	return (int)mX;
}

int CActor::GetY()
{
	return (int)mY;
}
