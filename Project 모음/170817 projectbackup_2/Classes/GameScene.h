#pragma once

#include "cocos2d.h"

#include <vector>

using namespace std;

USING_NS_CC;

class CBackgroundLayer;
class CUILayer;
class CGameSceneLayer;

class CActor;
class CAniBox;



class GameScene : public cocos2d::Scene
{

private:
	
protected:
	CUILayer *mpUILayer = NULL;
	CBackgroundLayer *mpBackgroundLayer = NULL;
	CGameSceneLayer *mpGameSceneLayer = NULL;


	ActionCamera *mpCamera = NULL;
	CActor *mpActor = NULL;			//초기화
	CAniBox *mpAniBox = NULL;			//초기화

	EventListenerTouchAllAtOnce *mpListener = NULL;		//터치 입력 리스너

	Label *mpGameOverLabel = NULL;

	Vec2 mTouchPosition;

	float mDistance = 0.0f;
	Size winSize;

public:
	void CreateBackgroundLayer();
	void CreateUILayer();
	void CreateGameSceneLayer();

	float CalcDistance();

	void onEnter();				//터치 기능 On
	void onExit();				//터치 기능 Off

	void GameOver();
	void CameraAction();
	void CreateActor();
	void CreateAnimation();
	Vec2 GetTouchPosition();



	void update(float dt);
	float GetDistance();
	
	virtual void onTouchesBegan(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesMoved(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesEnded(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesCancelled(const vector<Touch*>&touches, Event* unused_event);

public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

};