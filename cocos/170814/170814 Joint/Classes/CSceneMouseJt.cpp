#include "CSceneMouseJt.h"
#include "SimpleAudioEngine.h"

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* CSceneMouseJt::createScene()
{
    auto scene = Scene::create();
    
    auto layer = CSceneMouseJt::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool CSceneMouseJt::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto tBtnClose = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CSceneMouseJt::OnClickBtnGoScene, this));
    
    tBtnClose->setPosition(Vec2(480 - 50 , 0 + 50));
    
    
    
    
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(tBtnClose, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    // 윈도우 크기를 구한다.
    winSize = Director::getInstance()->getWinSize();
    
    // 이미지의 텍스쳐를 구한다.
    texture = Director::getInstance()->getTextureCache()->addImage("blocks.png");
    
    // 월드 생성
    if (this->createBox2dWorld(true))
    {
        this->schedule(schedule_selector(CSceneMouseJt::tick));
    }
    
    
    return true;
}

bool CSceneMouseJt::createBox2dWorld(bool debug)
{
    // 월드 생성 시작 --------------------------------------------------------------------------
    
    // 중력의 방향을 결정한다.
    b2Vec2 gravity = b2Vec2(0.0f, -30.0f);
    
    _world = new b2World(gravity);
    _world->SetAllowSleeping(true);
    _world->SetContinuousPhysics(true);
    
    // 디버그 드로잉 설정
    if (debug) {
        
        
        m_debugDraw = new GLESDebugDraw(PTM_RATIO);
        _world->SetDebugDraw(m_debugDraw);
        
        uint32 flags = 0;
        flags += b2Draw::e_shapeBit;
        flags += b2Draw::e_jointBit;
        //flags += b2Draw::e_aabbBit;
        //flags += b2Draw::e_pairBit;
        //flags += b2Draw::e_centerOfMassBit;
        m_debugDraw->SetFlags(flags);
    }
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body *groundBody = _world->CreateBody(&groundBodyDef);
    
    b2EdgeShape groundEdge;
    b2FixtureDef boxShapeDef;
    boxShapeDef.shape = &groundEdge;
    
    // 아래쪽.
    groundEdge.Set(b2Vec2(0, 0), b2Vec2(winSize.width / PTM_RATIO, 0));
    groundBody->CreateFixture(&boxShapeDef);
    // 왼쪽
    groundEdge.Set(b2Vec2(0, 0), b2Vec2(0, winSize.height / PTM_RATIO));
    groundBody->CreateFixture(&boxShapeDef);
    // 위쪽
    groundEdge.Set(b2Vec2(0, winSize.height / PTM_RATIO),
                   b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO));
    groundBody->CreateFixture(&boxShapeDef);

    groundEdge.Set(b2Vec2(winSize.width / PTM_RATIO, winSize.height / PTM_RATIO),
                   b2Vec2(winSize.width / PTM_RATIO, 0));
    groundBody->CreateFixture(&boxShapeDef);
    
    // 월드 생성 끝   --------------------------------------------------------------------------
    
    
    
    bDrag = false;
    
    // 마우스 조인트 바디를 생성해서 월드에 추가한다.
    gbody = this->addNewSprite(Point(0, 0), Size(0, 0), b2_staticBody, NULL, 0);
    
    // 바디를 생성해서 월드에 추가한다.
    this->addNewSprite(Point(240, 160), Size(32, 32), b2_dynamicBody, "test", 0);
    
    
    return true;
}

CSceneMouseJt::~CSceneMouseJt()
{
    delete _world;
    _world = NULL;
}

void CSceneMouseJt::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
    //
    // IMPORTANT:
    // This is only for debug purposes
    // It is recommend to disable it
    //
    Layer::draw(renderer, transform, flags);
    
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION);
    
    kmGLPushMatrix();
    
    _world->DrawDebugData();
    
    kmGLPopMatrix();
}

void CSceneMouseJt::onEnter()
{
    Layer::onEnter();
    
    // 싱글터치모드로 터치리스너 등록
    auto listener = EventListenerTouchOneByOne::create();
    // Swallow touches only available in OneByOne mode.
    // 핸들링된 터치 이벤트를 터치 이벤트 array에서 지우겠다는 의미이다.
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(CSceneMouseJt::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(CSceneMouseJt::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(CSceneMouseJt::onTouchEnded, this);
    
    // The priority of the touch listener is based on the draw order of sprite
    // 터치리스너의 우선순위를 (노드가) 화면에 그려진 순서대로 한다.
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void CSceneMouseJt::onExit()
{
    //_eventDispatcher->removeEventListeners(EventListener::Type::TOUCH_ONE_BY_ONE);
    
    //_eventDispatcher->removeAllEventListeners();
    
    Layer::onExit();
}

void CSceneMouseJt::tick(float dt)
{
    int velocityIterations = 8;
    int positionIterations = 3;
    
    // Step : 물리 세계를 시뮬레이션한다.
    _world->Step(dt, velocityIterations, positionIterations);
    
    // 만들어진 객체 만큼 루프를 돌리면서 바디에 붙인 스프라이트를 여기서 제어한다.
    for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != NULL) {
            Sprite* spriteData = (Sprite *)b->GetUserData();
            
            spriteData->setPosition(Point(b->GetPosition().x * PTM_RATIO,
                                          b->GetPosition().y * PTM_RATIO));
            spriteData->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
        }
    }
}

b2Body* CSceneMouseJt::addNewSprite(Point point, Size size, b2BodyType bodytype,
                                 const char* spriteName, int type)
{
    // 바디데프 만들고 속성들을 지정한다.
    b2BodyDef bodyDef;
    bodyDef.type = bodytype;
    bodyDef.position.Set(point.x / PTM_RATIO, point.y / PTM_RATIO);
    
    if (spriteName){
        if (strcmp(spriteName, "test") == 0) {
            int idx = (CCRANDOM_0_1() > .5 ? 0 : 1);
            int idy = (CCRANDOM_0_1() > .5 ? 0 : 1);
            Sprite* sprite = Sprite::createWithTexture(texture,
                                                       Rect(32 * idx, 32 * idy, 32, 32));
            sprite->setPosition(point);
            this->addChild(sprite);
            
            bodyDef.userData = sprite;
        }
        else {
            Sprite* sprite = Sprite::create(spriteName);
            sprite->setPosition(point);
            this->addChild(sprite);
            
            bodyDef.userData = sprite;
        }
    }
    
    // 월드에 바디데프의 정보로 바디를 만든다.
    b2Body *body = _world->CreateBody(&bodyDef);
    
    // 바디에 적용할 물리 속성용 바디의 모양을 만든다.
    b2FixtureDef fixtureDef;
    b2PolygonShape dynamicBox;
    b2CircleShape circle;
    
    if (type == 0) {
        dynamicBox.SetAsBox(size.width / 2 / PTM_RATIO, size.height / 2 / PTM_RATIO);
        
        fixtureDef.shape = &dynamicBox;
    }
    else {
        circle.m_radius = (size.width / 2) / PTM_RATIO;
        
        fixtureDef.shape = &circle;
    }
    
    // Define the dynamic body fixture.
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.0f;
    
    body->CreateFixture(&fixtureDef);
    
    return body;
}

b2Body* CSceneMouseJt::getBodyAtTab(Point p)
{
    b2Fixture *fix;
    for (b2Body *b = _world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != NULL) {
            if (b->GetType() == b2_staticBody) continue;
            fix = b->GetFixtureList();
            if (fix->TestPoint(b2Vec2(p.x / PTM_RATIO, p.y / PTM_RATIO))) {
                return b;
            }
        }
    }
    return NULL;
}

bool CSceneMouseJt::onTouchBegan(Touch *touch, Event * event)
{
    Point touchPoint = touch->getLocation();
    
    if (b2Body *b = this->getBodyAtTab(touchPoint))
    {
        dragBody = b;
        bDrag = true;
        
        
        //MouseJoint 설명 정의하고 생성함.
        b2MouseJointDef tDef;
        tDef.bodyA = gbody;
        tDef.bodyB = dragBody;
        tDef.target.Set(dragBody->GetPosition().x, dragBody->GetPosition().y);
        tDef.maxForce = 300.0 * dragBody->GetMass();
        
        mpMouseJoint = (b2MouseJoint *)_world->CreateJoint(&tDef);
    }
    
    return true;
}

void CSceneMouseJt::onTouchMoved(Touch *touch, Event * event)
{
    Point touchPoint = touch->getLocation();
    
    if (bDrag) {
        mpMouseJoint->SetTarget(b2Vec2(touchPoint.x / PTM_RATIO, touchPoint.y / PTM_RATIO));
    }
}

void CSceneMouseJt::onTouchEnded(Touch *touch, Event * event)
{
    if (bDrag) {
        _world->DestroyJoint(mpMouseJoint);
        mpMouseJoint = NULL;
        
        dragBody->SetAwake(true);
    }
    bDrag = false;
}


void CSceneMouseJt::OnClickBtnGoScene(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}




