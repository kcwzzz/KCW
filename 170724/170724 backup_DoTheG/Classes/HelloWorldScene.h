#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:
	cocos2d::Sprite *tTestMole_0;
	cocos2d::Sprite *tTestMole_1;
	cocos2d::Sprite *tTestMole_2;
	
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
	

	void SetBackground();
	void SetMoles();

//	void MoveMoles(Object *pSender);
	void UpMoveMoles();
	void DownMoveMoles();
	void DamagedMoles();

	void TestSeq();

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif // __HELLOWORLD_SCENE_H__
