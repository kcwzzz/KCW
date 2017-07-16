#include "stdafx.h"
#include "Define.h"

#include "ActorBullet.h"
#include "Actor.h"

void CActorBullet :: Setup() //액터의 X,Y 좌표
{
	mX= WIDTH / 2;
	mY= HEIGHT - 1 - 1;
	mIsLife = false;
}

void CActorBullet::Move(CActor *tpActor) //조정
{
	if (true == mIsLife)
	{
		if (mY > 0)
		{
			mDirY = -1;
			mSpeedPower = 1;
			mY = mY + mDirY * mSpeedPower;
		}
		else
		{
			mIsLife = false;
			ReadyToFire(tpActor);
		}
	}
	else
	{
		mSpeedPower = 0;
	}
}

void CActorBullet::ReadyToFire(CActor *tpActor)
{

	mX = tpActor->GetX();
	mY = tpActor->GetY();
}

void CActorBullet::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + mY*WIDTH + mX) = '*';
}