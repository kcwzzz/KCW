#ifndef __SCENE_0_SCENE_H__
#define __SCENE_0_SCENE_H__


#include "cocos2d.h"

USING_NS_CC;

class Scene_0 : public cocos2d::Scene
{

protected:
	cocos2d::Sprite *tTestMole_0;
	cocos2d::Sprite *tTestMole_1;
	cocos2d::Sprite *tTestMole_2;

	int tIsTrigger_0 = 0;
	int tIsTrigger_1 = 0;
	int tIsTrigger_2 = 0;

	int mScore = 0;
	Label *mpScore = NULL;

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(Scene_0);


	//void doClose(Object* pSender);

	void SetBackground();
	void SetMoles();

	void PrintScore();

	//	void MoveMoles(Object *pSender);
	void MovedSetPositonMoles();
	void UpMoveMoles();
	void DownMoveMoles();
	void DamagedMoles();

	void TestSeq();
	void SequenceMoles();

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void TestClock(float f);
};


#endif // __HELLOWORLD_SCENE_H__
