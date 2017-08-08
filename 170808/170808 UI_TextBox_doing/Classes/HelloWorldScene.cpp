#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "CUITestEditBox.h"

USING_NS_CC;

using namespace std;

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


	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto tBtnGoScene = MenuItemFont::create("GoScene",
		CC_CALLBACK_1(HelloWorld::OnClickBtnGoScene, this));

	tBtnGoScene->setPosition(Vec2(240.0f, 160.0f));

	auto menu = Menu::create(closeItem,tBtnGoScene, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	auto label = Label::createWithTTF("Edit Box", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);


	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::OnClickBtnGoScene(Ref *pSender)
{
	auto tpScene = CUITestEditBox::createScene();
	Director::getInstance()->pushScene(tpScene);
}