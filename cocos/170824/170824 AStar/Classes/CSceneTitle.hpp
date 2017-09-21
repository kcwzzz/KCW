//
//  CSceneTitle.hpp
//  BuildAndStudio_2
//
//  Created by pokpoongryu on 2016. 8. 11..
//
//

#ifndef CSceneTitle_hpp
#define CSceneTitle_hpp

#include <stdio.h>

#include "cocos2d.h"


class CSceneTitle : public cocos2d::Layer
{
protected:
    
    const int CONFIG_TIME = 1;
    
    int mTimeCount = 0;
    
    
    
    cocos2d::Label *mpLabel = NULL;
    
    
    
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
    
    // a selector callback
    void OnClickBtnTest(cocos2d::Ref* pSender);
    
    void OnClickBtnGoSceneFindPath(cocos2d::Ref* pSender);
    
    
    void OnTimer(float dt);
    void OnTimerBox2d(float dt);
    void OnTimerBox2d_0(float dt);
    
    
    cocos2d::TransitionScene *CreateTransition(int tType, float t, cocos2d::Scene *tpScene );
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(CSceneTitle);
};


#endif /* CSceneTitle_hpp */
