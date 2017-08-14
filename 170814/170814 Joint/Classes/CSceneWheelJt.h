#ifndef __CSceneWheelJt_SCENE_H__
#define __CSceneWheelJt_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include <GLES-Render.h>

#define PTM_RATIO 32

using namespace cocos2d;

class CSceneWheelJt : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void OnClickBtnGoScene(cocos2d::Ref* pSender);
    
    CREATE_FUNC(CSceneWheelJt);
    
    
    bool createBox2dWorld(bool debug);
    ~CSceneWheelJt();
    //virtual void draw();
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    void tick(float dt);
    b2Body* addNewSprite(Point point, Size size, b2BodyType bodytype, const char* spriteName, int type);
    
    Size winSize;
    Texture2D* texture;
    b2World* _world;
    GLESDebugDraw* m_debugDraw;
    
    b2Body *mpBodyCar = NULL;
    b2WheelJoint* mWheel_0 = NULL;
    b2WheelJoint* mWheel_1 = NULL;
};

#endif // __CSceneWheelJt_SCENE_H__
