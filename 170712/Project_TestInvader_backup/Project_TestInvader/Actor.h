#pragma once
#include "ActorBullet.h"
//#include "Unit.h"
#include "Character.h"

class CActor : public CCharacter
{
protected:
//	CActorBullet tActorBullet[10];

	float mTargetX = 0;
	float mTargetY = 0;

public:

	void CActor::Setup();
	void MoveWithInput(char tKey, CEnemy *tpEnemy); //Á¶Á¤
	void Move(CEnemy *tpEnemy);
	int GetX();
};

