#pragma once
#include "ActorBullet.h"
class CActor
{
protected:
	int mX = 0;
	int mY = 0;

	CActorBullet tActorBullet[10];

	int mCurBulletIndex = 0;
	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;

public:
	void Setup(); //������ X,Y ��ǥ
	void MoveWithInput(char tKey); //����
	void Move();
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��

	int GetX();
};

