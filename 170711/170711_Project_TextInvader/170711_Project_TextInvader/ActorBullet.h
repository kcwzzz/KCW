#pragma once
class CActor;

class CActorBullet
{
protected:
	int mX = 0;
	int mY = 0;
	bool mBulletLife = false;
	
	int mSpeedPower = 0;
	int mDirX = 0;
	int mDirY = 0;

public:
	CActorBullet();
	~CActorBullet();

	void Setup();
	void MoveWithInput(char tKey, CActor *tpActor);
	void Move();
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
	void SetPositionForFire(CActor *tpActor);
	void SetIsLife(bool tIsLife);
};