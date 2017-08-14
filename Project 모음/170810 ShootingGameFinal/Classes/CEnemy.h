#pragma once

#include "cocos2d.h"

#include "CCharacter.h"

#include <vector>

USING_NS_CC;

using namespace std;

class CEnemyBullet;

typedef vector <CEnemyBullet *> CEnemyBulletVec;

class CActorBullet;

typedef vector <CActorBullet *> CActorBulletVec;


class CEnemy :public CCharacter
{
private:

protected:
	CEnemyBulletVec mEnemyBulletVec;
	CActorBulletVec mActorBulletVec;

	ParticleSystem *mpParticleSys;

	int mScore = 0;


public:

	virtual void Create();
	virtual void Build();
	virtual void Destroy();

	virtual void Update(float dt);
	virtual void SetScene(GameScene *tpScene);
	virtual void ReadyToFire(float f);
	virtual bool IsColision();
	virtual void doParticles();

	Rect BulletColisionBox();

	void SetActorBulletVec(CActorBulletVec tBulletVec);
	CEnemyBulletVec GetEnemyBullets();

public:
	CEnemy();
	virtual ~CEnemy();
};