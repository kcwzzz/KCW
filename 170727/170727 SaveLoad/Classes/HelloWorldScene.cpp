#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	srand((unsigned)time(NULL));

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

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);


	auto tBtnLoad = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OneClickBtnLoad, this));

	tBtnLoad->setPosition(Vec2(50, 50));

	auto tBtnSave = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OneClickBtnSave, this));

	tBtnSave->setPosition(Vec2(100, 50));

	auto tBtnPlayTest = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OneClickBtnPlayTest, this));
	tBtnPlayTest->setPosition(Vec2(350, 50));


	auto menu = Menu::create(closeItem, tBtnLoad, tBtnSave, tBtnPlayTest, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100);

	mpLabel = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	mpLabel->setPosition((Vec2(origin.x + visibleSize.width - mpLabel->getContentSize().width / 2,
		origin.y + mpLabel->getContentSize().height / 2)));

	this->addChild(mpLabel, 10);

	auto sprite = Sprite::create("HelloWorld.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite, 1);

	return true;
}

void HelloWorld::OneClickBtnPlayTest(cocos2d::Ref* pSender)
{
	mPlayinfo.mName = "Save-Load Test";	

	mPlayinfo.mScore = mPlayinfo.mScore + 1;
	mPlayinfo.mX = 240.0f;
	mPlayinfo.mY = 160.0f;

	BuildUIPlayInfo();
}
void HelloWorld::OneClickBtnLoad(cocos2d::Ref* pSender)
{
	LoadFromFile();
	BuildUIPlayInfo();
}
void HelloWorld::OneClickBtnSave(cocos2d::Ref* pSender)
{
	SaveToFile();
}


void HelloWorld::LoadFromFile()
{
	mPlayinfo.mName = UserDefault::getInstance()->getStringForKey("key_name");
	mPlayinfo.mScore = UserDefault::getInstance()->getIntegerForKey("key_score");
	mPlayinfo.mX = UserDefault::getInstance()->getFloatForKey("key_x");
	mPlayinfo.mY = UserDefault::getInstance()->getFloatForKey("key_y");

}

void HelloWorld::SaveToFile()
{
	UserDefault::getInstance()->setStringForKey("key_name", mPlayinfo.mName);
	UserDefault::getInstance()->setIntegerForKey("key_score",mPlayinfo.mScore);
	UserDefault::getInstance()->setFloatForKey("key_x",mPlayinfo.mX);
	UserDefault::getInstance()->setFloatForKey("key_y", mPlayinfo.mY);

	UserDefault::getInstance()->flush();
}

void HelloWorld::BuildUIPlayInfo()
{
	string tString = "";

	char tszTemp[256];
	memset(tszTemp, 0, 256);
	sprintf(tszTemp, "%s, %d, %f, %f",
		mPlayinfo.mName.c_str(),
		mPlayinfo.mScore,
		mPlayinfo.mX,
		mPlayinfo.mY
			);

	tString = tString + tszTemp;

	mpLabel->setString(tString);

}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
