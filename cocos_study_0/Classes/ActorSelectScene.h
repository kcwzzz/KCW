#pragma once

#include "cocos2d.h"

USING_NS_CC;

class ActorSelectScene : public cocos2d::Scene
{

protected:
	Sprite *mpSprite_0 = NULL;
	Sprite *mpSprite_1 = NULL;

	Sprite *mpBGsprite_0 = NULL;
	Sprite *mpBGsprite_1 = NULL;

public:

	void OnLoadStageInfo_0(Ref *pSender);
	void OnLoadStageInfo_1(Ref *pSender);

	void OnLoadStage_0();
	void OnLoadStage_1();

	void SeqStageChange_0();
	void SeqStageChange_1();
	
	void FadeOutBG_0();
	void FadeOutBG_1();




	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ActorSelectScene);

};