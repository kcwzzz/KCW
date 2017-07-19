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

	mpBtnLt = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnLt, this));


	mpBtnRt = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnRt, this));


	mpBtnLt->setPosition(Vec2(300.0f, 50.0f));

	mpBtnRt->setPosition(Vec2(500.0f, 50.0f));


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
	auto tKeyListner = EventListenerKeyboard::create();
	tKeyListner->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	tKeyListner->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(tKeyListner, this);

	mpSprActor = NULL;

	mpSprActor = Sprite::create("slime.png");
	mpSprActor->retain();

	this->addChild(mpSprActor, 0);

	mVecActor.x = 400.0f;
	mVecActor.y = 200.f;

	mpSprActor->setPosition(mVecActor);

	return true;
}

void HelloWorld::OnClickBtnLt(Ref *pSender)
{
	mVecActor.x = mVecActor.x - 1.0f;
	mpSprActor->setPosition(mVecActor);
}

void HelloWorld::OnClickBtnRt(Ref *pSender)
{
	mVecActor.x = mVecActor.x + 1.0f;
	mpSprActor->setPosition(mVecActor);
}


void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		mVecActor.x = mVecActor.x - 1.0f;
		mpSprActor->setPosition(mVecActor);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		mVecActor.x = mVecActor.x + 1.0f;
		mpSprActor->setPosition(mVecActor);
	}
}

void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	this->removeChild(mpSprActor);
	this->removeChild(menu);

	if (NULL != mpSprActor)
	{
		mpSprActor->release();
		mpSprActor = NULL;
	}

	if (NULL != menu)
	{
		menu->release();
		menu = NULL;
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
