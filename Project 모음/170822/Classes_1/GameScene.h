#pragma once

#include "cocos2d.h"

#include <vector>

using namespace std;

USING_NS_CC;

class CBackgroundLayer;
class CUILayer;
//class CGameSceneLayer;

class CActor;
class CAniBox;



class GameScene : public cocos2d::Scene
{

private:
	
protected:
	CUILayer *mpUILayer = NULL;
	CBackgroundLayer *mpBackgroundLayer = NULL;

	ActionCamera *mpCamera = NULL;
	CActor *mpActor = NULL;			//초기화
	CAniBox *mpAniBox = NULL;			//초기화
	Size winSize;
	

	Sprite *mpSprAni = NULL;
	Texture2D *mpTexture = NULL;
	Animation *mpAnimation = NULL;
	Animate *mpAnimate = NULL;
	Vec2 mVec;
	int mState = 0;

	typedef void (GameScene::*CallFuncState)(void);

	CallFuncState mArray[4] = { &GameScene::AniMoveUp,&GameScene::AniMoveDown,
		&GameScene::AniMoveLeft ,&GameScene::AniMoveRight };


public:
	void CreateBackgroundLayer();
	void CreateUILayer();

	
	void onEnter();				//터치 기능 On
	void onExit();				//터치 기능 Off

	void CreateActor();

	void update(float dt);
	


public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

};