#pragma once

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public cocos2d::Scene
{

protected:

	/*
	cocos2d::Sprite *mpSpriteA;
	cocos2d::Sprite *mpSpriteB;

	MenuItemFont *StartGame = NULL;
	Menu *tStartMenu = NULL;

	cocos2d::Size winSize;
	cocos2d::Layer *mpLayerForWorld = NULL;
	cocos2d::Layer *mpLayerForUI = NULL;

	void CreateBackgroundParallax();
	void SceneChange(Object *pSender);
	*/

	cocos2d::Sprite *mpSpriteA;
	cocos2d::Sprite *mpSpriteB;


	void  CreateBackground();

public:
	void CloseGame();

	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);

};