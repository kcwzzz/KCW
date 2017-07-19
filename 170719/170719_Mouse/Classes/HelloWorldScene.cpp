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

	//	auto tBtnTest = MenuItemImage::create(	)
		// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->retain();
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


	mplblTest = Label::createWithTTF("UI", "fonts/Marker Felt.ttf", 18);
	mplblTest->setPosition(Vec2(origin.x + visibleSize.width/2, 
		origin.y + visibleSize.height - mplblTest->getContentSize().height));

	this->addChild(mplblTest, 1);

	mpSprite = Sprite::create("HelloWorld.png");
	mpSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(mpSprite, 0);
	return true;
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	//마우스 이벤트 등록

	mpListenerMouse = EventListenerMouse::create();

	mpListenerMouse->onMouseDown = CC_CALLBACK_1(HelloWorld::onMouseDown, this);
	mpListenerMouse->onMouseUp = CC_CALLBACK_1(HelloWorld::onMouseUp, this);
	mpListenerMouse->onMouseMove = CC_CALLBACK_1(HelloWorld::onMouseMove, this);
	mpListenerMouse->onMouseScroll = CC_CALLBACK_1(HelloWorld::onMouseScroll, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListenerMouse, this);
	
}

void HelloWorld::onExit()
{

	//마우스 이벤트 등록 해지
	_eventDispatcher->removeEventListener(mpListenerMouse);

	Scene::onExit();
}

void HelloWorld::onMouseDown(cocos2d::Event *event)
{
	auto mouseEvent = static_cast<EventMouse*>(event);
	Vec2 ClickPoint = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	auto isRight = mouseEvent->getMouseButton();
	mplblTest->setString("onMouseDown");
	log("onMouseDown");
}

void HelloWorld::onMouseUp(cocos2d::Event* event)
{
	auto mouseEvent = static_cast<EventMouse*>(event);
	Vec2 ClickPoint = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	auto isRight = mouseEvent->getMouseButton();
	mplblTest->setString("onMouseUp");
	log("onMouseUp");
}

void HelloWorld::onMouseMove(cocos2d::Event *event)
{
	auto mouseEvent = static_cast<EventMouse*>(event);
	Vec2 ClickPoint = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	auto isRight = mouseEvent->getMouseButton();
	mplblTest->setString("onMouseMove");
	log("onMouseMove");
}

void HelloWorld::onMouseScroll(cocos2d::Event* event)
{
	auto mouseEvent = static_cast<EventMouse*>(event);
	Vec2 ClickPoint = Vec2(mouseEvent->getCursorX(), mouseEvent->getCursorY());
	auto isRight = mouseEvent->getMouseButton();
	mplblTest->setString("onMouseScroll");
	log("onMouseScroll");
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
