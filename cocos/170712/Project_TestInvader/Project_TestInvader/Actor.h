#pragma once
#include "ActorBullet.h"

#include "Unit.h"

class CActor : public CUnit
{
protected:
	CActorBullet tActorBullet[10];
	
	int mCurBulletIndex = 0;
	float mSpeedPower = 0;

	float mTargetX = 0;
	float mTargetY = 0;

public:
	void Setup(); 
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��

	void MoveWithInput(char tKey, CEnemy *tpEnemy); //����
	void Move(CEnemy *tpEnemy);
	int GetX();
	int GetY();
};

