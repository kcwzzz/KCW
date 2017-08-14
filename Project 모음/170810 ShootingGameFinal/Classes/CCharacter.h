#pragma once

#include "cocos2d.h"
#include "CUnit.h"

USING_NS_CC;

class CCharacter :public CUnit
{	
private :

protected:

	float mCharacterHP = 0.0f;
	
	int mCurBulletIndex = 0;

	float mHalfRadius = 0.0;

public:
	virtual void ReadyToFire(float f);
	virtual void Destroy();
	virtual void Update(float dt);




	virtual float ImageHalfRadius();


};