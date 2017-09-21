#include "stdafx.h"
#include  <math.h>
#include "ActorBullet.h"
#include "Define.h"

void CActorBullet :: Setup() //�⺻ ��ġ ����
{
	mX= WIDTH / 2;
	mY= HEIGHT - 1 - 1;
	mIsLife = false;
}

void CActorBullet::ReadyToFire(CActor *tpActor) //�������� ����
{
	//switch (tKey)
	//{
	//case 'M':
	//case 'm':
	//{
		//�߻�����
		mX = tpActor->GetX();
		mY = tpActor->GetY() - 1;

		//�߻�ƴ��� ����

		mIsLife = true;
	//	break;
	//}
	//}	
}

void CActorBullet::Move(CEnemy *tpEnemy) //�Ѿ��� ������
//����źvoid CActorBullet::Move() //����
{
	if (true == mIsLife)
	{	/*
		if (mY > 0)
		{
		
			// ����ź
			mX = mX + mDirX*mSpeedPower;
			mY = mY + mDirY*mSpeedPower;

			
			//����ź
			mTargetX = tpEnemy->GetX();
			mTargetY = tpEnemy->GetY();

			mSpeedPower = 1;

			float tDistance = sqrtf((mTargetX - mX)*(mTargetX - mX) + (mTargetY - mY) * (mTargetY - mY));

			mDirX = (mTargetX - mX) / tDistance;
			mDirY = (mTargetY - mY) / tDistance;
			//����ź
						
			//������
			mDirY = -1;
			mSpeedPower = 1;
			float tPowerAngle = 30;
			float tRadius = 20;
			
			static float tTheta = 0;
			float tX = tRadius * cosf((3.14 / 180)*tTheta);

			mX = mX + tX;
			mY = mY + mDirY*mSpeedPower;

			tTheta = tTheta + tPowerAngle;
			//������
			*/
			/*
			//���� ��
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

void CActorBullet::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = '*';
}

/*

void CActorBullet::ReadyToFire(CActor *tpActor, CEnemy *tpEnemy)
{	
	
	����ź

	//��������
	//mX = tpActor->GetX();
	//mY = HEIGHT - 1 - 1;

	//Ÿ������
	mTargetX = tpEnemy->GetX() ;
	mTargetY = tpEnemy->GetY() ;

	mSpeedPower = 1;

	float tDistance = sqrtf((mTargetX - mX)*(mTargetX - mX) + (mTargetY - mY) * (mTargetY - mY));

	mDirX = (mTargetX - mX) / tDistance;
	mDirY = (mTargetY - mY) / tDistance;
	
}
*/
/*
void CActorBullet::Clean(char *tpPixel) // �׷��� Ŭ����
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = 0;
}
*/

