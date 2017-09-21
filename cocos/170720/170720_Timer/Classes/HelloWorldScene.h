#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
protected:
	int mCount_0 = 0;
	int mCount_1 = 0;
	int mCount_2 = 0;

	Label *mplblTest_0 = NULL;
	Label *mplblTest_1 = NULL;
	Label *mplblTest_2 = NULL;

public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HelloWorld);
	
	void callEveryFrame(float f);	//모든 프레임 마다
	void myTick(float f);			//틱마다
	void myTickOnce(float f);		//1회만

};

#endif // __HELLOWORLD_SCENE_H__
