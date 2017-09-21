#pragma once

#include "cocos2d.h"
#include "CBullet.h"

USING_NS_CC;

class CActor;

class CActorBullet :public CBullet
{	
private :

protected:
	CActor *mpActor = NULL;

	bool mIsLife = false;

public:
	virtual void Create();
	virtual void Build();
	virtual void Clear();

	virtual void ReadyToFire(Vec2 tVec);

public:
	CActorBullet();
	virtual ~CActorBullet();

	void Update(float dt);
};