#pragma once

#include "cocos2d.h"

#include "CEnemy.h"

USING_NS_CC;

class CEnemyBullet_1;

typedef vector <CEnemyBullet_1 *> CEnemyBulletVec_1;

class CActorBullet;

typedef vector <CActorBullet *> CActorBulletVec;


class CEnemy_2 :public CEnemy
{
private:

protected:
	CEnemyBulletVec_1 mEnemyBulletVec_1;

public:
	void Create();
	void Build();
	void Destroy();

	virtual void Update(float dt);
	virtual void SetScene(GameScene *tpScene);
	virtual void ReadyToFire(float f);
	virtual bool IsColision();
	virtual void doParticles();

	Rect BulletColisionBox();

	void SetActorBulletVec(CActorBulletVec tBulletVec);

};

