#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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



	/*

	auto tpBtnTestAttack = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnTestAttack, this));

	tpBtnTestAttack->setPosition(Vec2(240, 50));



	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem,
		tpBtnTestAttack,
		NULL);

	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 10);

	*/
	auto tpLabel = Label::createWithTTF("Progress Timer", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	tpLabel->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - tpLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(tpLabel, 1);


	mpSpriteA = Sprite::create("HelloWorld.png");
	mpSpriteB = Sprite::create("HelloWorld.png");



	//this->SpriteProgressToRadial();
	this->SpriteProgressToHorizontal();
	//this->SpriteProgressToVertical();
	//this->SpriteProgressToRadialMidpointChanged();
	//this->SpriteProgressBarVarious();
	//this->SpriteProgressBarTintAndFade();





	return true;
}

/*
void HelloWorld::OnClickBtnTestAttack(cocos2d::Ref* pSender)
{
	mpRyuGuageHP->BuildGuageWithDamage(10.0f);
}

*/

void HelloWorld::SpriteProgressToRadial()
{
	//
	auto tpProgressTimer_0 = ProgressTimer::create(mpSpriteA);
	this->addChild(tpProgressTimer_0);

	tpProgressTimer_0->setReverseDirection(false);
	tpProgressTimer_0->setType(ProgressTimer::Type::RADIAL);


	tpProgressTimer_0->setPosition(Vec2(140, 160));


	auto tpAction_0 = ProgressTo::create(4, 100);
	tpProgressTimer_0->runAction(RepeatForever::create(tpAction_0));



	//
	auto tpProgressTimer_1 = ProgressTimer::create(mpSpriteB);
	this->addChild(tpProgressTimer_1);

	tpProgressTimer_1->setReverseDirection(true); // Makes the ridial CCW
	tpProgressTimer_1->setType(ProgressTimer::Type::RADIAL);
	
	tpProgressTimer_1->setPosition(Vec2(340, 160));

	auto tpAction_1 = ProgressTo::create(4, 100);
	tpProgressTimer_1->runAction(RepeatForever::create(tpAction_1));
}


//------------------------------------------------------------------
//
// SpriteProgressToHorizontal
//
//------------------------------------------------------------------

void HelloWorld::SpriteProgressToHorizontal()
{
	//
	auto tpProgressTimer_0 = ProgressTimer::create(mpSpriteA);
	this->addChild(tpProgressTimer_0);


	tpProgressTimer_0->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_0->setMidpoint(Vec2(0, 0));
	tpProgressTimer_0->setBarChangeRate(Vec2(1, 0));

	tpProgressTimer_0->setPosition(Vec2(140, 160));

	auto tpAction_0 = ProgressTo::create(2, 100);
	tpProgressTimer_0->runAction(RepeatForever::create(tpAction_0));





	//
	auto tpProgressTimer_1 = ProgressTimer::create(mpSpriteB);
	this->addChild(tpProgressTimer_1);


	tpProgressTimer_1->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_1->setMidpoint(Vec2(1, 0));
	tpProgressTimer_1->setBarChangeRate(Vec2(1, 0));

	tpProgressTimer_1->setPosition(Vec2(340, 160));

	auto tpAction_1 = ProgressTo::create(2, 100);
	tpProgressTimer_1->runAction(RepeatForever::create(tpAction_1));
}

//------------------------------------------------------------------
//
// SpriteProgressToVertical
//
//------------------------------------------------------------------

void HelloWorld::SpriteProgressToVertical()
{
	//
	auto tpProgressTimer_0 = ProgressTimer::create(mpSpriteA);
	this->addChild(tpProgressTimer_0);



	tpProgressTimer_0->setType(ProgressTimer::Type::BAR);

	tpProgressTimer_0->setMidpoint(Vec2(0, 0));
	tpProgressTimer_0->setBarChangeRate(Vec2(0, 1));

	tpProgressTimer_0->setPosition(Vec2(140, 160));

	auto tpAction_0 = ProgressTo::create(2, 100);
	tpProgressTimer_0->runAction(RepeatForever::create(tpAction_0));






	//
	auto tpProgressTimer_1 = ProgressTimer::create(mpSpriteB);
	this->addChild(tpProgressTimer_1);



	tpProgressTimer_1->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_1->setMidpoint(Vec2(0, 1));
	tpProgressTimer_1->setBarChangeRate(Vec2(0, 1));

	tpProgressTimer_1->setPosition(Vec2(340, 160));

	auto tpAction_1 = ProgressTo::create(2, 100);
	tpProgressTimer_1->runAction(RepeatForever::create(tpAction_1));
}

//------------------------------------------------------------------
//
// SpriteProgressToRadialMidpointChanged
//
//------------------------------------------------------------------

void HelloWorld::SpriteProgressToRadialMidpointChanged()
{
	//
	auto tpProgressTimer_0 = ProgressTimer::create(mpSpriteA);
	this->addChild(tpProgressTimer_0);


	tpProgressTimer_0->setType(ProgressTimer::Type::RADIAL);
	tpProgressTimer_0->setMidpoint(Vec2(0.25f, 0.75f));
	tpProgressTimer_0->setPosition(Vec2(140, 160));

	auto tpAction_0 = ProgressTo::create(2, 100);
	tpProgressTimer_0->runAction(RepeatForever::create(tpAction_0));



	//
	auto tpProgressTimer_1 = ProgressTimer::create(mpSpriteB);
	this->addChild(tpProgressTimer_1);


	tpProgressTimer_1->setType(ProgressTimer::Type::RADIAL);
	tpProgressTimer_1->setMidpoint(Vec2(0.75f, 0.25f));
	tpProgressTimer_1->setPosition(Vec2(340, 160));

	auto tpAction_1 = ProgressTo::create(2, 100);
	tpProgressTimer_1->runAction(RepeatForever::create(tpAction_1));
}

//------------------------------------------------------------------
//
// SpriteProgressBarVarious
//
//------------------------------------------------------------------

void HelloWorld::SpriteProgressBarVarious()
{






	//
	auto tpProgressTimer_0 = ProgressTimer::create(mpSpriteA);
	this->addChild(tpProgressTimer_0);


	tpProgressTimer_0->setType(ProgressTimer::Type::BAR);


	tpProgressTimer_0->setMidpoint(Vec2(0.5f, 0.5f));
	tpProgressTimer_0->setBarChangeRate(Vec2(1, 0));

	tpProgressTimer_0->setPosition(Vec2(140, 160));

	auto tpAction_0 = ProgressTo::create(2, 100);
	tpProgressTimer_0->runAction(RepeatForever::create(tpAction_0));








	//
	auto tpProgressTimer_1 = ProgressTimer::create(mpSpriteB);
	this->addChild(tpProgressTimer_1);


	tpProgressTimer_1->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_1->setMidpoint(Vec2(0.5f, 0.5f));
	tpProgressTimer_1->setBarChangeRate(Vec2(1, 1));

	tpProgressTimer_1->setPosition(Vec2(240, 160));

	auto tpAction_1 = ProgressTo::create(2, 100);
	tpProgressTimer_1->runAction(RepeatForever::create(tpAction_1));




	auto tpProgressTimer_2 = ProgressTimer::create(mpSpriteA);
	this->addChild(tpProgressTimer_2);


	tpProgressTimer_2->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_2->setMidpoint(Vec2(0.5f, 0.5f));
	tpProgressTimer_2->setBarChangeRate(Vec2(0, 1));
	tpProgressTimer_2->setPosition(Vec2(340, 160));

	auto tpAction_2 = ProgressTo::create(2, 100);
	tpProgressTimer_2->runAction(RepeatForever::create(tpAction_2));
}

//------------------------------------------------------------------
//
// SpriteProgressBarTintAndFade
//
//------------------------------------------------------------------

void HelloWorld::SpriteProgressBarTintAndFade()
{
	auto tpAction_0 = ProgressTo::create(6, 100);

	auto tpAction_1 = Sequence::create(TintTo::create(1, 255, 0, 0),
		TintTo::create(1, 0, 255, 0),
		TintTo::create(1, 0, 0, 255),
		NULL);

	auto tpAction_2 = Sequence::create(FadeTo::create(1.0f, 0),
		FadeTo::create(1.0f, 255),
		NULL);





	auto tpProgressTimer_0 = ProgressTimer::create(mpSpriteA);
	tpProgressTimer_0->addChild(LabelTTF::create("Tint", "Marker Felt", 20.0f));
	this->addChild(tpProgressTimer_0);




	tpProgressTimer_0->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_0->setMidpoint(Vec2(0.5f, 0.5f));
	tpProgressTimer_0->setBarChangeRate(Vec2(1, 0));
	tpProgressTimer_0->setPosition(Vec2(140, 160));

	tpProgressTimer_0->runAction(RepeatForever::create(tpAction_0->clone()));
	tpProgressTimer_0->runAction(RepeatForever::create(tpAction_1->clone()));






	auto tpProgressTimer_1 = ProgressTimer::create(mpSpriteB);
	tpProgressTimer_1->addChild(LabelTTF::create("Fade", "Marker Felt", 20.0f));
	this->addChild(tpProgressTimer_1);




	tpProgressTimer_1->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_1->setMidpoint(Vec2(0.5f, 0.5f));
	tpProgressTimer_1->setBarChangeRate(Vec2(1, 1));
	tpProgressTimer_1->setPosition(Vec2(240, 160));

	tpProgressTimer_1->runAction(RepeatForever::create(tpAction_0->clone()));
	tpProgressTimer_1->runAction(RepeatForever::create(tpAction_2->clone()));






	auto tpProgressTimer_2 = ProgressTimer::create(mpSpriteA);
	tpProgressTimer_2->addChild(LabelTTF::create("Tint and Fade", "Marker Felt", 20.0f));
	this->addChild(tpProgressTimer_2);


	tpProgressTimer_2->setType(ProgressTimer::Type::BAR);
	tpProgressTimer_2->setMidpoint(Vec2(0.5f, 0.5f));
	tpProgressTimer_2->setBarChangeRate(Vec2(0, 1));
	tpProgressTimer_2->setPosition(Vec2(340, 160));

	tpProgressTimer_2->runAction(RepeatForever::create(tpAction_0->clone()));
	tpProgressTimer_2->runAction(RepeatForever::create(tpAction_1->clone()));
	tpProgressTimer_2->runAction(RepeatForever::create(tpAction_2->clone()));



}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
