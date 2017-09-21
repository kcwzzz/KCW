#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "rapidjson\document.h"
#include "rapidjson\reader.h"

using namespace rapidjson;

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
	auto menu = Menu::create(closeItem, NULL);
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

	Document document;

	//json은 기본적으로 텍스트 파일
	std::string fileName = FileUtils::getInstance()->fullPathForFilename("data/test_data.json");
	log("[%s]", fileName.c_str());

	std::string clearData = FileUtils::getInstance()->getStringFromFile(fileName);

	if (document.Parse<0>(clearData.c_str()).HasParseError())
	{
		return 1;
	}

	std::string str1 = document["response"].GetString();

	const rapidjson::Value& tSomes = document["somes"];

	for (SizeType i = 0; i < tSomes.Size(); i++)
	{
		log("%s", tSomes[i].GetString());
	}


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
