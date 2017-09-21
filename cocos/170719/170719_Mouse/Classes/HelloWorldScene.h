#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:

	EventListenerMouse *mpListenerMouse = NULL;

	Label *mplblTest = NULL;
	Sprite *mpSprite = NULL;
	
public:
	virtual void onEnter();
	virtual void onExit();

	virtual void onMouseDown(cocos2d::Event *event);
	virtual void onMouseUp(cocos2d::Event *event);
	virtual void onMouseMove(cocos2d::Event *event);
	virtual void onMouseScroll(cocos2d::Event *event);

	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref *pSender);

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
