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
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시

	void MoveWithInput(char tKey, CEnemy *tpEnemy); //조정
	void Move(CEnemy *tpEnemy);
	int GetX();
	int GetY();
};

