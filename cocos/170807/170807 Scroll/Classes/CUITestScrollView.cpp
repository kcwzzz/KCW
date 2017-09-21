#include <stdio.h>

#include "CUITestScrollView.h"


Scene* CUITestScrollView::createScene()
{
	auto scene = Scene::create();

	auto layer = CUITestScrollView::create();

	scene->addChild(layer);

	return scene;
}

bool CUITestScrollView::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto tBtnGoSceneTitle = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CUITestScrollView::OnClickBtnGoSceneTitle, this));

	tBtnGoSceneTitle->setPosition(Vec2(origin.x + visibleSize.width - tBtnGoSceneTitle->getContentSize().width / 2,
		origin.y + tBtnGoSceneTitle->getContentSize().height / 2));


	auto menu = Menu::create(tBtnGoSceneTitle,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto sprite1 = Sprite::create("HelloWorld.png");
	auto sprite2 = Sprite::create("HelloWorld.png");

	sprite1->setScale(0.4f);
	sprite2->setScale(0.4f);


	sprite1->setPosition(Vec2(100, 80));
	sprite2->setPosition(Vec2(850, 80));

	auto tpLayer = LayerColor::create(Color4B(255, 0, 255, 255));
	tpLayer->setAnchorPoint(Vec2::ZERO);
	tpLayer->setPosition(Vec2(0, 0));
	tpLayer->setContentSize(Size(960, 160));

	tpLayer->addChild(sprite1);
	tpLayer->addChild(sprite2);

	mpScrollView = ScrollView::create();
	mpScrollView->retain();

	mpScrollView->setDirection(ScrollView::Direction::HORIZONTAL);
	//mpScrollView->setDirection(ScrollView::Direction::VERTICAL);

	mpScrollView->setViewSize(Size(480, 160));
	mpScrollView->setContentSize(tpLayer->getContentSize());
	mpScrollView->setContentOffset(Vec2::ZERO, false);

	mpScrollView->setPosition(Vec2(0, 100));
	mpScrollView->setContainer(tpLayer);//addchild까지 다 해주는 함수네..


	mpScrollView->setDelegate(this);
	//CUITestScrollView 가 ScrollViewDelegate를 상속받아서 이벤트에 쓰기 위해서
	//주석 처리하면 아래 scrollViewDidScroll 함수가 작동하지 않음.
	//화면 스크롤 자체는 가능함.

	this->addChild(mpScrollView);

	return true;
}


void CUITestScrollView::scrollViewDidScroll(ScrollView *view)
{
	log("scrollViewDidScroll...");
}



void CUITestScrollView::scrollViewDidZoom(ScrollView *view)
{
	log("scrollViewDidZoom...");
}


void CUITestScrollView::OnClickBtnGoSceneTitle(Ref *pSender)
{
	this->removeChild(mpScrollView);

	mpScrollView->release();

	Director::getInstance()->popScene();
}