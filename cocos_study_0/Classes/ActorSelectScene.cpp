#include "ActorSelectScene.h"
#include "SimpleAudioEngine.h"
#include "DataDriven.h"
#include "GameScene.h"
USING_NS_CC;

Scene* ActorSelectScene::createScene()
{
	return ActorSelectScene::create();
}

bool ActorSelectScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	DataDriven::GetInstance()->CreateActor();

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(ActorSelectScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	
	auto SelectActor_0 = MenuItemImage::create(
		"Hero_1_Select.png",
		"HelloWorld.png",
		CC_CALLBACK_1(ActorSelectScene::OnLoadStageInfo_0, this));
	SelectActor_0->setPosition(Vec2(300, 200));

	auto SelectActor_1 = MenuItemImage::create(
		"Hero_2_Select.png",
		"HelloWorld.png",
		CC_CALLBACK_1(ActorSelectScene::OnLoadStageInfo_1, this));
	SelectActor_1->setPosition(Vec2(700, 200));

	auto menu = Menu::create(closeItem, SelectActor_0, SelectActor_1, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	return true;
}

void ActorSelectScene::OnLoadStageInfo_0(Ref* pSender)
{
	DataDriven::GetInstance()->SetCurActorInfo(0);

	auto pScene = GameScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void ActorSelectScene::OnLoadStageInfo_1(Ref* pSender)
{
	DataDriven::GetInstance()->SetCurActorInfo(1);

	auto pScene = GameScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void ActorSelectScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}