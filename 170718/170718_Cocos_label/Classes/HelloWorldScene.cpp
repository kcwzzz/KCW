#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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

	auto closeItem_1 = MenuItemImage::create(
											"CloseNormal.png",
											"CloseSelected.png",
											CC_CALLBACK_1(HelloWorld::OnClickBtnTest, this));



	closeItem_1->setPosition(Vec2(400 ,200));

//	auto tBtnTest = MenuItemImage::create(	)
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, closeItem_1, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
	mpSprBall = Sprite::create("HelloWorld.png");
	mpSprBall->retain();

	mVecBall.x = 400;
	mVecBall.y = 240;

	this->addChild(mpSprBall, 0);

	mpLabel_0 = Label::createWithBMFont("fonts/boundsTestFont.fnt", "I am a goob boy.");
	mpLabel_0->retain();

	Vec2 tVecLabel;
	tVecLabel.x = 400;
	tVecLabel.y = 240;
	mpLabel_0->setPosition(tVecLabel);
	mpLabel_0->setAnchorPoint(Vec2(0, 0));

	this->addChild(mpLabel_0, 1);

	mpLabel_1 = Label::createWithCharMap("fonts/larabie-16.plist");
	mpLabel_1->retain();

	tVecLabel.x = 400;
	tVecLabel.y = 240 - 40;

	mpLabel_1->setPosition(tVecLabel);
	mpLabel_1->setString("GOODBOY");
	this->addChild(mpLabel_1, 2);
	
    return true;
}

void HelloWorld::OnClickBtnTest(Ref *pSender)

{
	auto tTemp = (MenuItemImage *)pSender;
	tTemp->getTag();
	mpLabel_1->setString("CLICK SUCCESS");
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{

	this->removeChild(mpLabel_1);

	if (NULL != mpLabel_1)
	{
		mpLabel_1->release();
		mpLabel_1 = NULL;	
	}

	this->removeChild(mpLabel_0);


	if (NULL != mpLabel_0)
	{
		mpLabel_0->release();
		mpLabel_0 = NULL;
	}

	this->removeChild (mpSprBall);
	if (NULL !=
		mpSprBall)
	{
		mpSprBall->release();
		mpSprBall = NULL;
	}
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
