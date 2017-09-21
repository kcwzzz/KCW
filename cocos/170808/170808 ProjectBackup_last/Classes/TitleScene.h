#pragma once

#include "cocos2d.h"

USING_NS_CC;

class TitleScene : public cocos2d::Scene
{
private:
	cocos2d::Sprite *tBackground_0;
	cocos2d::Sprite *tBackground_1;

protected:

	cocos2d::Layer *mpWorldLayer= NULL;
	cocos2d::Layer *mpUILayer = NULL;

	cocos2d::Label *mpTitleLabel = NULL;

public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(TitleScene);


public:
	void CreateWorldLayer();
	void CreateUILayer();

	void TitleBackGround();

	void TitleText();

	void CloseGame();
	void BtnStartGame();

	void SceneChange(Object *pSender);
	TransitionScene* TitleScene::createTransition(int nIndex, float t, Scene *s);

};