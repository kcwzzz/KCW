#pragma once

#include "cocos2d.h"
#include "CBullet.h"

USING_NS_CC;

class CEnemyBullet :public CBullet
{	
private:

protected:


	//Vec2 mVec_1;


public:
	virtual void Create();


public:
	CEnemyBullet();
	virtual ~CEnemyBullet();

	virtual void BulletMove(float dt);
	//virtual void BulletMove_1(float dt);
	virtual void BulletDestroy();

};