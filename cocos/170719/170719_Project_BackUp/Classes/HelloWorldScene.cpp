#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 종료 버튼 
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->retain();
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	// 종료 버튼 


	//타이틀 움직임
	DoSetupTitle();		// 타이틀 초기 상태 셋업 함수
	DoTitleAction();	// 타이틀 액션 함수
	//타이틀 움직임
	DoTitleHide();
	DoSetupSlime();

	return true;
}

//void HelloWorld::
/*
void HelloWorld::onEnter()
{
	Scene::onEnter();// 장면 진입

	//마우스 이벤트 등록

	mpListenerCustom = EventListenerCustom::create("Custom Event", CC_CALLBACK_1(HelloWorld::OnCustomEvent, this));

	_eventDispatcher->addEventListenerWithFixedPriority(mpListenerCustom, 1);
}

void HelloWorld::OnClickBtnTest(Ref *pSender)
{
	static int tCount = 0;
	mplblTest->setString(" ");

	char tBuffer[512];
	memset(tBuffer, 0, 512);
	sprintf(tBuffer, "this is Event Test : %d, tCount");

	EventCustom tEventCustom("Custom Evnet");
	tEventCustom.setUserData(tBuffer);
	_eventDispatcher->dispatchEvent(&tEventCustom);

	tCount++;
}
*/
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}
void HelloWorld::DoSetupTitle()
{
	mplblTitle = Label::createWithCharMap("fonts/larabie-16.plist");
	mplblTitle->retain();
	mplblTitle->setString("HUNTSLIME!");
	mplblTitle->setPosition(400, 0);		//기본위치
	mplblTitle->setScale(4);
	this->addChild(mplblTitle);
}
void HelloWorld::DoTitleAction()
{
	mpMove = MoveTo::create(6.0f, Vec2(400, 240));
	mpEaseMove = EaseElasticInOut::create(static_cast<ActionInterval *>(mpMove->clone()), 0.4f);
	mpFadeOut = FadeOut
	mplblTitle->runAction(mpEaseMove);
}

void HelloWorld::DoTitleHide()
{

}
void HelloWorld::DoSetupSlime()
{

}
