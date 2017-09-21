#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

//#include "RyuAniBox.h"

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


	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	auto tBtnTest = MenuItemFont::create("Sprite Flip", CC_CALLBACK_1(HelloWorld::OnClickBtnTest, this));

	tBtnTest->setColor(Color3B(255, 255, 0));

	auto tpMenu = Menu::create(tBtnTest, NULL);
	tpMenu->setPosition(Vec2(240, 40));
	this->addChild(tpMenu, 100);

	mpSpr_0 = Sprite::create("Images/f054.png");
	mpSpr_0->setScale(0.5f);
	mpSpr_0->setPosition(Vec2(240, 160));
	this->addChild(mpSpr_0);

	mpSpr_1 = Sprite::create("Images/f062.png");
	mpSpr_1->setScale(0.5f);
	mpSpr_1->setPosition(Vec2(240, 160));
	this->addChild(mpSpr_1);

	mState = 0;

	mpSpr_0->setVisible(true);
	mpSpr_1->setVisible(false);

	return true;
}

//게임루프에서 호출되는 멤버함수

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


void HelloWorld::OnClickBtnTest(Ref* pSender)
{
	if (0 == mState)
	{
		mState = 1;
	}
	else if (1 == mState)
	{
		mState = 0;

	}

	DoFrontFlip();
}

void HelloWorld::DoFrontFlip()
{
	auto tFirstHalf = OrbitCamera::create(
												2.5f, //t
												1.0f, //radius
												0,    //delta radius
												0,    //z
												90.0f,   //delta z
												0,    //x
												0   //delta x
											);

	switch (mState)
	{
	case 0:
	{
		mpSpr_0->runAction(tFirstHalf);
	}
	break;

	case 1:
	{
		mpSpr_1->runAction(tFirstHalf);
	}
	break;
	}

	auto tSequence = Sequence::create(DelayTime::create(0.5f),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::DoBackFlip, this)), NULL);

	this->runAction(tSequence);
}

void HelloWorld :: DoBackFlip()
{
	switch (mState)
	{
	case 0:
	{
		mpSpr_0->setVisible(true);
		mpSpr_1->setVisible(false);
	}
	break;

	case 1:
	{
		mpSpr_0->setVisible(false);
		mpSpr_1->setVisible(true);
	}
	break;

	}
	auto tSecondHalf = OrbitCamera::create(
											2.5f,
											1.0f,
											0,
											270,
											90.0f,
											0,
											0);
	switch (mState)
	{
	case 0:
	{
		mpSpr_0->runAction(tSecondHalf);

	}
	break;

	case 1:
	{
		mpSpr_1->runAction(tSecondHalf);
	}
	break;

	}
}