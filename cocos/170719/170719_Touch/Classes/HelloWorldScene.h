#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:

	EventListenerTouchOneByOne *mpListener = NULL;

	Label *mplblTest = NULL;
	Sprite *mpSprite = NULL;
	
public:
	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	//Cancelled 전화가 오거나 하는 상황


	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref *pSender);

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
