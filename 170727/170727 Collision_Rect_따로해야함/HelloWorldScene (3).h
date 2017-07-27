#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


#include "CPlayInfo.hpp"

USING_NS_CC;


class CScrollBg;

class HelloWorld : public cocos2d::Scene
{
protected:
    
    Sprite *mpSpriteA = NULL;
    Vec2 mVecA;
    
    Sprite *mpSpriteB = NULL;
    Vec2 mVecB;
    
    
    CScrollBg *mpScrollBgNear = NULL;
    CScrollBg *mpScrollBgFar = NULL;
    
    
    int mCollisionCount = 0;
    
public:
    
    bool IsCollision();
    
 
    virtual void update(float dt);
    
    
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);
    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event);
    
    
    void OnClickBtnLt(cocos2d::Ref* pSender);
    void OnClickBtnRt(cocos2d::Ref* pSender);
    void OnClickBtnUp(cocos2d::Ref* pSender);
    void OnClickBtnDown(cocos2d::Ref* pSender);
    
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
