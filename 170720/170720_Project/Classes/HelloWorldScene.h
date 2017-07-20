#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:
	Label *mplblTitle = NULL;
	Label *mplblTest = NULL;

	Action *mpMove = NULL;
	Action *mpEaseMove = NULL;
	Action *mpFadeOut = NULL;

	Sprite *mpSprSlime = NULL;
	Sprite *mpSprSlimeKing = NULL;

	//EventListenerCustom *mpListenerCustom = NULL;
	EventListenerTouchOneByOne *mpListener = NULL;

//	Label *mplblTest = NULL;

public:

	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref *pSender);

	CREATE_FUNC(HelloWorld);


	void DoSetupTitle();
	void BeginTitleAction();
	void CreateSlime();
	void OnCompleteEndTileAction();
	void DoSlimeInvisible();

	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
};

#endif // __HELLOWORLD_SCENE_H__
