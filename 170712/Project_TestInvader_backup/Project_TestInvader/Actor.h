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

	void MoveWithInput(char tKey, CEnemy *tpEnemy); //Á¶Á¤
	void Move(CEnemy *tpEnemy);
	int GetX();
};

