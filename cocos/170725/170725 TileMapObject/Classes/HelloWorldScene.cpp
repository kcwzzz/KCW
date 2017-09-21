
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
	this->addChild(menu, 1);

	mpSprCoin = Sprite::create("coin.png");
	mpSprCoin->retain();

	auto tMap = TMXTiledMap::create("exam_tilemap.tmx");
	this->addChild(tMap, 0, 11);
	tMap->setAnchorPoint(Vec2(0, 0));

	TMXObjectGroup *tObj = tMap->getObjectGroup("layer_object");

	ValueMap tSpawnPosisionActor = tObj->getObject("objectLayer");

	int tX = tSpawnPosisionActor["x"].asInt();
	int tY = tSpawnPosisionActor["y"].asInt();

	Vec2 tVec;
	tVec.x = tX;
	tVec.y = tY;
	mpSprCoin->setPosition(tVec);
	tMap->addChild(mpSprCoin);;

	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	if (NULL != mpSprCoin)
	{
		mpSprCoin->release();
		mpSprCoin = NULL;
	}

	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
