#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


#include "CScene_0.h"
#include "CScene_1.h"
#include "CScene_2.h"



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
    
    
    
    //btns
    auto tBtnGoScene_0 = MenuItemFont::create("GoScene_0",
                                              CC_CALLBACK_1(HelloWorld::OnClickBtnGoScene_0, this));
    
    tBtnGoScene_0->setPosition(Vec2(240, 160 + 40 ));
    
    auto tBtnGoScene_1 = MenuItemFont::create("GoScene_1",
                                              CC_CALLBACK_1(HelloWorld::OnClickBtnGoScene_1, this));
    
    tBtnGoScene_1->setPosition(Vec2(240, 160 ));
    
    
    auto tBtnGoScene_2 = MenuItemFont::create("GoScene_2",
                                              CC_CALLBACK_1(HelloWorld::OnClickBtnGoScene_2, this));
    
    tBtnGoScene_2->setPosition(Vec2(240, 160 - 40 ));
    
    
    
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem,
                             tBtnGoScene_0,
                             tBtnGoScene_1,
                             tBtnGoScene_2,
                             NULL);
    
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("PARTICLE", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    
    
    
    
    return true;
}


void HelloWorld::OnClickBtnGoScene_0(Ref *pSender)
{
    auto tpScene = CScene_0::createScene();
    Director::getInstance()->pushScene( tpScene );
}

void HelloWorld::OnClickBtnGoScene_1(Ref *pSender)
{
    auto tpScene = CScene_1::createScene();
    Director::getInstance()->pushScene( tpScene );
}


void HelloWorld::OnClickBtnGoScene_2(Ref *pSender)
{
    auto tpScene = CScene_2::createScene();
    Director::getInstance()->pushScene( tpScene );
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
}
