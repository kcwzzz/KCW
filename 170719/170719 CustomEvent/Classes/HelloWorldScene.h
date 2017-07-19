#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:

	EventListenerCustom *mpListenerCustom = NULL;

	Label *mplblTest = NULL;
	Sprite *mpSprite = NULL;
	
public:
	virtual void onEnter();
	virtual void onExit();

	void OnCustomEvent(EventCustom *Event);

	void OnClickBtnTest(Ref *pSender);
	//Cancelled ��ȭ�� ���ų� �ϴ� ��Ȳ

	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref *pSender);

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
