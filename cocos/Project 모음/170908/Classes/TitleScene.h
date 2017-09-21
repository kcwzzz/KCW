#pragma once

#include "cocos2d.h"

USING_NS_CC;

class TitleScene : public cocos2d::Scene
{
private:
	Sprite *tBackground_0;
	Sprite *tBackground_1;

protected:

	Layer *mpWorldLayer= NULL;
	Layer *mpUILayer = NULL;

	Label *mpTitleLabel = NULL;

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