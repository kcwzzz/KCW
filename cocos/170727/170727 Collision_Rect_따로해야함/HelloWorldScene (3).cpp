#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


#include "CScrollBg.hpp"


USING_NS_CC;


Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    
    
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 100);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto tKeyListener = EventListenerKeyboard::create();
    tKeyListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    tKeyListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(tKeyListener, this);
    
    
    
    
    
    auto tBtnLt = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::OnClickBtnLt, this));
    tBtnLt->setPosition(Vec2(50, 50));
    
    auto tBtnRt = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::OnClickBtnRt, this));
    tBtnRt->setPosition(Vec2(150, 50));
    
    
    auto tBtnUp = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::OnClickBtnUp, this));
    tBtnUp->setPosition(Vec2(100, 100));
    
    auto tBtnDown = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::OnClickBtnDown, this));
    tBtnDown->setPosition(Vec2(100, 50));
    
    
    
    auto tMenu = Menu::create(tBtnLt,tBtnRt,tBtnUp,tBtnDown, NULL);
    tMenu->setPosition(Vec2::ZERO);
    this->addChild(tMenu, 200);
    
    
    
    mpSpriteA = NULL;
    mpSpriteA = Sprite::create("actor.png");
    
    mVecA.x = 240.0f;
    mVecA.y = 160.0f;
    mpSpriteA->setPosition(mVecA);
    
    //mpSpriteA->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(mpSpriteA, 10);
    
    
    
    mpSpriteB = NULL;
    mpSpriteB = Sprite::create("enemy.png");
    
    mVecB.x = 140.0f;
    mVecB.y = 160.0f;
    mpSpriteB->setPosition(mVecB);
    
    //mpSpriteB->setAnchorPoint(Vec2(0.0f, 0.0f));
    this->addChild(mpSpriteB,10);
    
    
    mpScrollBgFar = NULL;
    mpScrollBgFar = new CScrollBg();
    mpScrollBgFar->Create(200.0f, 0);
    mpScrollBgFar->SetScene(this);
    
    mpScrollBgFar->Build();
    
    
    mpScrollBgNear = NULL;
    mpScrollBgNear = new CScrollBg();
    mpScrollBgNear->Create(400.0f, 5);
    mpScrollBgNear->SetScene(this);
    
    mpScrollBgNear->Build();
    
    
    this->scheduleUpdate();
    
    
    return true;
}


void HelloWorld::update(float dt)
{
    
    mpScrollBgFar->UpdateScroll(dt);
    mpScrollBgNear->UpdateScroll(dt);
    
    
    if ( true == IsCollision() )
    {
        log("collision %d", mCollisionCount);
        
        mCollisionCount++;
    }
}
bool HelloWorld::IsCollision()
{
    bool tResult = false;
    
    
    
    //point vs rect
    /*
    float tBWidthHalf    = mpSpriteB->getContentSize().width*0.5f;
    float tBHeightHalf   = mpSpriteB->getContentSize().height*0.5f;
    
    if (mVecA.x >= mVecB.x - tBWidthHalf && mVecA.x <= mVecB.x + tBWidthHalf)
    {
        if (mVecA.y >= mVecB.y - tBHeightHalf && mVecA.y <= mVecB.y + tBHeightHalf)
        {
            tResult = true;
        }
    }
    */
    
    //rect vs rect
    /*
    float tAWidthHalf    = mpSpriteA->getContentSize().width*0.5f;
    float tAHeightHalf   = mpSpriteA->getContentSize().height*0.5f;
    

    float tBWidthHalf    = mpSpriteB->getContentSize().width*0.5f;
    float tBHeightHalf   = mpSpriteB->getContentSize().height*0.5f;

    if (mVecA.x + tAWidthHalf >= mVecB.x - tBWidthHalf && mVecA.x - tAWidthHalf<= mVecB.x + tBWidthHalf)
    {
        if (mVecA.y + tAHeightHalf >= mVecB.y - tBHeightHalf && mVecA.y - tAHeightHalf <= mVecB.y + tBHeightHalf)
        {
            tResult = true;
        }
    }
     */
     
    
    //based on cocos
    Rect tRectA = mpSpriteA->getBoundingBox();
    Rect tRectB = mpSpriteB->getBoundingBox();
    
    if(true == tRectA.intersectsRect(tRectB))
    {
        tResult = true;
    }
    
    
    return tResult;
}


void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        mVecA.x = mVecA.x - 5.0f;
        
        mpSpriteA->setPosition(mVecA);
    }
    
    
    
    if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        mVecA.x = mVecA.x + 5.0f;
        
        mpSpriteA->setPosition(mVecA);
    }
    
    if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
    {
        mVecA.y = mVecA.y - 5.0f;
        
        mpSpriteA->setPosition(mVecA);
    }
    
    
    
    if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
    {
        mVecA.y = mVecA.y + 5.0f;
        
        mpSpriteA->setPosition(mVecA);
    }
    
    
    
    if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
    {
        
    }
    
    
    
}

void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
    
}




void HelloWorld::OnClickBtnLt(cocos2d::Ref* pSender)
{
    mVecA.x = mVecA.x - 5.0f;

    mpSpriteA->setPosition(mVecA);
}
void HelloWorld::OnClickBtnRt(cocos2d::Ref* pSender)
{
    mVecA.x = mVecA.x + 5.0f;

    mpSpriteA->setPosition(mVecA);
}

void HelloWorld::OnClickBtnUp(cocos2d::Ref* pSender)
{
    mVecA.y = mVecA.y + 5.0f;

    mpSpriteA->setPosition(mVecA);
}

void HelloWorld::OnClickBtnDown(cocos2d::Ref* pSender)
{
    mVecA.y = mVecA.y - 5.0f;

    mpSpriteA->setPosition(mVecA);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    this->unscheduleUpdate();
     
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
}
