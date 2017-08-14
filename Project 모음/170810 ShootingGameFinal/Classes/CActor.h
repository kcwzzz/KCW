#pragma once

#include "cocos2d.h"

#include "CCharacter.h"

#include <vector>

USING_NS_CC;

using namespace std;

class CActorBullet;
class CEnemyBullet;

typedef vector <CActorBullet *> CActorBulletVec;
typedef vector <CEnemyBullet *> CEnemyBulletVec;

class CActor :public CCharacter
{	
private :

protected:	
	CActorBulletVec mActorBulletVec;
	CEnemyBulletVec mEnemyBulletVec;

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

	virtual Rect ActorColisionBox();
	CActorBulletVec GetActorBullets();
	

	Rect BulletColisionBox();


	CEnemyBulletVec GetEnemyBullets();
	bool IsColision();
	void doParticles();

	void SetEnemyBulletVec(CEnemyBulletVec tBulletVec);

public:
	CActor();
	virtual ~CActor();
};