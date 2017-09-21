#ifndef __SCENE_2_H__
#define __SCENE_2_H__

#include "cocos2d.h"

#include <vector>

using namespace cocos2d;
using namespace std;

typedef vector<string> CStringVec;
typedef CStringVec::iterator CStringVecItor;

/*
 created by pokpoongryu 
 
 use plist
 */
class CScene_2 : public cocos2d::Scene
{
public:
    
    CStringVec mStringVec;
    
    unsigned int mCurIndex = 0;
    
    
    cocos2d::EventListenerTouchOneByOne *mpListener = NULL;
    
public:
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
    
    void OnClickBtnGoSceneTitle(cocos2d::Ref* pSender);
    void OnClickBtnChange(cocos2d::Ref* pSender);
    
    void showParticle(cocos2d::Vec2 pPoint);
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(CScene_2);
};

#endif // __SCENE_2_H__
