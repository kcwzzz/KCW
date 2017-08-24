#ifndef __FINDPATH_SCENE_H__
#define __FINDPATH_SCENE_H__

#include "cocos2d.h"
//http
#include "network/HttpClient.h"


USING_NS_CC;
using namespace cocos2d::network;


class CGrid;

class CUnit;
class CActor;


class CRyuPathFinder;


/*
     created by pokpoongryu
     
     
     A* 길찾기 알고리즘의 예시 장면이다.
 */
class CSceneFindPath : public cocos2d::Layer
{
protected:
    
    CGrid *mpGrid = NULL;
    
    CActor *mpActor = NULL;
    
    
    
    cocos2d::Sprite *mpSprTest = NULL;
    
    
    cocos2d::Label *mplblDebug = NULL;
    
    
    cocos2d::Layer *mpLayer_0 = NULL;
    cocos2d::Layer *mpLayer_1 = NULL;
    
    
    
    //터치 이벤트 리스너
    EventListenerTouchOneByOne *mpListener = NULL;
    
    
    
    
    
    
    
    CRyuPathFinder *mpPathFinder = NULL;
    
    
    
public:
    
    
    
    
    static cocos2d::Scene* createScene();

    virtual bool init();
    virtual void update(float dt);
    
    int DoRandom();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void OnClickBtnGoMove(Ref *pSender);
    
    
    
    //터치의 시작(손가락을 댄다), 터치한 상태로 움직이는 것, 터치의 끝(손가락을 뗀다)
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(CSceneFindPath);
};

#endif // __FINDPATH_SCENE_H__
