#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


using namespace std;

class CActor;

class HelloWorld : public cocos2d::Scene
{
//test
private:
    cocos2d::Label *label = NULL;
    
protected :
	CActor *mpActor = NULL;

    
public:

	void SetmDir_0();
	void SetmDir_1();
	void SetmDir_2();
	void SetmDir_3();

	void SetFSM_0();
	void SetFSM_1();
       
	void update(float dt);

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
