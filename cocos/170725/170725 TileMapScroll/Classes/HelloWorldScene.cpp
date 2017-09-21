
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

	mpTiledMap = TMXTiledMap::create("test_for_scroll.tmx");
	mpTiledMap->retain();
	mpTiledMap->setAnchorPoint(Vec2(0, 0));

	ParallaxNode *tpNode = ParallaxNode::create();

	tpNode->addChild(mpTiledMap, 0, Vec2(0, 1), Vec2(0, 0));

	auto go = MoveBy::create(0.5, Vec2(0, -960 + 320));
	auto goBack = go->reverse();
	auto tSequence = Sequence::create(go, goBack, NULL);
	auto tRepeatForever = RepeatForever::create(tSequence);

	tpNode->runAction(tRepeatForever);
	this->addChild(tpNode);

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
