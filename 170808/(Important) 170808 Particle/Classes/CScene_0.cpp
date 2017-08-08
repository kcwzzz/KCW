#include "CScene_0.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* CScene_0::createScene()
{
    return CScene_0::create();
}

bool CScene_0::init()
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
                                                  CC_CALLBACK_1(::CScene_0::OnClickBtnGoSeceneTitle, this));
    
    tBtnGoSceneTitle->setPosition(Vec2(origin.x + visibleSize.width - tBtnGoSceneTitle->getContentSize().width/2 ,
                                origin.y + tBtnGoSceneTitle->getContentSize().height/2));
    
    
    
    auto tBtnDoParticle = MenuItemImage::create(
                                                  "CloseNormal.png",
                                                  "CloseSelected.png",
                                                  CC_CALLBACK_1(::CScene_0::OnClickBtnOdParticle, this));
    
    tBtnDoParticle->setPosition(Vec2(240 ,50));
    
    
    auto tBtnSelectTexture = MenuItemImage::create(
                                                "CloseNormal.png",
                                                "CloseSelected.png",
                                                CC_CALLBACK_1(::CScene_0::OnClickBtnSelectTexture, this));
    
    tBtnSelectTexture->setPosition(Vec2(240 + 50 ,50));

    
    

    auto menu = Menu::create(tBtnGoSceneTitle,
                             tBtnDoParticle,
                             tBtnSelectTexture,
                             NULL);
    
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 10);
    
    /////////////////////////////
    
    Texture2D *tpTexture = NULL;
    
    //0
    tpTexture = NULL;
    tpTexture = Director::getInstance()->getTextureCache()->addImage("Images/fire.png");
    
    mTextureVec.push_back(tpTexture);
    
    
    //1
    tpTexture = NULL;
    tpTexture = Director::getInstance()->getTextureCache()->addImage("Images/stars.png");
    
    mTextureVec.push_back(tpTexture);
    
    
    //본인이 원하는 여러 텍스쳐 파일을 추가해서 테스트해볼 것!!
    
    
    
    //파티클마다 retain해주지 않으면 실행중 메모리 에러남.
    ParticleSystem* tpParticleSys = NULL;
    
    //0
    tpParticleSys = NULL;
    tpParticleSys = ParticleFire::create();      // Images/fire.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    //1
    tpParticleSys = NULL;
    tpParticleSys = ParticleSun::create();       // Images/fire.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    //2
    tpParticleSys = NULL;
    tpParticleSys = ParticleGalaxy::create();    // Images/fire.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    //3
    tpParticleSys = NULL;
    tpParticleSys = ParticleSpiral::create();    // Images/fire.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    //4
    tpParticleSys = NULL;
    tpParticleSys = ParticleSmoke::create();     // Images/fire.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    //5
    tpParticleSys = NULL;
    tpParticleSys = ParticleMeteor::create();    // Images/fire.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    //6
    tpParticleSys = NULL;
    tpParticleSys = ParticleFlower::create();    // Images/stars.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    
    //7
    tpParticleSys = NULL;
    tpParticleSys = ParticleFireworks::create(); // Images/stars.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    //8
    tpParticleSys = NULL;
    tpParticleSys = ParticleExplosion::create(); // Images/stars.png
    tpParticleSys->retain();
    
    mParticleSysVec.push_back(tpParticleSys);
    
    
    
    
    
    
    mpCurParticleSys = mParticleSysVec[mCurIndexParticleSys];
    
    // 파티클의 크기 조정
    mpCurParticleSys->setScale(1.0);
    
    // 파티클의 지속 시간 조정 : -1 means 'forever'
    //mpCurParticleSys->setDuration(1.0);
    
    // 파티클의 위치 조정
    mpCurParticleSys->setPosition(Vec2(240, 160));
    
    
    
    
    
    
    this->addChild(mpCurParticleSys);


    this->DoParticle();
    
    return true;
}


void CScene_0::OnClickBtnOdParticle(cocos2d::Ref *pSender)
{
	unsigned int tMaxCount = mParticleSysVec.size();

	if (mCurIndexParticleSys < tMaxCount - 1)
	{
		mCurIndexParticleSys++;
	}
	else
	{
		mCurIndexParticleSys = 0;
	}
	DoParticle();
}
void CScene_0::OnClickBtnSelectTexture(cocos2d::Ref *pSender)
{
	unsigned int tMaxCount = mTextureVec.size();

	if (mCurIndexTexture < tMaxCount - 1)
	{
		mCurIndexTexture++;
	}
	else
	{
		mCurIndexTexture = 0;
	}


	DoParticle();
}
void CScene_0::DoParticle()
{
	this->removeChild(mpCurParticleSys);

	mpCurParticleSys = mParticleSysVec[mCurIndexParticleSys];
	mpCurTexture = mTextureVec[mCurIndexTexture];

	mpCurParticleSys->setTexture(mpCurTexture);


	this->addChild(mpCurParticleSys);

}

void CScene_0::OnClickBtnGoSeceneTitle(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}
