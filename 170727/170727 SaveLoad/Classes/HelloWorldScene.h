#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "CPlayInfo.hpp"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
private :
	CPlayInfo mPlayinfo;

	void LoadFromFile();
	void SaveToFile();
	
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);

	void OneClickBtnPlayTest(cocos2d::Ref* pSender);
	void OneClickBtnLoad(cocos2d::Ref* pSender);
	void OneClickBtnSave(cocos2d::Ref* pSender);

	void BuildUIPlayInfo();

	Label *mpLabel = NULL;
};

#endif // __HELLOWORLD_SCENE_H__
