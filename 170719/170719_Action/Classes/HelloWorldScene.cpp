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
	MenuItemFont::setFontSize(18);

	auto tpBtnDoSelectType = MenuItemFont::create("DoSelectType",
		CC_CALLBACK_1(HelloWorld::DoSelectType, this));

	tpBtnDoSelectType->setColor(Color3B(255, 255, 0));


	MenuItemFont::setFontSize(18);

	auto tpBtnDoAction = MenuItemFont::create("DoAction",
		CC_CALLBACK_1(HelloWorld::DoAction, this));

	tpBtnDoAction->setColor(Color3B(255, 0, 0));


	auto tpMenuForTest = Menu::create(tpBtnDoSelectType, tpBtnDoAction, NULL);

	tpMenuForTest->alignItemsVertically();

	tpMenuForTest->setPosition(Vec2(240, 50));

	this->addChild(tpMenuForTest);

	mplblStatus = Label::createWithTTF("Type : 0", "fonts/Marker Felt.ttf", 24);
	mplblStatus->setPosition(Vec2(400, 450));

	this->addChild(mplblStatus, 1);

	mpBall_0 = Sprite::create("CloseNormal.png");
	this->addChild(mpBall_0);

	mpBall_1 = Sprite::create("CloseNormal.png");
	this->addChild(mpBall_1);

	mpBall_2 = Sprite::create("CloseNormal.png");
	this->addChild(mpBall_2);

	mpBall_3 = Sprite::create("CloseNormal.png");
	this->addChild(mpBall_3);

	DoReset();


	return true;
}


void HelloWorld::DoSelectType(Ref* pSender)
{
	if (mType < TYPE_SPEED)
	{
		mType++;
	}
	else
	{
		mType = 0;
	}

	char tszTemp[512];
	memset(tszTemp, 0, 512);
	std::sprintf(tszTemp, "Type: %d", mType);
	std::string tString = tszTemp;

	mplblStatus->setString(tString);

	DoReset();
}

void HelloWorld::DoAction(Ref* pSender)
{
	DoReset();

	mpMove = MoveBy::create(6.0f, Vec2(700, 0));

	switch (mType)
	{
	case TYPE_EASE:
	{

		mpEaseIn = EaseIn::create(static_cast<ActionInterval *>(mpMove->clone()), 3.0f);
		mpEaseOut = EaseOut::create(static_cast<ActionInterval *>(mpMove->clone()), 3.0f);
		mpEaseInOut_1 = EaseInOut::create(static_cast<ActionInterval *>(mpMove->clone()), 3.0f);

		break;
	}

	case TYPE_ELASTIC:
	{

		mpEaseIn = EaseElasticIn::create(static_cast<ActionInterval *>(mpMove->clone()), 0.4f);
		mpEaseOut = EaseElasticOut::create(static_cast<ActionInterval *>(mpMove->clone()), 0.4f);
		mpEaseInOut_1 = EaseElasticInOut::create(static_cast<ActionInterval *>(mpMove->clone()), 0.4f);
		break;
	}

	case TYPE_BOUNCE:
	{

		mpEaseIn = EaseBounceIn::create(static_cast<ActionInterval *>(mpMove->clone()));
		mpEaseOut = EaseBounceOut::create(static_cast<ActionInterval *>(mpMove->clone()));
		mpEaseInOut_1 = EaseBounceInOut::create(static_cast<ActionInterval *>(mpMove->clone()));
		break;
	}

	case TYPE_SPEED:
	{

		mpEaseIn = Speed::create(static_cast<ActionInterval *>(mpMove->clone()), 2);
		mpEaseOut = Speed::create(static_cast<ActionInterval *>(mpMove->clone()), 3);
		mpEaseInOut_1 = Speed::create(static_cast<ActionInterval *>(mpMove->clone()), 4);
		break;
	}
	}

	mpBall_0->runAction(mpMove);
	mpBall_1->runAction(mpEaseIn);
	mpBall_2->runAction(mpEaseOut);
	mpBall_3->runAction(mpEaseInOut_1);

}

void HelloWorld::DoReset()
{

	mpBall_0->setPosition(Vec2(50, 400));
	mpBall_0->setScale(1.7f);

	mpBall_1->setPosition(Vec2(50, 300));
	mpBall_1->setScale(1.0f);

	mpBall_2->setPosition(Vec2(50, 200));
	mpBall_2->setScale(1.0f);

	mpBall_3->setPosition(Vec2(50, 100));
	mpBall_3->setScale(1.0f);
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
