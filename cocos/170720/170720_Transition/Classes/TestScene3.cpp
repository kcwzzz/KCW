#include "TestScene3.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

Scene* TestScene3::createScene()
{
	return TestScene3::create();
}


bool TestScene3::init()
{
	if(!Scene::init())
	{
	return false;
	}

	auto item1 = MenuItemFont::create(
		"Close Scene3",
		CC_CALLBACK_1(TestScene3::doClose, this));
	item1->setColor(Color3B  (255, 0, 0));

	auto pMenu = Menu::create(item1, nullptr);
	pMenu->setPosition(Vec2(400, 50));
	this->addChild(pMenu, 10);

	auto tpSprite = Sprite::create("slime_boss.png");
	tpSprite->setPosition(Vec2(400, 240));
	this->addChild(tpSprite, 0);
	
	return true;
}

void TestScene3 :: doClose(Ref *pSender)
{
	auto pScene = HelloWorld :: createScene();
	Director::getInstance()->replaceScene(pScene);
}