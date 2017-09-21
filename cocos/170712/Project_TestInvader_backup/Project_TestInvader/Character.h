#pragma once
#include "Unit.h"

class CCharacter : public CUnit
{
protected :
	int mCurBulletIndex = 0;

public:
	CCharacter();
	~CCharacter();

	virtual void MoveWithInput(); //Á¶Á¤
	int GetX();
	int GetY();
};