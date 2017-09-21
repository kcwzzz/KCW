
#include "SimpleAudioEngine.h"
#include "Scene_0.h"
#include <time.h>
#include <cstdlib>

using namespace cocos2d;

USING_NS_CC;

#define Under_Grass  0				// 수풀 아래에 있는 상태
#define Upto_Grass  1				// 수풀 위로 올라오는 상태
#define Downto_Grass  2			// 수풀위에서 아래로 내려오는 상태
#define Damaged_Downto_Grass  3	// 망치에 맞고 수풀로 내려오는 상태

Scene* Scene_0::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_0::create();

	scene->addChild(layer);

	return Scene_0::create();
}


bool Scene_0::init()
{
	srand((unsigned)time(NULL));
	
	if (!Scene::init())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Scene_0::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5); 

	SetBackground();
	SetMoles();

	auto tpListener = EventListenerTouchOneByOne::create();
	tpListener->setSwallowTouches(true);
	tpListener->onTouchBegan = CC_CALLBACK_2(Scene_0::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(tpListener, this);

	this->schedule(schedule_selector(Scene_0::TestClock), 2.0f);

	mpScore = Label::createWithTTF("State: 0 and Type: 0", "fonts/Marker Felt.ttf", 24);
	mpScore->retain();
	mpScore->setPosition(Vec2(240, 290));
	mpScore->setString("Score : ");
	this->addChild(mpScore, 2);

	return true;
}

void Scene_0::SetBackground()
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

void Scene_0::SetMoles()
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

void Scene_0::MovedSetPositonMoles()
{
	auto SetPositon_0 = MoveTo::create(0.1f, (Vec2(95, 100)));
	auto SetPositon_1 = MoveTo::create(0.1f, (Vec2(240, 100)));
	auto SetPositon_2 = MoveTo::create(0.1f, (Vec2(385, 100)));

	auto SetTint_0 = TintBy::create(0.1f, 255, 255, 255);
	auto SetTint_1 = TintBy::create(0.1f, 255, 255, 255);
	auto SetTint_2 = TintBy::create(0.1f, 255, 255, 255);

	tTestMole_0->runAction(SetPositon_0->clone());
	tTestMole_1->runAction(SetPositon_1->clone());
	tTestMole_2->runAction(SetPositon_2->clone());

	tTestMole_0->runAction(SetTint_0->clone());
	tTestMole_1->runAction(SetTint_1->clone());
	tTestMole_2->runAction(SetTint_2->clone());

	tIsTrigger_0 = Under_Grass;
	tIsTrigger_1 = Under_Grass;
	tIsTrigger_2 = Under_Grass;
}
void Scene_0::TestClock(float f)
{

	int tMoleIndex = rand() % 3;

	log("tAttrib : %d", tMoleIndex);


	switch (tMoleIndex)
	{
	case 0:
	{
		tIsTrigger_0 = Upto_Grass;

		break;
	}
	case 1:
	{

		tIsTrigger_1 = Upto_Grass;
		break;
	}
	case 2:
	{

		tIsTrigger_2 = Upto_Grass;
		break;
	}
	}

	SequenceMoles();
}
void Scene_0::UpMoveMoles()
{
	auto tUpAction_Mole = MoveBy::create(0.5f, (Vec2(0, 80)));

	if (Upto_Grass == tIsTrigger_0)
	{
		tTestMole_0->runAction(tUpAction_Mole->clone());
		tIsTrigger_0 += 1;
	}

	else if (Upto_Grass == tIsTrigger_1)
	{
		tTestMole_1->runAction(tUpAction_Mole->clone());
		tIsTrigger_1 += 1;
	}

	else if (Upto_Grass == tIsTrigger_2)
	{
		tTestMole_2->runAction(tUpAction_Mole->clone());
		tIsTrigger_2 += 1;
	}
}
void Scene_0::DownMoveMoles()
{
	auto tDownAction_Mole = MoveBy::create(0.5f, (Vec2(0, -80)));

	//Downto_Grass = 2;
	if (Downto_Grass == tIsTrigger_0)
	{
		tTestMole_0->runAction(tDownAction_Mole->clone());
	}
	if (Downto_Grass == tIsTrigger_1)
	{
		tTestMole_1->runAction(tDownAction_Mole->clone());
	}
	if (Downto_Grass == tIsTrigger_2)
	{
		tTestMole_2->runAction(tDownAction_Mole->clone());
	}
}

bool Scene_0::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tTouchPos = touch->getLocation();

	auto tDamagedAction_Mole = TintTo::create(0.5f, 255, 0, 0);

	bool tIsTouch_0 = tTestMole_0->getBoundingBox().containsPoint(tTouchPos);
	bool tIsTouch_1 = tTestMole_1->getBoundingBox().containsPoint(tTouchPos);
	bool tIsTouch_2 = tTestMole_2->getBoundingBox().containsPoint(tTouchPos);

	auto move1 = Sequence::create(tDamagedAction_Mole,
		CallFunc::create(CC_CALLBACK_0(Scene_0::TestSeq, this)),
		NULL);

	tTestMole_0->runAction(move1);

	if (true == tIsTouch_0)
	{
		tTestMole_0->runAction(move1->clone());
		mScore = mScore + 10;
	}
	else if (true == tIsTouch_1)
	{
		tTestMole_1->runAction(move1->clone());

		mScore = mScore + 10;
	}
	else if (true == tIsTouch_2)
	{
		tTestMole_2->runAction(move1->clone());
		mScore = mScore + 10;
	}
	return true;
}
void Scene_0::DamagedMoles()
{
	auto tDamagedAction_Mole = TintTo::create(0.5f, 255, 0, 0);

	if (Damaged_Downto_Grass == tIsTrigger_0)
	{
		tTestMole_0->runAction(tDamagedAction_Mole->clone());
		//mScore = mScore + 10;
	}

	if (Damaged_Downto_Grass == tIsTrigger_0)
	{
		tTestMole_1->runAction(tDamagedAction_Mole->clone());
		//mScore = mScore + 10;
	}

	if (Damaged_Downto_Grass == tIsTrigger_0)
	{
		tTestMole_2->runAction(tDamagedAction_Mole->clone());
		//mScore = mScore + 10;
	}
}

void Scene_0::PrintScore()
{
	char tszTemp[512];
	memset(tszTemp, 0, 512);
	std::sprintf(tszTemp, "Score : %d", mScore);
	std::string tString = tszTemp;
	mpScore->setString(tString);
}
void Scene_0::SequenceMoles()//Sequence를 사용해서 피격 후 아래로 이동하게 해둠.
{
	auto move1 = Sequence::create(
		CallFunc::create(CC_CALLBACK_0(Scene_0::UpMoveMoles, this)),
		DelayTime::create(0.5),
		CallFunc::create(CC_CALLBACK_0(Scene_0::DownMoveMoles, this)),
		DelayTime::create(0.5),
		CallFunc::create(CC_CALLBACK_0(Scene_0::MovedSetPositonMoles, this)),
		NULL);

	tTestMole_0->runAction(move1);
}
// 색바뀌고 바닥으로 내려가는 시퀸스
void Scene_0::TestSeq()
{
	auto move1 = Sequence::create(
		CallFunc::create(CC_CALLBACK_0(Scene_0::DamagedMoles, this)),
		CallFunc::create(CC_CALLBACK_0(Scene_0::PrintScore, this)),
		DelayTime::create(0.5),
		CallFunc::create(CC_CALLBACK_0(Scene_0::DownMoveMoles, this)),
		DelayTime::create(0.5),
		CallFunc::create(CC_CALLBACK_0(Scene_0::MovedSetPositonMoles, this)),

		NULL);

	tTestMole_0->runAction(move1);
}
void Scene_0::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
