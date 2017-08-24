//
//  CSceneTitle.cpp
//  BuildAndStudio_2
//
//  Created by pokpoongryu on 2016. 8. 11..
//
//

#include "CSceneTitle.hpp"
#include "CSceneFindPath.h"



USING_NS_CC;







Scene* CSceneTitle::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CSceneTitle::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CSceneTitle::init()
{
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CSceneTitle::OnClickBtnTest, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    
    
    auto tBtnGoSceneFindPath = MenuItemImage::create(
                                                     "CloseNormal.png",
                                                     "CloseSelected.png",
                                                     CC_CALLBACK_1(CSceneTitle::OnClickBtnGoSceneFindPath, this));
    
    tBtnGoSceneFindPath->setPosition(Vec2(400 , 100));
    
    
    
    auto menu = Menu::create(closeItem, tBtnGoSceneFindPath, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    
    mpLabel = Label::createWithTTF("CSceneTitle", "fonts/BMJUA_ttf.ttf", 24);
    
    mpLabel->setPosition(Vec2(400.0f, 400.0f));
    
    
    this->addChild(mpLabel, 1);
    
    
    
    
    
    
    
    auto tpLabel = Label::createWithTTF("ver 1.0", "fonts/BMJUA_ttf.ttf", 24);
    tpLabel->setPosition(Vec2(origin.x,
                              origin.y));
    tpLabel->setAnchorPoint(Vec2(0,0));
    
    this->addChild(tpLabel, 100);
    
    
    
    
    
    
    return true;
}






void CSceneTitle::OnClickBtnTest(Ref* pSender)
{

    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void CSceneTitle::OnTimer(float dt)
{
    char tszTemp[256];
    memset( tszTemp, 0, 256 );
    sprintf(tszTemp, "%d초 후에 시작합니다.", CONFIG_TIME - mTimeCount );
    
    
    mpLabel->setString(tszTemp);
    
    mTimeCount++;
    
    
    
    if( mTimeCount>=CONFIG_TIME)
    {
        this->unschedule(CC_SCHEDULE_SELECTOR(CSceneTitle::OnTimer));
        
        
        auto tpScene = CSceneFindPath::createScene();
        //Director::getInstance()->pushScene( tpScene );
        auto tpTransScene = CreateTransition(1, CONFIG_TIME, tpScene);
        if( NULL != tpTransScene )
        {
            Director::getInstance()->pushScene( tpTransScene );
        }
    }
}


cocos2d::TransitionScene *CSceneTitle::CreateTransition(int tType, float t, cocos2d::Scene *tpScene )
{
    TransitionScene *tResult = NULL;
    
    
    Director::getInstance()->setDepthTest( false );
    
    switch( tType )
    {
        case 0:
        {
            tResult = TransitionJumpZoom::create(t, tpScene);
        }
            break;
        case 1:
        {
            tResult = TransitionProgressRadialCCW::create(t, tpScene);
        }
            break;
        case 2:
        {
            tResult = TransitionTurnOffTiles::create(t, tpScene);
        }
            break;
        case 3:
        {
            tResult = TransitionFade::create(t, tpScene);
        }
            break;
            
    }
    
    return tResult;
}
                                   
void CSceneTitle::OnClickBtnGoSceneFindPath(cocos2d::Ref* pSender)
{
    mTimeCount = 0;
    schedule(CC_SCHEDULE_SELECTOR(CSceneTitle::OnTimer), 1.0f);
    
    if( true == this->isScheduled("OnTimer")  )
    {
        mpLabel->setString("isScheduled.OnTimer");
    }
}

