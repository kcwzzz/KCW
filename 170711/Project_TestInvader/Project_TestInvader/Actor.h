#pragma once
#include "Character.h"
#include "ActorBullet.h"

class CActor : public CCharacter
{
protected:
/*
	int mX = 0;
	int mY = 0;
	int mCurBulletIndex = 0;
	int mSpeedPower = 0;
	int mDirX = 0;
	int mDirY = 0;
	*/
	CActorBullet tActorBullet[10];

public:
	void Setup(); //액터의 X,Y 좌표
	void MoveWithInput(char tKey); //조정
	void Move();
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
};

