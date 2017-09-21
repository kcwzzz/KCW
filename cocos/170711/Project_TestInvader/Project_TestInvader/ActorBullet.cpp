#include "stdafx.h"
#include "ActorBullet.h"
#include "Define.h"
#include "Actor.h"



void CActorBullet :: Setup() //������ X,Y ��ǥ
{
	mX= WIDTH / 2;
	mY= HEIGHT - 1 - 1;
	mIsLife = false;
}

void CActorBullet::Move() //����
{
	if (true == mIsLife)
	{
		if (mY > 0)
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
	}
}

void CActorBullet::ReadyToFire(CActor *tpActor)
{
	mX = tpActor->GetX();
	mY = HEIGHT - 1 - 1;
}
/*
void CActorBullet::SetIsLife(bool tIsLife)
{
	mIsLife = tIsLife;
}
*/
/*
void CActorBullet::Clean(char *tpPixel) // �׷��� Ŭ����
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
*/

void CActorBullet::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + mY*WIDTH + mX) = '*';
}