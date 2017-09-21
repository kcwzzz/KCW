#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:

	cocos2d::Sprite *tBackground_0;
	cocos2d::Sprite *tBackground_1;

	MenuItemFont *StartGame = NULL;
	Menu *tStartMenu = NULL;

	cocos2d::Size winSize;
	cocos2d::Layer *mpLayerForWorld = NULL;
	cocos2d::Layer *mpLayerForUI = NULL;

	void CreateBackgroundParallax();
	void SceneChange(Object *pSender);

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);

};
#endif // __HELLOWORLD_SCENE_H__