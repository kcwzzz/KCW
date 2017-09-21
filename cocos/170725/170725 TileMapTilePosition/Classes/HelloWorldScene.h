#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
private:
	Sprite *mpSprCoin = NULL;

protected :
	EventListenerTouchOneByOne *mpListener = NULL;

	Label *mplblTest = NULL;

	TMXTiledMap *tMap = NULL;

	int GetAttributeWith(int tRow, int tCol);

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);	

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

};

#endif // __HELLOWORLD_SCENE_H__
