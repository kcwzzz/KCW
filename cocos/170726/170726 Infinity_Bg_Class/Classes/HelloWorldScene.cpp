#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "CScrollBg.h"

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
	if (!Scene::init())
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

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));


	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 10);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	/*
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
	*/
	
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(240, 160));
	

	// add the sprite as a child to this layer
	this->addChild(sprite, 1);
	
	//mpSpriteA = Sprite::create("bg.png");
	//mpSpriteA->retain();

	//mpSpriteA->setAnchorPoint(Vec2(0.0f, 0.0f));
	//this->addChild(mpSpriteA, 0);

	//mVecA.x = 0.0f;
	//mVecA.y = 0.0f;
	//mpSpriteA->setPosition(mVecA);

	//mpSpriteB = Sprite::create("bg.png");
	//mpSpriteB->retain();

	//mpSpriteB->setAnchorPoint(Vec2(0.0f, 0.0f));
	//this->addChild(mpSpriteB, 0);

	//mVecB.x = 0.0f;
	//mVecB.y = mpSpriteA->getContentSize().height;//800.0f;
	//mpSpriteB->setPosition(mVecB);

	//tHeight = mpSpriteA->getContentSize().height;

	//mScrollSpeed = 40.0f;


	mpScrollBg = NULL;
	mpScrollBg = new CScrollBg();

	mpScrollBg->Create(100.0f, 2);
	mpScrollBg->SetScene(this);
	mpScrollBg->Build();
	
	this->scheduleUpdate();
	
	return true;
}

void HelloWorld::update(float dt)
{
	//UpdateScroll(dt);
	mpScrollBg->UpdateScroll(dt);
}
/*
void HelloWorld::UpdateScroll(float dt)
{
	//mVecA.x = 0.0f;
	mVecA.y = mVecA.y - mScrollSpeed*dt;
	mpSpriteA->setPosition(mVecA);

	//mVecB.x = 0.0f;
	mVecB.y = mVecB.y - mScrollSpeed*dt;
	mpSpriteB->setPosition(mVecB);

	//float tHeight = mpSpriteA->getContentSize().height;

	if (mVecA.y <= -tHeight)
	{
		mVecA.y = tHeight;
	}

	if (mVecB.y <= -tHeight)
	{
		mVecB.y = tHeight;
	}
}
*/

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	this->unscheduleUpdate();


	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif


}