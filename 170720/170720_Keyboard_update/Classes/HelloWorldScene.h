#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
protected:
	cocos2d::Sprite *mpSpr = NULL;
	cocos2d::Vec2 mVec;

	enum {
		DIR_LEFT = -1,
		DIR_RIGHT = 1

	};

	float mSpeedPower = 0.0f;
	float mDirX = 0.0f;

	bool mIsKeyPressed = false;

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HelloWorld);

	virtual void update(float dt);
	void OnClickBtnTest(cocos2d::Ref* pSender);

	//void OnClickBtnLt(Ref *pSender);
	//void OnClickBtnRt(Ref *pSender);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);
};

#endif // __HELLOWORLD_SCENE_H__
