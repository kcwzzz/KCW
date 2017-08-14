#pragma once

#include "cocos2d.h"
#include "CActor.h"
#include "CAniBox.h"


USING_NS_CC;

class GameScene : public cocos2d::Scene
{

private:
	
protected:
	cocos2d::Sprite *mpSpriteA;	//��� �̹���1
	cocos2d::Sprite *mpSpriteB; //��� �̹���2 -> 1�̹����� ���� �����ؼ� ��뿹��

	Vec2 mVecBackgroundA;					//��� �̹���1�� ��ġ ��
	Vec2 mVecBackgroundB;					//��� �̹���2�� ��ġ ��

	ActionCamera *mpCamera = NULL;
	CActor *mpActor = NULL;			//�ʱ�ȭ
	CAniBox *mpAniBox = NULL;			//�ʱ�ȭ



	EventListenerTouchOneByOne *mpListener = NULL;		//��ġ �Է� ������

	Label *mpGameOverLabel = NULL;

	Vec2 mTouchPosition;

	float mDistance = 0.0f;

public:
	void CloseGame();			//���� ���� ��ư : ���Ŀ� ������ ��
	void OnCompleteAction();	//
	void TitleBackGround();		//
	float CalcDistance();


	void onEnter();				//��ġ ��� On
	void onExit();				//��ġ ��� Off

	void GameOver();
	void CameraAction();
	void CreateActor();
	void CreateAnimation();

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