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

	int mCurBulletIndex = 0;
	
public:	
	virtual void Create();
	virtual void Build();
	virtual void Clear();

	virtual void Update(float dt);
	void SetScene(GameScene *tpScene);
	void ReadyToFire(float f);

	void Destroy();

	
public:
	CActor();
	virtual ~CActor();
};