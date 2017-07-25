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

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
	
	// 테스트 동작용 버튼 완료시 삭제
	auto TestActionIcon = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_0(HelloWorld::TestSeq, this));

	auto BtnTest = Menu::create(TestActionIcon, NULL);
	BtnTest->setPosition(Vec2(240,50));
	BtnTest->setAnchorPoint(Vec2(0, 0));
	this->addChild(BtnTest, 5);
	//테스트 동작용 버튼 완료시 삭제

	//게임 함수들
	SetBackground();
	SetMoles();
	UpMoveMoles();	
	//DownMoveMoles();
	
	auto tpListener = EventListenerTouchOneByOne::create();

	tpListener->setSwallowTouches(true);

	tpListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(tpListener, this);


	return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

	auto tTouchPos = touch->getLocation();
	bool tIsTouch = tTestMole_0->getBoundingBox().containsPoint(tTouchPos);
	
	if (true == tIsTouch)
	{
		TestSeq();
	}
	else
	{

	}
	return true;
}

void HelloWorld::SetBackground()
{
	auto tGrass_Upper = Sprite::create("grass_upper.png");
	tGrass_Upper->setPosition(Vec2(0, 160));
	tGrass_Upper->setAnchorPoint(Vec2(0, 0));
	this->addChild(tGrass_Upper, 0);

	auto tGrass_Lower = Sprite::create("grass_lower.png");
	tGrass_Lower->setPosition(Vec2(0, 0));
	tGrass_Lower->setAnchorPoint(Vec2(0, 0));
	this->addChild(tGrass_Lower, 2);
}
void HelloWorld::SetMoles()
{
	tTestMole_0 = Sprite::create("mole_1.png");
	tTestMole_0->setPosition(Vec2(95, 100));
	this->addChild(tTestMole_0, 1);

	tTestMole_1 = Sprite::create("mole_1.png");
	tTestMole_1->setPosition(Vec2(240, 100));
	this->addChild(tTestMole_1, 1);

	tTestMole_2 = Sprite::create("mole_1.png");
	tTestMole_2->setPosition(Vec2(385, 100));
	this->addChild(tTestMole_2, 1);
}
//void HelloWorld::MoveMoles(Object *pSender)
void HelloWorld::UpMoveMoles()
{
	auto tUpAction_Mole = MoveBy::create(1.5f, (Vec2(0, 80)));
	tTestMole_0->runAction(tUpAction_Mole->clone());
	tTestMole_1->runAction(tUpAction_Mole->clone());
	tTestMole_2->runAction(tUpAction_Mole);
}
void HelloWorld::DownMoveMoles()
{
	auto tDownAction_Mole = MoveBy::create(1.5f, (Vec2(0, -80)));
	tTestMole_0->runAction(tDownAction_Mole->clone());
	tTestMole_1->runAction(tDownAction_Mole->clone());
	tTestMole_2->runAction(tDownAction_Mole);
}
void HelloWorld::DamagedMoles()
{
	auto tDamagedAction_Mole = TintTo::create(0.5f, 255,0,0);
	tTestMole_0->runAction(tDamagedAction_Mole->clone());
	tTestMole_1->runAction(tDamagedAction_Mole->clone());
	tTestMole_2->runAction(tDamagedAction_Mole);

}
//Sequence를 사용해서 피격 후 아래로 이동하게 해둠.
void HelloWorld::TestSeq()
{
	auto move1 = Sequence::create(
		CallFunc::create(CC_CALLBACK_0(HelloWorld::DamagedMoles, this)),
		CallFunc::create(CC_CALLBACK_0(HelloWorld::DownMoveMoles, this)), NULL);

	tTestMole_0->runAction(move1);
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
