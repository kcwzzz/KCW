#pragma once

#include "cocos2d.h"

#include <vector>

using namespace std;

USING_NS_CC;

class CBackgroundLayer;
class CUILayer;
class CActor;
class CAniBox;
class CEnemy;

class GameScene : public cocos2d::Scene
{
private:
	
protected:
	CUILayer *mpUILayer = NULL;
	CBackgroundLayer *mpBackgroundLayer = NULL;

	TMXTiledMap *mpTilemap = NULL;
	ActionCamera *mpCamera = NULL;

	CActor *mpActor = NULL;			//초기화
	Rect mRectActor;
	Rect mRectActorAttack;
		
	CEnemy *mpEnemy[10];
	Rect mRectEnemy[10];
	Rect mRectEnemyAttack[10];

	CAniBox *mpAniBox = NULL;			//초기화
	Size winSize;

	Vec2 mVec;
	int mState = 0;
	
	typedef void (GameScene::*CallFuncState)(void);

public:
	void CreateBackgroundLayer();
	void CreateUILayer();

	
	void onEnter();				//터치 기능 On
	void onExit();				//터치 기능 Off

	void CreateActor();
	void CreateEnemy();
	void update(float dt);
	void TestMoving(float f);

	
	//Actor
	void MoveBehavior();
	void IdleBehavior();
	void DamagedActor();

	void Colision();

public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

};