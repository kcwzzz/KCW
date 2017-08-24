#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "RyuAniBox.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
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

	tBtnTest->setPosition(Vec2(400.0f, 100.0f));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, tBtnTest, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	/*
	 auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	 // position the label on the center of the screen
	 label->setPosition(Vec2(origin.x + visibleSize.width/2,
	 origin.y + visibleSize.height - label->getContentSize().height));

	 // add the label as a child to this layer
	 this->addChild(label, 1);

	 // add "HelloWorld" splash screen"
	 auto sprite = Sprite::create("HelloWorld.png");

	 // position the sprite on the center of the screen
	 sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	 // add the sprite as a child to this layer
	 this->addChild(sprite, 0);
	 */
	
	mpAniIdle = new CRyuAniBox();
	mpAniIdle->Create("grossini", 14, 0.5);

	//mpAniIdle->SetScene(this);
	mpAniIdle->SetScene(static_cast<Node *>(this)); //암묵적으로 형변환을 해주지만, 명시적으로 하는 습관을 갖자.
	mpAniIdle->Build();
	
	mpAniIdle->SetPosition(Vec2(400, 240));
	mpAniIdle->RunAni();



	mpAniIdle_1 = new CRyuAniBox();
	mpAniIdle_1->Create("grossini", 14, 0.1);

	//mpAniIdle->SetScene(this);
	mpAniIdle_1->SetScene(static_cast<Node *>(this)); //암묵적으로 형변환을 해주지만, 명시적으로 하는 습관을 갖자.
	mpAniIdle_1->Build();

	mpAniIdle_1->SetPosition(Vec2(440, 240));
	mpAniIdle_1->RunAni();


	mpAniIdle_2 = new CRyuAniBox();
	mpAniIdle_2->Create("grossini", 14, 1);

	//mpAniIdle->SetScene(this);
	mpAniIdle_2->SetScene(static_cast<Node *>(this)); //암묵적으로 형변환을 해주지만, 명시적으로 하는 습관을 갖자.
	mpAniIdle_2->Build();


	mpAniIdle_2->SetPosition(Vec2(400, 180));
	mpAniIdle_2->RunAni();


	//감춰놨던 게임루프를 활성화한다.
	this->scheduleUpdate();

	return true;
}


//게임루프에서 호출되는 멤버함수
void HelloWorld::update(float dt)
{

}

void HelloWorld::OnClickBtnTest(cocos2d::Ref* pSender)
{
	if (true == mpAniIdle->IsShow())
	{
		mpAniIdle->StopAni();
		mpAniIdle->Hide();
	}
	else
	{
		mpAniIdle->Show();
		mpAniIdle->RunAni();
	}

	if (true == mpAniIdle_1->IsShow())
	{
		mpAniIdle_1->StopAni();
		mpAniIdle_1->Hide();
	}
	else
	{
		mpAniIdle_1->Show();
		mpAniIdle_1->RunAni();
	}

	if (true == mpAniIdle_2->IsShow())
	{
		mpAniIdle_2->StopAni();
		mpAniIdle_2->Hide();
	}
	else
	{
		mpAniIdle_2->Show();
		mpAniIdle_2->RunAni();
	}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	this->unscheduleUpdate();



	mpAniIdle->UnBuild();

	if (NULL != mpAniIdle)
	{
		mpAniIdle->Destroy();

		delete mpAniIdle;
		mpAniIdle = NULL;
	}

	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
