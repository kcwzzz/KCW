#pragma once

#include "cocos2d.h"
#include "CBullet.h"

USING_NS_CC;

class CActorBullet :public CBullet
{	
private :

protected:

public:
	virtual void Create();


public:
	CActorBullet();
	virtual ~CActorBullet();

	virtual void BulletMove(float dt);
	virtual void BulletDestroy();
	//bool IsColision();

};