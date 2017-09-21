#ifndef __SCENE_0_H__
#define __SCENE_0_H__

#include "cocos2d.h"

#include <vector>

using namespace cocos2d;
using namespace std;

typedef vector <ParticleSystem *> CParticleSysVec;
typedef CParticleSysVec::iterator	CParticleSysVecItor;

typedef vector<Texture2D *> CTextureVec;
typedef CTextureVec::iterator CTextureVecItor;

class CScene_0 : public cocos2d::Scene
{
protected:  
	CParticleSysVec mParticleSysVec;

	ParticleSystem *mpCurParticleSys = NULL;

	unsigned int mCurIndexParticleSys = 0;

	CTextureVec mTextureVec;

	Texture2D *mpCurTexture = NULL;

	unsigned int mCurIndexTexture = 0;

public:
	void OnClickBtnGoSeceneTitle(cocos2d::Ref *pSender);
	void OnClickBtnOdParticle(cocos2d::Ref *pSender);
	void OnClickBtnSelectTexture(cocos2d::Ref *pSender);

	void DoParticle();

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(CScene_0);
};

#endif // __SCENE_0_H__
