#pragma once

#ifndef __SceneTrans__TestScene2__
#define __SceneTrans__TestScene2__

#include "cocos2d.h"

class TestScene2 : public cocos2d::Scene
{

public:
	static cocos2d::Scene *createScene();

	virtual bool init();

	CREATE_FUNC(TestScene2);

	void doClose(Ref* pSender);

};

#endif

