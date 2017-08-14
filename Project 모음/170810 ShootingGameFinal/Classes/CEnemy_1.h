#pragma once

#include "cocos2d.h"

#include "CEnemy.h"

#include <vector>

USING_NS_CC;

using namespace std;

class CEnemyBullet;

typedef vector <CEnemyBullet *> CEnemyBulletVec;


class CEnemy_1 :public CEnemy
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
	bool IsColision();

	bool GetIsLife();
	Rect BulletColisionBox();
	void SetActorBulletVec(CActorBulletVec tBulletVec);

public:
	CEnemy_1();
	virtual ~CEnemy_1();
};