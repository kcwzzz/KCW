#include "TestScene2.h"

using namespace cocos2d;

Scene* TestScene2::createScene()

{

	return TestScene2::create();

}

bool TestScene2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto item1 = MenuItemFont::create(
		"Close Scene 2",
		CC_CALLBACK_1(TestScene2::doClose, this));

	auto pMenu = Menu::create(item1, nullptr);

	pMenu->setPosition(Vec2(400, 50));

	this->addChild(pMenu, 10);

	auto tpSprite = Sprite::create("slime.png");
	tpSprite->setPosition(Vec2(400, 240));
	this->addChild(tpSprite, 0);

	return true;
}

void TestScene2::doClose(Ref* pSender)
{
	Director::getInstance()->popScene();
}