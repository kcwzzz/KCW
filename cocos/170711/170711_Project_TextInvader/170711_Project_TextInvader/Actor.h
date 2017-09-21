#pragma once
#include "ActorBullet.h"

class CActor
{
protected:
	int mX = 0;
	int mY = 0;
	
	int mSpeedPower = 0;
	int mDirX = 0;
	int mDirY = 0;

	int mCurBulletIndex = 0;

	CActorBullet tActorBullet[10];
	
public:
	CActor();
	~CActor();

	void Setup();
	void Move();
	void MoveWithInput(char tKey);
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
	int GetX();
};

