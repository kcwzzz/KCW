#pragma once

#include "cocos2d.h"
#include "CActor.h"

USING_NS_CC;

class GameScene : public cocos2d::Scene
{

private:


protected:

	cocos2d::Sprite *mpSpriteA;	//��� �̹���1
	cocos2d::Sprite *mpSpriteB; //��� �̹���2 -> 1�̹����� ���� �����ؼ� ��뿹��

	Vec2 mVecA;					//��� �̹���1�� ��ġ ��
	Vec2 mVecB;					//��� �̹���2�� ��ġ ��

	EventListenerTouchOneByOne *mpListener = NULL;		//��ġ �Է� ������
	
	CActor *mActor;
	cocos2d::Sprite *mpActor;		//���߿��� CUnit Ŭ������ ��������
	Vec2 mVecActor;					
	int mActorSpeed = 0;



public:
	void CloseGame();			//���� ���� ��ư : ���Ŀ� ������ ��
	void OnCompleteAction();	//
	void TitleBackGround();		//
	//void CreateActor(CActor * tpActor);
	void CreateActor();

	void onEnter();				//��ġ ��� On
	void onExit();				//��ġ ��� Off

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� ��ġ�� ���
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� �巡�׽� ���
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� ��ġ ����� ���
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *Unused_event);	//��ġ ��ҽ� ���

	void update(float dt);

	//�⺻ ȭ�� �ʿ� ��� ����
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);

};