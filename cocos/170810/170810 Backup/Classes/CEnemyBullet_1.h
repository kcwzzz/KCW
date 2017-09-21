#pragma once

#include "cocos2d.h"
#include "CEnemyBullet.h"

USING_NS_CC;

class CEnemyBullet_1 :public CEnemyBullet
{	
private:

protected:
	Vec2  mVec_0;
	Vec2  mVec_1;
	Vec2  mVec_2;
	Vec2  mVec_3;
	Vec2  mVec_4;

public:
	virtual void Create();


public:
	CEnemyBullet_1();
	virtual ~CEnemyBullet_1();

	virtual void BulletMove(float dt);
	virtual void BulletDestroy();
};