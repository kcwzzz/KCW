#include "CUILayer.h"
#include "cocos2d.h"
#include "CVirtualPad.h"


void CUILayer::CreateLayer()
{
	mpUILayer = new Layer();
	mpUILayer->Layer::create();
	mpUILayer->setAnchorPoint(Vec2(0, 0));
	mpUILayer->setPosition(Vec2(0, 0));
	this->addChild(mpUILayer, 10);
}


void CUILayer::VirtualPad()
{
	mpVirtualPad = new CVirtualPad();
	mpVirtualPad->create(mpUILayer, Vec2(200, 200));

}

void CUILayer::CloseGame()
{

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CUILayer::menuCloseCallback, this));

	closeItem->setPosition(Vec2(450, 25));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
}

void CUILayer::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}