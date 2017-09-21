#ifndef __SCENE_1_H__
#define __SCENE_1_H__

#include "cocos2d.h"
#include <vector>

using namespace cocos2d;
using namespace std;

typedef vector<ParticleSystem *> CParticleSysVec;
typedef CParticleSysVec::iterator CParticleSysVecItor;

/*
 created by pokpoongryu
 
 example snow, rain based on particle system
 */
class CScene_1 : public cocos2d::Scene
{
protected:
    
    CParticleSysVec mParticleSysVec;
    
    ParticleSystem *mpCurParticleSys = NULL;
    
    unsigned int mCurIndex = 0;
    
public:
    void OnClickBtnGoSceneTitle(cocos2d::Ref* pSender);
    void OnClickBtnToggle(cocos2d::Ref* pSender);
    
    void DoToggle();
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(CScene_1);
};

#endif // __SCENE_1_H__
