#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{

protected:
		
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
//	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HelloWorld);

	void doChangeScene(Ref*pSender);

	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();
	virtual void onExit();
	~HelloWorld(void);
};

#endif // __HELLOWORLD_SCENE_H__
