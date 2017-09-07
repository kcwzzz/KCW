#pragma once

#include "cocos2d.h"

USING_NS_CC;

class ActorSelectScene : public cocos2d::Scene
{

protected:
	Sprite *mpSprite_0 = NULL;
	Sprite *mpSprite_1 = NULL;

public:

	void OnLoadStageInfo_0(Ref *pSender);
	void OnLoadStageInfo_1(Ref *pSender);

	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ActorSelectScene);

};