#include "stdafx.h"
#include "ActorBullet.h"
#include "Define.h"
#include "Actor.h"



void CActorBullet :: Setup() //액터의 X,Y 좌표
{
	mX= WIDTH / 2;
	mY= HEIGHT - 1 - 1;
	mIsLife = false;
}
void CActorBullet::Fire(char tKey, CActor *tpActor) //조정
{/*
	switch (tKey)
	{
	case 'M':
	case 'm':
	{
		//발사지점
		mX = tpActor->GetX();
		mY = HEIGHT - 1 - 1;	

		//발사됐는지 여부

		tIsLife = true;
		break;
	}
	}
	*/
}
void CActorBullet::Move() //조정
{
	if (true == mIsLife)
	{
		if (mY > 0)
		{
			mY = mY - 1;
		}
		else
		{
			mY = mY;
			mIsLife = false;
		}
	}
}

void CActorBullet::ReadyToFire(CActor *tpActor)
{
	mX = tpActor->GetX();
	mY = HEIGHT - 1 - 1;
}

void CActorBullet::SetIsLife(bool tIsLife)
{
	mIsLife = tIsLife;
}

void CActorBullet::Clean(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}

void CActorBullet::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + mY*WIDTH + mX) = '*';
}