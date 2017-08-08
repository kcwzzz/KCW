#include "CScene_1.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* CScene_1::createScene()
{
    return CScene_1::create();
}

bool CScene_1::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto tBtnGoSceneTitle = MenuItemImage::create(
                                                  "CloseNormal.png",
                                                  "CloseSelected.png",
                                                  CC_CALLBACK_1(::CScene_1::OnClickBtnGoSceneTitle, this));
    
    tBtnGoSceneTitle->setPosition(Vec2(origin.x + visibleSize.width - tBtnGoSceneTitle->getContentSize().width/2 ,
                                       origin.y + tBtnGoSceneTitle->getContentSize().height/2));
    
    
    
    
    auto tBtnToggle = MenuItemImage::create("CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(::CScene_1::OnClickBtnToggle, this));
    
    
    tBtnToggle->setPosition(Vec2(240.0f, 50.0f));
    
    
    auto menu = Menu::create(tBtnGoSceneTitle,
                             tBtnToggle,
                             NULL);
    
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    
    /////////////////////////////
    
    ParticleSystem* tpParticleSys = NULL;
    Texture2D *tpTexture = NULL;
    
    //snow
    tpParticleSys = NULL;
    tpParticleSys = ParticleSnow::create();
    tpParticleSys->retain();
    
    tpTexture = NULL;
    tpTexture = Director::getInstance()->getTextureCache()->addImage("Images/snow.png");
    tpParticleSys->setTexture(tpTexture);
    
    tpParticleSys->setTotalParticles(200);  // default : 700
    tpParticleSys->setLife(5); // 3
    tpParticleSys->setLifeVar(1);
    
    // gravity
    tpParticleSys->setGravity(Vec2(0, -10));
    
    // speed of particles
    tpParticleSys->setSpeed(100);  // 130
    tpParticleSys->setSpeedVar(30); // 30
    
    
    Color4F startColor = tpParticleSys->getStartColor();
    startColor.r = 0.9f;
    startColor.g = 0.9f;
    startColor.b = 0.9f;
    tpParticleSys->setStartColor(startColor);
    
    
    Color4F endColorVar = tpParticleSys->getStartColorVar();
    endColorVar.r = 0.0f;
    endColorVar.g = 0.0f;
    endColorVar.b = 0.0f;
    tpParticleSys->setStartColorVar(endColorVar);
    
    tpParticleSys->setEmissionRate(tpParticleSys->getTotalParticles() / tpParticleSys->getLife());
    
    tpParticleSys->setPosition(Vec2(240, 320));
    

    mParticleSysVec.push_back( tpParticleSys );
    
    
    
    
    //rain
    tpParticleSys = NULL;
    tpParticleSys = ParticleRain::create();
    tpParticleSys->retain();
    
    tpTexture = NULL;
    tpTexture = Director::getInstance()->getTextureCache()->addImage("Images/fire.png");
    tpParticleSys->setTexture(tpTexture);

    tpParticleSys->setLife(4);
    tpParticleSys->setScaleY(4);
    tpParticleSys->setPosition(Vec2(240, 320));
    
    mParticleSysVec.push_back( tpParticleSys );

    
    
    mpCurParticleSys = mParticleSysVec[mCurIndex];
    this->addChild(mpCurParticleSys);
    
    
    
    DoToggle();
    
    
    return true;
}

void CScene_1::DoToggle()
{
    if( 0 == mCurIndex )
    {
        mCurIndex = 1;
    }
    else
    {
        mCurIndex = 0;
    }
    
    
    
    this->removeChild( mpCurParticleSys );
    
    mpCurParticleSys = mParticleSysVec[ mCurIndex ];
    
    this->addChild( mpCurParticleSys );
}


void CScene_1::OnClickBtnToggle(cocos2d::Ref* pSender)
{
    DoToggle();
}

void CScene_1::OnClickBtnGoSceneTitle(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}

