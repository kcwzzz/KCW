#pragma once

#include "cocos2d.h"
#include "CActor.h"
#include "CAniBox.h"
#include "CBackground.h"

USING_NS_CC;

class GameScene : public cocos2d::Scene
{

private:
	
protected:
	
	CBackground *mpBackground = NULL;
	ActionCamera *mpCamera = NULL;
	CActor *mpActor = NULL;			//초기화
	CAniBox *mpAniBox = NULL;			//초기화
	
	EventListenerTouchOneByOne *mpListener = NULL;		//터치 입력 리스너

	Label *mpGameOverLabel = NULL;

	//Vec2 mTouchPosition;
	int mTouchX = 0;
	int mTouchY = 0;
	float mDistance = 0.0f;

public:
	void CloseGame();			//게임 종료 버튼 : 이후에 제거할 듯
	//void OnCompleteAction();	//

	float CalcDistance();

	void onEnter();				//터치 기능 On
	void onExit();				//터치 기능 Off

	void GameOver();
	void CameraAction();
	void CreateActor();
	void CreateAnimation();
	//Vec2 GetTouchPosition();

	int GetTouchX();
	int GetTouchY();

	void CreateBackground();


	void update(float dt);
	float GetDistance();
	
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//화면 터치시 기능
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//화면 드래그시 기능
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//화면 터치 종료시 기능
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *Unused_event);	//터치 취소시 기능

public:

	//기본 화면 필요 기능 모음
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);

};