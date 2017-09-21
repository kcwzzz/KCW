#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

private : 
	enum{

		STATE_MOVE = 0,
		STATE_ROTATE = 1,
		STATE_SCALE = 2,
		STATE_JUMP = 3,
		STATE_TINT = 4,
		STATE_BEZIER = 5,
		STATE_PLACE = 6,
		STATE_BLINK = 7,
		STATE_FADEOUT = 8,
		STATE_FADEIN = 9,
	};

	enum {
		TYPE_TO = 0,
		TYPE_BY = 1
	};

	unsigned int mState = 0;
	unsigned int mType = 90;

	void DoActionWithStateAndType();

	Sprite *mpSprBall = NULL;
	Action *mpAction = NULL;
	cocos2d::Label *mplblStatus = NULL;


public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorld);

	void menuCloseCallback(cocos2d::Ref *pSender);

	void DoSelectState(Ref* pSender);
	void DoSelectType(Ref* pSender);

	void DoAction(Ref* pSender);

};

#endif // __HELLOWORLD_SCENE_H__
