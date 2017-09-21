#pragma once

#include "cocos2d.h"
#include "CEnemyBullet.h"

USING_NS_CC;

class CEnemyBullet_1 :public CEnemyBullet
{	
private:

protected:

public:
	virtual void Create();


public:
	CEnemyBullet_1();
	virtual ~CEnemyBullet_1();

	virtual void BulletMove(float dt);
	virtual void BulletDestroy();
};