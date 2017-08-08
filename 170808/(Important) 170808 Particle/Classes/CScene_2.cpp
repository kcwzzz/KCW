#include "CScene_2.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* CScene_2::createScene()
{
    return CScene_2::create();
}

bool CScene_2::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto tpBtnGoSceneTitle = MenuItemImage::create(
                                                  "CloseNormal.png",
                                                  "CloseSelected.png",
                                                  CC_CALLBACK_1(::CScene_2::OnClickBtnGoSceneTitle, this));
    
    tpBtnGoSceneTitle->setPosition(Vec2(origin.x + visibleSize.width - tpBtnGoSceneTitle->getContentSize().width/2 ,
                                       origin.y + tpBtnGoSceneTitle->getContentSize().height/2));
    
    
    
    auto tpBtnChange = MenuItemImage::create(
                                       "CloseNormal.png",
                                       "CloseSelected.png",
                                       CC_CALLBACK_1(::CScene_2::OnClickBtnChange, this));
    tpBtnChange->setPosition(Vec2(240.0f, 50.0f));
    
    auto menu = Menu::create(tpBtnGoSceneTitle,
                             tpBtnChange,
                             NULL);
    
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    
    /////////////////////////////
    string tpFileName = "";
    
    //0
    tpFileName = "";
    tpFileName = "Particles/BoilingFoam.plist";
    
    mStringVec.push_back( tpFileName );
    
    //1
    tpFileName = "";
    tpFileName = "Particles/BurstPipe.plist";
    
    mStringVec.push_back( tpFileName );
    
    //2
    tpFileName = "";
    tpFileName = "Particles/Comet.plist";
    
    mStringVec.push_back( tpFileName );
    
    //3
    tpFileName = "";
    tpFileName = "Particles/ExplodingRing.plist";
    
    mStringVec.push_back( tpFileName );
    
    //4
    tpFileName = "";
    tpFileName = "Particles/Flower.plist";
    
    mStringVec.push_back( tpFileName );
    
    //5
    tpFileName = "";
    tpFileName = "Particles/Galaxy.plist";
    
    mStringVec.push_back( tpFileName );
    
    //6
    tpFileName = "";
    tpFileName = "Particles/LavaFlow.plist";
    
    mStringVec.push_back( tpFileName );
    
    //7
    tpFileName = "";
    tpFileName = "Particles/Phoenix.plist";
    
    mStringVec.push_back( tpFileName );
    
    //8
    tpFileName = "";
    tpFileName = "Particles/SmallSun.plist";
    
    mStringVec.push_back( tpFileName );
    
    //9
    tpFileName = "";
    tpFileName = "Particles/SpinningPeas.plist";
    
    mStringVec.push_back( tpFileName );
    
    //10
    tpFileName = "";
    tpFileName = "Particles/Spiral.plist";
    
    mStringVec.push_back( tpFileName );
    
    //11
    tpFileName = "";
    tpFileName = "Particles/SpookyPeas.plist";
    
    mStringVec.push_back( tpFileName );
    
    //12
    tpFileName = "";
    tpFileName = "Particles/TestPremultipliedAlpha.plist";
    
    mStringVec.push_back( tpFileName );
    
    //13
    tpFileName = "";
    tpFileName = "Particles/Upsidedown.plist";
    
    mStringVec.push_back( tpFileName );
    
    //14
    tpFileName = "";
    tpFileName = "Particles/holly.plist";
    
    mStringVec.push_back( tpFileName );
    
    

    return true;
}

void CScene_2::onEnter()
{
    Scene::onEnter();
    
    mpListener = EventListenerTouchOneByOne::create();
    mpListener->setSwallowTouches(true);
    mpListener->onTouchBegan = CC_CALLBACK_2(CScene_2::onTouchBegan, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);
}

void CScene_2::onExit()
{
    _eventDispatcher->removeEventListener(mpListener);
    
    Scene::onExit();
}

bool CScene_2::onTouchBegan(Touch *touch, Event * event)
{
    auto touchPoint = touch->getLocation();
    
    this->showParticle(touchPoint);
    
    return true;
}

void CScene_2::showParticle(Vec2 pPoint)
{
    ParticleSystem* tpParticleSys = ParticleSystemQuad::create(mStringVec[mCurIndex]);
    tpParticleSys->setPosition(pPoint);
    tpParticleSys->setDuration(2.0);
    tpParticleSys->setAutoRemoveOnFinish(true);
    
    this->addChild(tpParticleSys);
}



void CScene_2::OnClickBtnGoSceneTitle(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}
void CScene_2::OnClickBtnChange(cocos2d::Ref* pSender)
{
    if( mCurIndex < mStringVec.size() - 1 )
    {
        mCurIndex++;
    }
    else
    {
        mCurIndex = 0;
    }
}
