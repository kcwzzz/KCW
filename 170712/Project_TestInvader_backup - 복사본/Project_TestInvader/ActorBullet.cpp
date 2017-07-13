#include "stdafx.h"
#include  <math.h>
#include "ActorBullet.h"
#include "Define.h"

void CActorBullet :: Setup() //기본 위치 세팅
{
	mX= WIDTH / 2;
	mY= HEIGHT - 1 - 1;
	mIsLife = false;
}

void CActorBullet::ReadyToFire(CActor *tpActor) //시작지점 세팅
{
	//switch (tKey)
	//{
	//case 'M':
	//case 'm':
	//{
		//발사지점
		mX = tpActor->GetX();
		mY = tpActor->GetY() - 1;

		//발사됐는지 여부

		mIsLife = true;
	//	break;
	//}
	//}	
}

void CActorBullet::Move(CEnemy *tpEnemy) //총알의 움직임
//유도탄void CActorBullet::Move() //조정
{
	if (true == mIsLife)
	{	/*
		if (mY > 0)
		{
		
			// 유도탄
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
			/*
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
		*/
	}
}

void CActorBullet::Display(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = '*';
}

/*

void CActorBullet::ReadyToFire(CActor *tpActor, CEnemy *tpEnemy)
{	
	
	유도탄

	//시작지점
	//mX = tpActor->GetX();
	//mY = HEIGHT - 1 - 1;

	//타겟지점
	mTargetX = tpEnemy->GetX() ;
	mTargetY = tpEnemy->GetY() ;

	mSpeedPower = 1;

	float tDistance = sqrtf((mTargetX - mX)*(mTargetX - mX) + (mTargetY - mY) * (mTargetY - mY));

	mDirX = (mTargetX - mX) / tDistance;
	mDirY = (mTargetY - mY) / tDistance;
	
}
*/
/*
void CActorBullet::Clean(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = 0;
}
*/

