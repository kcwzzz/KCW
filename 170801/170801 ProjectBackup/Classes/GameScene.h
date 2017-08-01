#pragma once

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public cocos2d::Scene
{

private:


protected:

	cocos2d::Sprite *mpSpriteA;
	cocos2d::Sprite *mpSpriteB;

	Vec2 mVecA;
	Vec2 mVecB;

	EventListenerTouchOneByOne *mpListener = NULL;

	cocos2d::Sprite *mpActor;//나중에는 CUnit 클래스로 변경하자
	Vec2 mVecActor;

public:
	void CloseGame();
	void OnCompleteAction();
	void TitleBackGround();
	void CreateActor();

	void onEnter();
	void onExit();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *Unused_event);
	
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameScene);

};