#include "stdafx.h"
#include "ActorBullet.h"
#include "Actor.h"
#include "Define.h"

CActorBullet::CActorBullet()
{

}
CActorBullet::~CActorBullet()
{

}
void CActorBullet::Setup()
{
	mX = WIDTH / 2;
	mY = HEIGHT - 1 - 1;
	mBulletLife = false;
}
void CActorBullet::MoveWithInput(char tKey, CActor *tpActor)
{
}
void CActorBullet::Move()
{
	if (true == mBulletLife)
	{
		if (mY > 0)
		{
			mSpeedPower = 1;
			mDirY = -1;

			mY = mY +mDirY * mSpeedPower;
		}
	}
}
void CActorBullet::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void CActorBullet::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = '*';
}

void CActorBullet::SetPositionForFire(CActor *tpActor)
{
	mX = tpActor->GetX();
	mY = HEIGHT - 1 - 1;
}

void CActorBullet::SetIsLife(bool tBulletLife)
{
	mBulletLife = tBulletLife;
}