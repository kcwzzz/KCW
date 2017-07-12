#pragma once
class CActor;
class CEnemy;

class CActorBullet //: public CActor
{

protected:

	bool mIsLife = false;
	float mSpeedPower = 0;
	float mTargetX = 0;
	float mTargetY = 0;

public:
	void Fire(char tKey, CActor *tpActor); //조정
	void ReadyToFire(CActor *tpActor, CEnemy *tpEnemy);
	void Move(CEnemy *tpEnemy); //조정
	void SetIsLife(bool tIsLife);

};

