#include "CCharacter.h"

 float CCharacter:: ImageHalfRadius()
{
	 mHalfRadius = mpUnitImage->getContentSize().width*0.5f;

	 return mHalfRadius;
}