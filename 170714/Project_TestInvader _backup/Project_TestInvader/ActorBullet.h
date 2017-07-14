#pragma once
#include "Bullet.h"

class CActor;

class CActorBullet : public CBullet
{

protected:

public:
	void Setup(); //액터의 X,Y 좌표
	void ReadyToFire(CActor *tpActor);
	void Move(CActor *tpActor); //조정
	void Display(char *tpPixel); // 그래픽 표시
};

