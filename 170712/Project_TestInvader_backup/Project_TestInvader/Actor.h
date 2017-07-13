#pragma once
#include "ActorBullet.h"
#include "Character.h"

//class CActorBullet;

class CActor : public CCharacter
{
protected:
	CActorBullet tActorBullet[10];
	
	float mTargetX = 0;
	float mTargetY = 0;

public:

	void Setup();
	void MoveWithInput(char tKey, CEnemy *tpEnemy);	
	void Move(CEnemy *tpEnemy);

	void Display(char *tpPixel);
};

