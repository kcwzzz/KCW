#pragma once
#include "Unit.h"

class CCharacter : public CUnit
{
protected :
	//CBullet tBullet[10];
	int mCurBulletIndex = 0;
	float mSpeedPower = 0;

public:
	CCharacter();
	~CCharacter();

	int GetX();
	int GetY();
	//void MoveWithInput(); //Á¶Á¤
	

};

