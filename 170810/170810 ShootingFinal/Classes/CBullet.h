#pragma once

#include "cocos2d.h"
#include "CUnit.h"

USING_NS_CC;

class CActor;
class CEnemy;

class CBullet :public CUnit
{	
private :

protected:
	CActor *mpActor = NULL;
	CEnemy *mpEnemy = NULL;

	bool mIsLife = false;
	float mDamage = 0.0f;

public:
	CBullet();
	~CBullet();

	virtual void ReadyToFire(Vec2 tVec);
	virtual void BulletMove(float dt);
	virtual void BulletDestroy();
	virtual bool GetIsLife();

	virtual Rect BulletColisionBox();



};