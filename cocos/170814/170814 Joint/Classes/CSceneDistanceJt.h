#ifndef __CSceneDistanceJt_SCENE_H__
#define __CSceneDistanceJt_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include <GLES-Render.h>

#define PTM_RATIO 32

using namespace cocos2d;

class CSceneDistanceJt : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void OnClickBtnGoScene(cocos2d::Ref* pSender);
    
    CREATE_FUNC(CSceneDistanceJt);
    
    
    bool createBox2dWorld(bool debug);
    ~CSceneDistanceJt();
    //virtual void draw();
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    void createSpring(Point point, Size size);
    
    virtual void onEnter();
    virtual void onExit();
    void tick(float dt);
    b2Body* addNewSprite(Point point, Size size, b2BodyType bodytype, const char* spriteName, int type);
    
    b2Body* getBodyAtTab(Point p);
    virtual bool onTouchBegan(Touch *touch, Event * event);
    virtual void onTouchMoved(Touch *touch, Event * event);
    virtual void onTouchEnded(Touch *touch, Event * event);
    
    Size winSize;
    Texture2D* texture;
    b2World* _world;
    GLESDebugDraw* m_debugDraw;
    
    bool bDrag;
    b2Body *dragBody;
    b2MouseJoint *mpMouseJoint;
    b2Body *gbody;
};

#endif // __CSceneDistanceJt_SCENE_H__