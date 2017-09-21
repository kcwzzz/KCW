#pragma once

#include "cocos2d.h"

#include "CCharacter.h"

#include <vector>

USING_NS_CC;

using namespace std;

class CActorBullet;

//typedef vector <CActorBullet *> CActorBulletVec;

class CActor :public CCharacter
{	
private :


protected:	
	CActorBullet *mActorBullet = NULL;
	//CActorBullet *mActorBullet[10];
	//CActorBulletVec mActorBulletVec;



public:	
	virtual void Create();
	virtual void Build();
	virtual void Clear();

	virtual void Update(float dt);
	void SetScene(GameScene *tpScene);
	
public:
	CActor();
	virtual ~CActor();

};