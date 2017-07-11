#include "stdafx.h"
#include "Actor.h"
#include "Define.h"



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
	switch (tKey)
	{
	case 'Z':
	case 'z':
	{
		if (mX > 0)
		{
			mX = mX - 1;
		}
		else
		{
			mX = mX;
		}
		break;
	}

	//우
	case 'C':
	case 'c':
	{
		if (mX < WIDTH - 1)
		{
			mX = mX + 1;
		}
		else
		{
			mX = mX;
		}
		break;
	}

	case 'S':
	case 's':
	{
		if (mY < HEIGHT - 1)
		{
			mY = mY + 1;
		}
		else
		{
			mY = mY;
		}
		break;
	}

	case 'X':
	case 'x':
	{
		if (mY < HEIGHT - 1)
		{
			mY = mY + 1;
		}
		else
		{
			mY = mY;
		}
		break;
	}
	case 'M':
	case 'm':
	{
		//발사지점
		tActorBullet[mCurBulletIndex].ReadyToFire(this);
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
