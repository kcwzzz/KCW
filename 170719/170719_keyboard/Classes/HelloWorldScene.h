#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:
	cocos2d::Sprite *mpSprActor = NULL;
	cocos2d::Vec2 mVecActor;

	cocos2d::Menu *menu = NULL;
	cocos2d::MenuItemImage *closeItem = NULL;
	cocos2d::MenuItemImage *mpBtnLt = NULL;
	cocos2d::MenuItemImage *mpBtnRt = NULL;

public:

	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	void OnClickBtnLt(Ref *pSender);
	void OnClickBtnRt(Ref *pSender);

	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref *pSender);

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
