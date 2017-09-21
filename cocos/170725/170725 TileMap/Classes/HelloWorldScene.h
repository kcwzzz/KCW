#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class CGrid;

class HelloWorld : public cocos2d::Scene
{

protected:
	EventListenerTouchOneByOne *mpListener = NULL;

	Label *mplblTest = NULL;	

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);	

	CGrid *mpGrid = NULL;

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void SetBackground();
	void SetMoles();
};

#endif // __HELLOWORLD_SCENE_H__
