#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "pugixml.hpp"

#include "CStageMgr.hpp"
#include "CScenePlayGame.hpp"

USING_NS_CC;

using namespace std;
using namespace pugi;

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

	CStageMgr::GetInstance()->CreateActor();
	
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));


	auto tBtnStage_0 = MenuItemFont::create("Stage_0", CC_CALLBACK_1(HelloWorld::OnLoadStageInfo_0, this));
	tBtnStage_0->setPosition((Vec2(240, 160 + 40)));

	auto tBtnStage_1 = MenuItemFont::create("Stage_1", CC_CALLBACK_1(HelloWorld::OnLoadStageInfo_1, this));
	tBtnStage_1->setPosition((Vec2(240, 160)));

	auto tBtnStage_2 = MenuItemFont::create("Stage_2", CC_CALLBACK_1(HelloWorld::OnLoadStageInfo_2, this));
	tBtnStage_2->setPosition((Vec2(240, 160 - 40)));

	
	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, tBtnStage_0, tBtnStage_1, tBtnStage_2,  NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	auto label = Label::createWithTTF("test_androidbuild_1", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	
	/*
	xml_document tXmlDoc;

	std:string tFileName = FileUtils::getInstance()->fullPathForFilename("data/test_data.xml");
	xml_parse_result tResult = tXmlDoc.load_file(tFileName.c_str());

	if (tResult)
	{
		xml_node tNodeResult = tXmlDoc.child("response");
		xml_node tNodeSomes = tNodeResult.child("somes");

		for (xml_node tNodeSome = tNodeSomes.child("some"); tNodeSome; tNodeSome = tNodeSome.next_sibling("some"))
		{
			std::string tName = tNodeSome.text().get();
			log("%s", tName.c_str());
		}
	}
	*/
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

void HelloWorld::OnLoadStageInfo_0(Ref* pSender)
{
	CStageMgr::GetInstance()->SetCurStageIndex(0);

	auto pScene = CScenePlayGame::createScene();
	Director::getInstance()->pushScene(pScene);
}

void HelloWorld::OnLoadStageInfo_1(Ref* pSender)
{
	CStageMgr::GetInstance()->SetCurStageIndex(1);

	auto pScene = CScenePlayGame::createScene();
	Director::getInstance()->pushScene(pScene);
}

void HelloWorld::OnLoadStageInfo_2(Ref* pSender)
{
	CStageMgr::GetInstance()->SetCurStageIndex(2);

	auto pScene = CScenePlayGame::createScene();
	Director::getInstance()->pushScene(pScene);
}