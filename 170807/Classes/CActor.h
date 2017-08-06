#pragma once

#include "cocos2d.h"
#include "CCharacter.h"

USING_NS_CC;

class CActor :public CCharacter
{	
private :

protected:

public:
	CActor();
	virtual ~CActor();
	virtual void Setup();
};