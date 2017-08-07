//
//  CScenePlayGame.hpp
//  cocos_study_2
//
//  Created by YangBruce on 2017. 1. 24..
//
//

#ifndef CScenePlayGame_hpp
#define CScenePlayGame_hpp

#include <stdio.h>
#include <vector>
#include "cocos2d.h"

using namespace cocos2d;

class CScenePlayGame : public cocos2d::Scene
{
private:
    
    Label *mplblTitle = NULL;    
    Label *mplblTotalEnemyCount = NULL;   

    std::vector<Sprite *> mSpriteVec;
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void OnClickBtnGoTitle(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CScenePlayGame);
};


#endif /* CScenePlayGame_hpp */
