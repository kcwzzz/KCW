#pragma once

#include "cocos2d.h"
#include "CBullet.h"

USING_NS_CC;

class CActor;
class CEnemy;

class CActorBullet :public CBullet
{	
private :

protected:
	CActor *mpActor = NULL;
	CEnemy *mpEnemy = NULL;

	bool mIsLife = false;

	float mDamage = 0;

public:
	virtual void Create();
	virtual void Build();
	virtual void Clear();

	virtual void ReadyToFire(Vec2 tVec);

public:
	CActorBullet();
	virtual ~CActorBullet();

	void BulletMove(float dt);
	void BulletDestroy();
	bool GetIsLife();

	
	bool IsColision();


};