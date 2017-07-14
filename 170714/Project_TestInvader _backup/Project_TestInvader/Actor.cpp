#include "stdafx.h"
#include "Define.h"

#include "Actor.h"
#include "ActorBullet.h"

CActor::CActor()
{
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti] = new CActorBullet();
	}
}

CActor::~CActor()
{
	int  ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		if (NULL != tActorBullet[ti])
		{
			delete tActorBullet[ti];
			tActorBullet[ti] = NULL;
		}
	}
}

void CActor::Setup() // 액터와 총알 배열의 위치 초기화
{
	mX = WIDTH / 2;
	mY = HEIGHT - 1;

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
//		tActorBullet[ti].Setup();

		tActorBullet[ti]->Setup();
	}
}
void CActor::MoveWithInput(char tKey)
{	//키를 입력했을 때 액터의 운동
	//키를 입력하면 방향과 이동 거리를 변경하여 이동하게 한다. 
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
		tActorBullet[mCurBulletIndex]->ReadyToFire(this);
		tActorBullet[mCurBulletIndex]->SetIsLife(true);

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
void CActor::Move(CActor *tpActor)
{
	//
	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti]->Move(tpActor);
	}
}
void CActor::Clean(char *tpPixel)
{
	//*(tpPixel + mY*WIDTH + mX) = 0;
	CCharacter::Clean(tpPixel);

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti]->Clean(tpPixel);
	}
}
void CActor::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 'A';

	int ti = 0;
	for (ti = 0; ti < 10; ti++)
	{
		tActorBullet[ti]->Display(tpPixel);
	}
}
