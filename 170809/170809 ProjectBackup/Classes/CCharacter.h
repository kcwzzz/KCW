#pragma once

#include "cocos2d.h"
#include "CUnit.h"

USING_NS_CC;

class CCharacter :public CUnit
{	
private :

protected:

	float mCharacterHP = 0.0f;
	float mHalfRadius = 0.0;

public:
	virtual float ImageHalfRadius();


};