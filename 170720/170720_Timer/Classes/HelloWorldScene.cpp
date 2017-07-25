#include "HelloWorldScene.h"
#include "SecondScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	mplblTest_0 = Label::createWithTTF("UI", "fonts/Marker Felt.ttf", 18);
	mplblTest_0->setPosition(Vec2(400.0f, 450.0f));

	this->addChild(mplblTest_0, 1);


	mplblTest_1 = Label::createWithTTF("UI", "fonts/Marker Felt.ttf", 18);
	mplblTest_1->setPosition(Vec2(400.0f, 430.0f));

	this->addChild(mplblTest_1, 1);


	mplblTest_2 = Label::createWithTTF("UI", "fonts/Marker Felt.ttf", 18);
	mplblTest_2->setPosition(Vec2(400.0f, 410.0f));

	this->addChild(mplblTest_2, 1);

	mCount_0 = 0;
	mCount_1 = 0;
	mCount_2 = 0;
		
	this->schedule(schedule_selector(HelloWorld::callEveryFrame));
	this->schedule(schedule_selector(HelloWorld::myTick),1.0f);
	this->scheduleOnce(schedule_selector(HelloWorld::myTickOnce),3.0f);

	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	//To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below
	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}

void HelloWorld::callEveryFrame(float f)//모든 프레임 마다
{
	mCount_0++;
	if (mCount_0 > 60)
	{
		mCount_0 = 1;
	}

	char tszTemp[512];
	memset(tszTemp, 0, 512);
	sprintf(tszTemp, "%f callEveryFrame..%d ", f, mCount_0);

	std::string tString = tszTemp;

	mplblTest_0->setString(tString);
}

void HelloWorld::myTick(float f)
{
	mCount_1++;
	if (mCount_1 > 60) {
		mCount_1 = 1;
	}

	char tszTemp[512];
	memset(tszTemp, 0, 512);
	sprintf(tszTemp, "%f myTick..%d ", f, mCount_1);

	std::string tString = tszTemp;

	mplblTest_1->setString(tString);
}

void HelloWorld::myTickOnce(float f)
{
	mCount_2++;
	if (mCount_2 > 60) {
		mCount_2 = 1;
	}


	char tszTemp[512];
	memset(tszTemp, 0, 512);
	sprintf(tszTemp, "%f myTickOnce..%d ", f, mCount_2);

	std::string tString = tszTemp;

	mplblTest_2->setString(tString);
}
