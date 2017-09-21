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

void CActor::Setup() // ���Ϳ� �Ѿ� �迭�� ��ġ �ʱ�ȭ
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
{	//Ű�� �Է����� �� ������ �
	//Ű�� �Է��ϸ� ����� �̵� �Ÿ��� �����Ͽ� �̵��ϰ� �Ѵ�. 
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

	//��
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
		//�߻�����
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
		//�߻�ƴ��� ����
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
