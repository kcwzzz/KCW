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
	CActor *mpActor = NULL;			//�ʱ�ȭ
	CAniBox *mpAniBox = NULL;			//�ʱ�ȭ
	
	EventListenerTouchOneByOne *mpListener = NULL;		//��ġ �Է� ������

	Label *mpGameOverLabel = NULL;

	//Vec2 mTouchPosition;
	int mTouchX = 0;
	int mTouchY = 0;
	float mDistance = 0.0f;

public:
	void CloseGame();			//���� ���� ��ư : ���Ŀ� ������ ��
	//void OnCompleteAction();	//

	float CalcDistance();

	void onEnter();				//��ġ ��� On
	void onExit();				//��ġ ��� Off

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
	
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� ��ġ�� ���
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� �巡�׽� ���
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� ��ġ ����� ���
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *Unused_event);	//��ġ ��ҽ� ���

public:

	//�⺻ ȭ�� �ʿ� ��� ����
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);

};