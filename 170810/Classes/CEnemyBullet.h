#pragma once

#include "cocos2d.h"
#include "CBullet.h"

USING_NS_CC;

class CEnemyBullet :public CBullet
{	
private:

protected:

public:
	virtual void Create();


public:
	CEnemyBullet();
	virtual ~CEnemyBullet();

	virtual void BulletMove(float dt);
	virtual void BulletDestroy();
};