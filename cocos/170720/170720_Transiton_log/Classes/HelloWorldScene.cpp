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

	auto item1 = MenuItemFont::create(
		"pushScene",
		CC_CALLBACK_1(HelloWorld::doChangeScene, this));
	item1->setColor(Color3B(255, 255, 0));
	item1->setTag(777);

	auto item2 = MenuItemFont::create(
	"replaceScene",
		CC_CALLBACK_1(HelloWorld::doChangeScene, this));
	item2->setColor(Color3B(255, 255, 0));
	item2->setTag(999);

	auto pMenu = Menu::create(item1, item2, nullptr);
	pMenu->alignItemsVertically();

	this->addChild(pMenu);

	log("HelloWorld :: init");

	return true;
}

//void HelloWorld::

void HelloWorld ::doChangeScene(Ref*pSender)
{
	MenuItemFont *tpBtn = (MenuItemFont *)pSender;
	int tTagIndex = tpBtn->getTag();

	auto pScene = SecondScene::createScene();

	switch (tTagIndex)
	{
	case 777:
	{
		Director::getInstance()->pushScene(pScene);
		break;
	}
	case 999:
	{
		Director::getInstance()->replaceScene(pScene);
		break;
	}
	}
}


void HelloWorld::onEnter()
{
	Scene::onEnter();
	log("HelloWorld :: onEnter");	
}

void HelloWorld::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();
	log("HelloWorld :: onEnterTransitionDidFinish");
}

void HelloWorld::onExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();
	log("HelloWorld :: onExitTransitionDidStart");
}

void HelloWorld::onExit()
{
	Scene::onExit();
	log("HelloWorld :: onExit");
}

HelloWorld::~HelloWorld()
{
	log("HelloWorld :: dealloc");
}

/*
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
}*/
