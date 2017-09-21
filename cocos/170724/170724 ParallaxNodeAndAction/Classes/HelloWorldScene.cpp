#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

//#include "RyuAniBox.h"

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


	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
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
	this->CreateBackgroundParallax();
	this->CreateDragon();

	return true;
}


//게임루프에서 호출되는 멤버함수

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	this->unscheduleUpdate();


	/*
	mpAniIdle->UnBuild();

	if( NULL != mpAniIdle )
	{
		mpAniIdle->Destroy();

		delete mpAniIdle;
		mpAniIdle = NULL;
	}
	*/
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::CreateBackgroundParallax()
{
	ParallaxNode *tpNode = ParallaxNode::create();
	this->addChild(tpNode, 0);

	Sprite *tpBG_0 = Sprite::create("Images/background1.png");
	tpBG_0->setAnchorPoint(Vec2(0, 0));

	Sprite *tpBG_1 = Sprite::create("Images/background2.png");
	tpBG_1->setAnchorPoint(Vec2(0, 0));

	tpNode->addChild(tpBG_0, 1, Vec2(1.0f, 1.0f), Vec2(0, 0));
	tpNode->addChild(tpBG_1, 1, Vec2(1.0f, 1.0f), Vec2(512, 0));
	//addChild(변수 이름, Z높이, 이동 속도(x축 y축), 시작 위치(x축, y축));

	auto go = MoveBy::create(4, Vec2(-512, 0));
	auto goBack = go->reverse();
	auto seq = Sequence::create(go, goBack, NULL);
	auto tRepeatFoever = RepeatForever::create(seq);

	tpNode->runAction(tRepeatFoever);
}

void HelloWorld::CreateDragon()
{
	int tRow = 0;
	int tCol = 0;
	int ti = 0;

	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/dragon_animation.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (ti = 0; ti < 6; ti++)
	{
		tCol = ti % 4;
		tRow = ti / 4;
		animation->addSpriteFrameWithTexture(texture, Rect(tCol * 130, tRow * 140, 130, 140));
	}

	auto animate = Animate::create(animation);
	auto tRepeatForever = RepeatForever::create(animate);

	mpSprDragon = Sprite::createWithTexture(texture, Rect(0, 0, 130, 140));
	mpSprDragon->setPosition(Vec2(240, 160));
	this->addChild(mpSprDragon);

	//용이 움직이는 애니메이션 추가

}