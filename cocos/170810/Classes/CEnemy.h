#pragma once

#include "cocos2d.h"

#include "CCharacter.h"

#include <vector>

USING_NS_CC;

using namespace std;

class CEnemyBullet;

typedef vector <CEnemyBullet *> CEnemyBulletVec;


class CEnemy :public CCharacter
{
private:

protected:
	CEnemyBulletVec mEnemyBulletVec;

	float mEnemyRegenTime;

public:

	virtual void Create();
	virtual void Build();
	virtual void Destroy();

	virtual void Update(float dt);
	virtual void SetScene(GameScene *tpScene);
	virtual void ReadyToFire(float f);

public:
	CEnemy();
	virtual ~CEnemy();
};