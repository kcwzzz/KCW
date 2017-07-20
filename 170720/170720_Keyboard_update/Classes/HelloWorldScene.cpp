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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	
	auto tBtnTest = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnTest, this));

	tBtnTest->setPosition(Vec2(400.f, 100.f));

		
	auto menu = Menu::create(closeItem, tBtnTest, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
		
	srand((unsigned int)time(NULL));

	mpSpr = NULL;

	mpSpr = Sprite::create("slime.png");
	this->addChild(mpSpr,0);

	mpSpr->setPosition(Vec2(400.f, 100.f));

	/*
	키보드이벤트 이용.

	좌측이동, 우측이동, 발사  만들자.

	좌측이동 : 키가 눌린 상태이면 좌측으로 속도 2.0f씩 이동( 속도는 본인이 알맞게 정해도 됨 )
	우측이동 : 키가 눌린 상태이면 우측으로 속도 2.0f씩 이동( 속도는 본인이 알맞게 정해도 됨 )

	발사 : 키가 눌린 상태이면 총알 연속발사( 실제로 총알이 나가지 않아도 됨 )

	클리핑 처리도 하자.
	x: 0~800
	y: 0~480
	*/

	//리스터로 받아서 하는 것
	//콜백 함수
	auto tKeyListner = EventListenerKeyboard::create();
	tKeyListner->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	tKeyListner->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(tKeyListner, this);
	
	this->scheduleUpdate();

	return true;
}

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
}

void HelloWorld::OnClickBtnTest(cocos2d::Ref* pSender)
{
	mVec.x = (float)(rand() % 800 + 0);
	mVec.y = (float)(rand() % 480 + 0);

	mpSpr->setPosition(mVec);
}

void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{


	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{

		mSpeedPower = 10;
		mDirX = DIR_LEFT;
		//mVec.x = mVec.x + mSpeedPower*mDirX;
		//mpSpr->setPosition(mVec);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		mSpeedPower = 10;
		mDirX = DIR_RIGHT;
		//mVec.x = mVec.x + mSpeedPower*mDirX;
		//mpSpr->setPosition(mVec);
	}

	mIsKeyPressed = true;
}
void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	mIsKeyPressed = false;
	mSpeedPower = 0;
}
void HelloWorld::update(float dt)
{
	if (true == mIsKeyPressed) 
	{
		mVec.x = mVec.x + mSpeedPower*mDirX*dt*mIsKeyPressed;
		mpSpr->setPosition(mVec);
	}
}