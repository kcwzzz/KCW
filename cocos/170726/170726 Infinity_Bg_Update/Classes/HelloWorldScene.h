#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{

protected:
	
	Sprite *mpSpriteA = NULL;
	Vec2 mVecA;

	Sprite *mpSpriteB = NULL;
	Vec2 mVecB;

	void OnCompleteAction();

	float mScrollSpeed = 0;
	float tHeight = 0;
	

public:
	void update(float dt);
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
