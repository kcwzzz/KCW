#pragma once
//#include "Character.h"
//#include "ActorBullet.h"

class CActorBullet

class CActor : public CCharacter
{
protected:
	CActorBullet *tpActorBullet[10];

public:
	void Setup(); //액터의 X,Y 좌표
	void MoveWithInput(char tKey); //조정
	void Move(CActor *tpActor);
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
};

