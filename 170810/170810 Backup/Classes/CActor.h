#pragma once

#include "cocos2d.h"

#include "CCharacter.h"

#include <vector>

USING_NS_CC;

using namespace std;

class CActorBullet;

typedef vector <CActorBullet *> CActorBulletVec;

class CActor :public CCharacter
{	
private :

protected:	
	CActorBulletVec mActorBulletVec;
	CActorBullet *mActorBullet;
	
public:	
	virtual void Create();
	virtual void Build();
	virtual void Clear();

	virtual void Update(float dt);
	virtual void SetScene(GameScene *tpScene);
	virtual void ReadyToFire(float f);
	virtual void Destroy();

	virtual void BulletColision();

	CActorBulletVec GetActorBullets();
	
public:
	CActor();
	virtual ~CActor();
};