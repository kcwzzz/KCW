#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

//#include "RyuAniBox.h"

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
	this->addChild(menu, 1);

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

	auto tpListener = EventListenerTouchOneByOne::create();
	tpListener->setSwallowTouches(true);

	tpListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	tpListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(tpListener, this);

	mpCamera = new ActionCamera();
	mpCamera->startWithTarget(this);

	auto tpSprite = Sprite::create("HelloWorld.png");
	tpSprite->setPosition(Vec2(240, 160));
	this->addChild(tpSprite);

	return true;
}

//게임루프에서 호출되는 멤버함수

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

//손가락이 닫는 순간 호출된다.
bool HelloWorld::onTouchBegan(Touch *touch, Event *event)
{
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event)
{
	ChangeCameraAngle(touch, event);
}


void HelloWorld::ChangeCameraAngle(cocos2d ::Touch *touch, cocos2d ::Event *event)
{
	Vec3 tEye = mpCamera->getEye();
	//여기부터 계속
}

bool HelloWorld::isTouchInside(Sprite* sprite, Touch* touch)
{
	auto touchVec2 = touch->getLocation();

	bool bTouch = sprite->getBoundingBox().containsPoint(touchVec2);

	return bTouch;
}

void HelloWorld::startMovingBackground()
{
	if (isLeftPressed == true && isRightPressed == true)
	{
		return;
	}
	log("start moving");

	this->schedule(schedule_selector(HelloWorld::moveBackground));

	mIsUpdate = true;


}

void HelloWorld::stopMovingBackground()
{
	log("Stop moving");
	this->unschedule(schedule_selector(HelloWorld::moveBackground));
	mIsUpdate = false;

}

void HelloWorld::moveBackground(float t)
{
	auto tSpeed = 90;

	if (isLeftPressed)
	{
		tSpeed = -90;
		mpSprDragon->setFlippedX(false);
	}
	else
	{
		tSpeed = 90;
		mpSprDragon->setFlippedX(true);
		// setFlippedX : 좌우 반전 setFlippedY : 상하 반전
	}

	auto tPos = Vec2(mpSprDragon->getPosition().x + tSpeed*t, mpSprDragon->getPosition().y);

	if (tPos.x < 0)
	{
		tPos.x = 0;

	}
	else if (tPos.x > 512 * 2)
	{
		tPos.x = 512 * 2;
	}

	mpSprDragon->setPosition(tPos);
}

void HelloWorld::update(float dt)
{
	if (true == mIsUpdate)
	{
		moveBackground(dt);
	}
}