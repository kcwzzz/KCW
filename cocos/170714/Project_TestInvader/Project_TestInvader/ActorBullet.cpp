#include "stdafx.h"
#include "Define.h"

#include "ActorBullet.h"
#include "Actor.h"

void CActorBullet :: Setup() //������ X,Y ��ǥ
{
	mX= WIDTH / 2;
	mY= HEIGHT - 1 - 1;
	mIsLife = false;
}

void CActorBullet::Move(CActor *tpActor) //����
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

void CActorBullet::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + mY*WIDTH + mX) = '*';
}