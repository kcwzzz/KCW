#pragma once

#include "cocos2d.h"
#include "CActor.h"
#include "CEnemy.h"

USING_NS_CC;

class GameScene : public cocos2d::Scene
{

private:
	
protected:

	cocos2d::Sprite *mpSpriteA;	//배경 이미지1
	cocos2d::Sprite *mpSpriteB; //배경 이미지2 -> 1이미지를 상하 반전해서 사용예정

	Vec2 mVecBackgroundA;					//배경 이미지1의 위치 값
	Vec2 mVecBackgroundB;					//배경 이미지2의 위치 값

	EventListenerTouchOneByOne *mpListener = NULL;		//터치 입력 리스너
	
	CActor *mpActor = NULL;			//초기화
	float mDistance = 0;			//터치 - Actor 간 거리
	Vec2 mTouchPosition;			//터치한 위치의 좌표

	CEnemy *mpEnemy = NULL;


public:
	void CloseGame();			//게임 종료 버튼 : 이후에 제거할 듯
	void OnCompleteAction();	//
	void TitleBackGround();		//

	void CreateActor();
	void CreateEnemy(int EnemyCount);


	void onEnter();				//터치 기능 On
	void onExit();				//터치 기능 Off

	float CalcDistance();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//화면 터치시 기능
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//화면 드래그시 기능
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//화면 터치 종료시 기능
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *Unused_event);	//터치 취소시 기능

	void update(float dt);

public:

	//기본 화면 필요 기능 모음
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);

};