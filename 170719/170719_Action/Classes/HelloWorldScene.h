#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

private : 

	enum {
		TYPE_EASE = 0,
		TYPE_ELASTIC = 1,
		TYPE_BOUNCE = 2,
		TYPE_SPEED = 3
	};

	unsigned int mType = 0;

	Action *mpMove = NULL;
	Action *mpEaseIn = NULL;
	Action *mpEaseOut = NULL;
	Action *mpEaseInOut_1= NULL;
	
	Sprite *mpBall_0 = NULL;
	Sprite *mpBall_1 = NULL;
	Sprite *mpBall_2 = NULL;
	Sprite *mpBall_3 = NULL;

	cocos2d::Label *mplblStatus = NULL;

public:

	void DoSelectType(Ref* pSender);
	void DoAction(Ref* pSender);

	void DoReset();

	static cocos2d::Scene* createScene();
    
	virtual bool init();
    
	CREATE_FUNC(HelloWorld);

	void menuCloseCallback(cocos2d::Ref *pSender);
	
};

#endif // __HELLOWORLD_SCENE_H__
