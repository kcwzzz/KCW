#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CUITestScrollView
	:public cocos2d::LayerColor, public ScrollViewDelegate
{
public:
	ScrollView *mpScrollView = NULL;

	virtual void scrollViewDidScroll(ScrollView *view);
	virtual void scrollViewDidZoom(ScrollView *view);

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void OnClickBtnGoSceneTitle(Ref *pSender);
	CREATE_FUNC(CUITestScrollView);
};
