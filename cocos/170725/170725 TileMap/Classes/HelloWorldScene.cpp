
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "CGrid.h"

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

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	mpListener = EventListenerTouchOneByOne::create();
	mpListener->setSwallowTouches(true);

	mpListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	mpListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	mpListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);

	mplblTest = Label::createWithTTF("UI", "fonts/Marker Felt.ttf", 18);
	mplblTest->setColor(Color3B::RED);
	mplblTest->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - mplblTest->getContentSize().height));
	
	this->addChild(mplblTest, 1);

	mpGrid = new CGrid();
	mpGrid->Create();
	mpGrid->SetScene(this);

	mpGrid->Build();

	return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

	auto tTouchPos = touch->getLocation();

	return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tTouchPos = touch->getLocation();
}

void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tTouchPos = touch->getLocation();

	float tX = tTouchPos.x;
	float tY = tTouchPos.y;

	tY = 320 - tY;

	int tCol = 0;
	int tRow = 0;

	tCol = tX/80;
	tRow = tY/80;

	int tAttrib = 0;
	tAttrib = mpGrid->GetAttrib(tCol, tRow);

	char tszTemp[512];
	memset(tszTemp, 0, 512);
	sprintf(tszTemp, "tCol :  %d, tRow: %d, attrib %d", tCol, tRow, tAttrib);
	mplblTest->setString(tszTemp);
}

void HelloWorld::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	mpGrid->UnBuild();

	if (NULL != mpGrid)
	{
		mpGrid->Destroy();

		delete mpGrid;
		mpGrid = NULL;
	}

	_eventDispatcher->removeEventListener(mpListener);
	

	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
