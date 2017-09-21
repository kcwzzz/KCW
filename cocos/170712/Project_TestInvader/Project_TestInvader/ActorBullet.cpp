#include "stdafx.h"
#include  <math.h>
#include "ActorBullet.h"
#include "Define.h"
#include "Actor.h"
#include "Enemy.h"
#include "Unit.h"

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

void CActorBullet::Move(CEnemy *tpEnemy) //조정
//유도탄void CActorBullet::Move() //조정
{
	if (true == mIsLife)
	{
		if (mY > 0)
		{
			/* 유도탄
			mX = mX + mDirX*mSpeedPower;
			mY = mY + mDirY*mSpeedPower;

			
			//유도탄
			mTargetX = tpEnemy->GetX();
			mTargetY = tpEnemy->GetY();

			mSpeedPower = 1;

			float tDistance = sqrtf((mTargetX - mX)*(mTargetX - mX) + (mTargetY - mY) * (mTargetY - mY));

			mDirX = (mTargetX - mX) / tDistance;
			mDirY = (mTargetY - mY) / tDistance;
			//유도탄
			*/

			/*
			//사인파
			mDirY = -1;
			mSpeedPower = 1;
			float tPowerAngle = 30;
			float tRadius = 20;
			
			static float tTheta = 0;
			float tX = tRadius * cosf((3.14 / 180)*tTheta);

			mX = mX + tX;
			mY = mY + mDirY*mSpeedPower;

			tTheta = tTheta + tPowerAngle;
			//사인파
			*/
			
			//원형 파
			float tPowerAngle = 45;
			float tRadius = 8;

			static float tTheta = 0;
			float tXVelocity = tRadius * cosf((3.14 / 180) * tTheta);
			float tYVelocity = tRadius * sinf((3.14 / 180) * tTheta);

			mX = 40 + tXVelocity;
			mY = 12 + tYVelocity;

			tTheta = tTheta + tPowerAngle;
		}
		else
		{
			mSpeedPower = 0;
			mX = mX + mDirX*mSpeedPower;
			mY = mY + mDirY*mSpeedPower;
		}
	}
}

void CActorBullet::ReadyToFire(CActor *tpActor, CEnemy *tpEnemy)
{	//시작지점
	mX = tpActor->GetX();
	mY = HEIGHT - 1 - 1;

	//타겟지점
	mTargetX = tpEnemy->GetX() ;
	mTargetY = tpEnemy->GetY() ;

	mSpeedPower = 1;

	float tDistance = sqrtf((mTargetX - mX)*(mTargetX - mX) + (mTargetY - mY) * (mTargetY - mY));

	mDirX = (mTargetX - mX) / tDistance;
	mDirY = (mTargetY - mY) / tDistance;
}

void CActorBullet::SetIsLife(bool tIsLife)
{
	mIsLife = tIsLife;
}

void CActorBullet::Clean(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = 0;
}

void CActorBullet::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = '*';
}