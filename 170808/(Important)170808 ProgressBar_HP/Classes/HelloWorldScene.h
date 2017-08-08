#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;


class CGuageHP;
/*
 
    ProgressTimer ?¥Ïö©
 
    ui???∞Ï∂ú Íµ¨ÌòÑ ?±Ïóê ?¨Ïö©?òÎ©¥ ?òÍ≤†?? 
 
 */
class HelloWorld : public cocos2d::Scene
{
public:
    cocos2d::Sprite* mpSpriteA = NULL;
    cocos2d::Sprite* mpSpriteB = NULL;
    
    
    void SpriteProgressToRadial();
    void SpriteProgressToHorizontal();
    void SpriteProgressToVertical();
    void SpriteProgressToRadialMidpointChanged();
    void SpriteProgressBarVarious();
    void SpriteProgressBarTintAndFade();
    
    
    
public:
    CGuageHP *mpGuageHP = NULL;
    
    void OnClickBtnTestAttack(cocos2d::Ref* pSender);

    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
