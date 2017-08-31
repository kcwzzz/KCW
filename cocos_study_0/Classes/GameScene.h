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
	CActor *mpActor = NULL;			//�ʱ�ȭ
	CEnemy *mpEnemy = NULL;


	CAniBox *mpAniBox = NULL;			//�ʱ�ȭ
	Size winSize;

	Vec2 mVec;
	int mState = 0;
	
	typedef void (GameScene::*CallFuncState)(void);

public:
	void CreateBackgroundLayer();
	void CreateUILayer();

	
	void onEnter();				//��ġ ��� On
	void onExit();				//��ġ ��� Off

	void CreateActor();
	void CreateEnemy();
	void update(float dt);
	void TestMoving(float f);

	
	//Actor
	void AttackBehavior();
	void MoveBehavior();
	void IdleBehavior();
	void DamagedActor();

	//Vec2 ColisionGeometry();
	//int ColisionGeometry();


public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

};