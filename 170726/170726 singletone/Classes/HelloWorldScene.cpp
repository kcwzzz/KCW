#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "CSoundManager.h"

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

	CSoundManager::Getinstance()->Create();
	CSoundManager::Getinstance()->PlayBGM(0);
	CSoundManager::Getinstance()->PlayEffect(0);
	
	return true;
}

void HelloWorld::onExit()
{
	CSoundManager::Getinstance()->Destroy();

	Scene::onExit();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{


	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
