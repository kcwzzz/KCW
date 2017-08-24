#include "CSceneFindPath.h"
#include "SimpleAudioEngine.h"

#include "CSceneTitle.hpp"



#include "CGrid.hpp"
#include "CUnit.hpp"
#include "CActor.hpp"

#include <iostream>


#include "CRyuPathFinder.hpp"


USING_NS_CC;
using namespace std;


Scene* CSceneFindPath::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CSceneFindPath::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CSceneFindPath::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    
    
    
    mpListener = EventListenerTouchOneByOne::create();
    
    //임의의 객체가 터치 이벤트를 받으면 터치 이벤트가 사라짐.
    mpListener->setSwallowTouches(true);
    
    mpListener->onTouchBegan = CC_CALLBACK_2(CSceneFindPath::onTouchBegan, this);
    mpListener->onTouchMoved = CC_CALLBACK_2(CSceneFindPath::onTouchMoved, this);
    mpListener->onTouchEnded = CC_CALLBACK_2(CSceneFindPath::onTouchEnded, this);
    
    //이벤트리스너를 추가한다.
    //씬 그래프 상의 우선순위에 따라 터치 이벤트를 받는다.
    //( 이를테면, 위에 있는 스프라이트가 먼저 터치 이벤트를 받는다. )
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);
    
    
    
    
    
    
    
    
    
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CSceneFindPath::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    
    
    auto tBtnGoMove = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CSceneFindPath::OnClickBtnGoMove, this));
    
    tBtnGoMove->setPosition(Vec2(origin.x + visibleSize.width - tBtnGoMove->getContentSize().width/2 , 100.0f));

    
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, tBtnGoMove, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
    
    
    mpGrid = NULL;
    mpGrid = new CGrid();
    mpGrid->Create();
    mpGrid->SetScene( this );
    mpGrid->Build();
    
    
    
    mpActor = NULL;
    mpActor = new CActor();
    mpActor->Create();
    mpActor->SetScene(this);
    mpActor->Build();
    
    
    int tRow = 0;
    int tCol = 0;
    
    //mpActor->SetPos( mpGrid->GetPosition(tRow, tCol) );
    mpActor->SetPosOnGrid( tRow, tCol );
    
    
    mpPathFinder = NULL;
    mpPathFinder = new CRyuPathFinder();
    mpPathFinder->Create();
    
    
    
    mpLayer_0 = Layer::create();
    mpLayer_0->retain();
    this->addChild(mpLayer_0);
    
    
    mpLayer_1 = Layer::create();
    mpLayer_1->retain();
    //mpLayer_1->setOpacity(100);
    this->addChild(mpLayer_1, 10);
    
    
    
    
    mplblDebug = Label::createWithTTF("DEBUG: ", "fonts/BMJUA_ttf.ttf", 18);
    mplblDebug->retain();
    mplblDebug->setOpacity(128);
    mplblDebug->setAnchorPoint(Vec2(0,0));
    mplblDebug->setPosition(Vec2(50, 50));
    
    mpLayer_1->addChild( mplblDebug, 100 );
    
    
    
    
    
    
    this->scheduleUpdate();
    
    
    return true;
}

void CSceneFindPath::update(float dt)
{
    mpActor->UpdateMove(dt);
}


void CSceneFindPath::menuCloseCallback(Ref* pSender)
{
    this->unscheduleUpdate();
    
    
    
    
    
    
    
    if( NULL != mplblDebug )
    {
        mpLayer_1->removeChild( mplblDebug );
        
        mplblDebug->release();
        mplblDebug = NULL;
    }
    
    
    if( NULL != mplblDebug )
    {
        this->removeChild( mpLayer_1 );
        
        mpLayer_1->release();
        mpLayer_1 = NULL;
    }
    
    if( NULL != mplblDebug )
    {
        this->removeChild( mpLayer_0 );
        
        mpLayer_0->release();
        mpLayer_0 = NULL;
    }
    
    
    
    
    
    
    if( NULL != mpPathFinder )
    {
        mpPathFinder->Destroy();
        
        delete mpPathFinder;
        mpPathFinder = NULL;
    }
    
    
    if( NULL != mpActor )
    {
        mpActor->UnBuild();
        
        delete mpActor;
        mpActor = NULL;
    }
    
    
    
    mpGrid->UnBuild();
    
    if( NULL != mpGrid )
    {
        mpGrid->Destroy();
        
        delete mpGrid;
        mpGrid = NULL;
    }
    
    
    
    
    
    
    
    //이벤트리스너를 해지한다.
    _eventDispatcher->removeEventListener(mpListener);
    
    
    
    
    
    
    
    Director::getInstance()->popScene();
    
    //auto tpScene = CSceneTitle::createScene();
    //Director::getInstance()->pushScene( tpScene );
}




void CSceneFindPath::OnClickBtnGoMove(Ref *pSender)
{
    int ti = 0;
    for( ti = 0; ti<mpPathFinder->m_RoadVec.size(); ti++ )
    {
        Vec2 tVec = mpPathFinder->m_RoadVec[mpPathFinder->m_RoadVec.size() - 1 - ti ];
        
        
        mpActor->m_RoadVec.push_back( tVec );
    }
    
    mpActor->BeginMove();
}


int CSceneFindPath::DoRandom()
{
    int tResult = rand()%10;

    log("rand result: %d", tResult);
    
    return tResult;
}

bool CSceneFindPath::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    auto tTouchPos = touch->getLocation();
    
    return true;
}

void CSceneFindPath::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    auto tTouchPos = touch->getLocation();
    
}


void CSceneFindPath::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    auto tTouchPos = touch->getLocation();
    
    int tRow = 0;
    int tCol = 0;
    
    
    tRow = (480 - tTouchPos.y)/TILE_SIZE;
    tCol = (tTouchPos.x)/TILE_SIZE;
    
    
    
    //dipslay debug
    char szTemp[512];
    memset(szTemp, 0, 512);
    
    sprintf( szTemp, "Touch point: %f, %f, Row: %d Col: %d ",
                    tTouchPos.x, tTouchPos.y,
                    tRow, tCol );
    
    if(NULL != mplblDebug )
    {
        mplblDebug->setString(szTemp);
    }
    
    
    Vec2 tVecBegin = Vec2::ZERO;
    tVecBegin.x = mpActor->GetCol();
    tVecBegin.y = mpActor->GetRow();
    
    Vec2 tVecEnd = Vec2::ZERO;
    tVecEnd.x = tCol;
    tVecEnd.y = tRow;
    
    
    
    mpPathFinder->InputClickData(tVecBegin, tVecEnd);
    mpPathFinder->FindPath(mpGrid->mAttrib);
    
    mpPathFinder->SetRoadData();
}


