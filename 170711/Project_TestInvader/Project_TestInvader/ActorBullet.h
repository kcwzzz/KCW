#pragma once
#include "Bullet.h"

class CActor;

class CActorBullet : public CBullet
{

protected:

	/*
	int mX = 0;
	int mY = 0;
	bool mIsLife = false;

	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;
	*/

public:
	void Setup(); //������ X,Y ��ǥ
	void ReadyToFire(CActor *tpActor);
	void Move(); //����
	//void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	//void SetIsLife(bool tIsLife);

};

