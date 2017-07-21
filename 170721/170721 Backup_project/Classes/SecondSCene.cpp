#include "SecondScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* SecondScene::createScene()
{
	return SecondScene::create();
}

bool SecondScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto item1 = MenuItemFont::create(
		"Close Scene 2",
		CC_CALLBACK_1(SecondScene::doClose, this));
	item1->setColor(Color3B(255, 0, 0));
		
	auto pMenu = Menu::create(item1, nullptr);
	pMenu->setPosition(Vec2(400, 50));
	this->addChild(pMenu);

	log("SecondScene :: init");

	return true;
}

void SecondScene::onEnter()
{
	Scene::onEnter();
	log("SecondScene :: onEnter");
}

void SecondScene::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();
	log("SecondScene :: onEnterTransitionDidFinish");
}

void SecondScene::onExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();
	log("SecondScene :: onExitTransitionDidStart");
}

void SecondScene::onExit()
{
	Scene::onExit();
	log("SecondScene :: onExit");
}

SecondScene::~SecondScene()
{
	log("SecondScene :: dealloc");
}

void SecondScene::doClose(Ref *pSender)
{
	auto pScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(pScene);
}


/*
void SecondScene::menuCloseCallback(Ref* pSender)
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
