#pragma once
class CActor;
class CEnemy;

class CActorBullet : public CActor
{

protected:

	bool mIsLife = false;

	float mDirX = 0;
	float mDirY = 0;
	float mSpeedPower = 0;

	float mTargetX = 0;
	float mTargetY = 0;

public:

	void Fire(char tKey, CActor *tpActor); //����
	void ReadyToFire(CActor *tpActor, CEnemy *tpEnemy);
	void Move(CEnemy *tpEnemy); //����

	void SetIsLife(bool tIsLife);

};

