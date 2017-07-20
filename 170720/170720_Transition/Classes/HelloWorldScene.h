#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:
		
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HelloWorld);

	void doPushScene(Ref* pSender);
	void doPushSceneTran(Ref* pSender);
	void doReplaceScene(Ref* pSender);
	void doReplaceSceneTran(Ref* pSender);

	cocos2d::TransitionScene* createTransition(int nIndex, float t, cocos2d::Scene* s);


};

#endif // __HELLOWORLD_SCENE_H__
