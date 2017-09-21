#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:

	Label *mplblTitle = NULL;

	Action *mpMove = NULL;
	Action *mpEaseMove = NULL;
	Action *mpFadeOut = NULL;

	Sprite *mpSprSlime = NULL;
	Sprite *mpSprSlimeKing = NULL;

	EventListenerCustom *mpListenerCustom = NULL;


public:

	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref *pSender);

	CREATE_FUNC(HelloWorld);

	//virtual void onEnter();
	//virtual void onExit();

	//void OnCustomEvent(EventCustom *Event);

	void DoSetupTitle();
	void DoTitleAction();
	void DoTitleHide();
	void DoSetupSlime();
};

#endif // __HELLOWORLD_SCENE_H__
