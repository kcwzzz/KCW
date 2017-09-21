#pragma once
#include "Unit.h"

class CCharacter : public CUnit
{
protected :
	//CBullet tBullet[10];
	int mCurBulletIndex = 0;

public:
	CCharacter();
	~CCharacter();

	virtual void MoveWithInput() = 0; //Á¶Á¤
	int GetX();
	int GetY();
};