#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Scene_0 : public cocos2d::Scene
{

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(Scene_0);


	void doClose(Object* pSender);
};

