#pragma once

#include "cocos2d.h"
#include "CActor.h"
#include "CEnemy.h"
#include "CEnemy_1.h"
#include "CEnemy_2.h"
#include "CActorBullet.h"
#include <vector>

USING_NS_CC;

typedef vector <CEnemy_1 *> CEnemy_1_Vec;

class GameScene : public cocos2d::Scene
{

private:
	
protected:
	cocos2d::Sprite *mpSpriteA;	//��� �̹���1
	cocos2d::Sprite *mpSpriteB; //��� �̹���2 -> 1�̹����� ���� �����ؼ� ��뿹��

	Vec2 mVecBackgroundA;					//��� �̹���1�� ��ġ ��
	Vec2 mVecBackgroundB;					//��� �̹���2�� ��ġ ��

	EventListenerTouchOneByOne *mpListener = NULL;		//��ġ �Է� ������
	
	CActor *mpActor = NULL;			//�ʱ�ȭ
	float mDistance = 0;			//��ġ - Actor �� �Ÿ�
	Vec2 mTouchPosition;			//��ġ�� ��ġ�� ��ǥ

	CEnemy *mpEnemy[10];
	CEnemy_1 *mpEnemy_1[10];
	CEnemy_2 *mpEnemy_2[10];

	Label *mpGameOverLabel = NULL;

	int mScore = 0;
	Label *mpScore = NULL;


public:
	void CloseGame();			//���� ���� ��ư : ���Ŀ� ������ ��
	void OnCompleteAction();	//
	void TitleBackGround();		//

	void PrintScore();
	void SetScore(int tScore);

	void CreateActor();
	void CreateEnemy(float f);
	void CreateEnemy_1(float f);
	void CreateEnemy_2(float f);

	void ReadyToFire_Actor(float f);
	void ReadyToFire_Enemy(float f);

	void onEnter();				//��ġ ��� On
	void onExit();				//��ġ ��� Off

	float CalcDistance();

	Vec2 GetTouchVec();
	float GetDistance();

	void GameOver();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� ��ġ�� ���
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� �巡�׽� ���
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *Unused_event);		//ȭ�� ��ġ ����� ���
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *Unused_event);	//��ġ ��ҽ� ���

	void update(float dt);

	void SceneChange(Object *pSender);


public:

	//�⺻ ȭ�� �ʿ� ��� ����
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);

};