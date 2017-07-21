#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:

	int SlimeHP = 50;
	int ActorAP = 10;

	Label *mplblTitle = NULL;	
	Label *mplblTest = NULL;

	Action *mpMove = NULL;
	Action *mpEaseMove = NULL;
	Action *mpFadeOut = NULL;

	Sprite *mpSprSlime = NULL;
	Sprite *mpSprSlimeKing = NULL;

	Sprite *mpRock = NULL;
	Sprite *mpScissors = NULL;
	Sprite *mpPaper = NULL;


	EventListenerTouchOneByOne *mpListener = NULL;

public:

	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref *pSender);

	CREATE_FUNC(HelloWorld);

	void SlimeInfo();

	void DoSetupTitle();
	void BeginTitleAction();
	void CreateSlime();
	void OnCompleteEndTileAction();
	void DoSlimeInvisible();

	virtual void onEnter();
	virtual void onExit();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	void CreateSlimeKing();

	void RCPGame();

	//void SlimeAnimation();
};

#endif // __HELLOWORLD_SCENE_H__
