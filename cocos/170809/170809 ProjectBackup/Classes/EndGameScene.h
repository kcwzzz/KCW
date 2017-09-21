#pragma once

#include "cocos2d.h"

USING_NS_CC;

class EndGameScene : public cocos2d::Scene
{

protected:

	/*
	cocos2d::Sprite *tBackground_0;
	cocos2d::Sprite *tBackground_1;

	MenuItemFont *BtnStartGame = NULL;
	Menu *tStartMenu = NULL;

	cocos2d::Size winSize;
	cocos2d::Layer *mpLayerForWorld = NULL;
	cocos2d::Layer *mpLayerForUI = NULL;

	void CreateBackgroundParallax();
	void SceneChange(Object *pSender);
	*/
public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(EndGameScene);

};