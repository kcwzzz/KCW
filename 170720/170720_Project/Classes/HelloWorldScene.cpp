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

	DoSetupTitle();
	BeginTitleAction();
	CreateSlime();			// 슬라임을 생성하는 함수


	return true;
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

void HelloWorld::BeginTitleAction()
{
	mpMove = MoveTo::create(6.0f, Vec2(400, 240));
	mpEaseMove = EaseElasticInOut::create(static_cast<ActionInterval *>(mpMove->clone()), 0.15f);
	mpFadeOut = FadeOut::create(0.7f);

	//시퀀스는 FiniteTimeAction형으로 바꿔줘야 사용이 가능하다 슈벌
	auto mpSeq = Sequence::create(
		static_cast<FiniteTimeAction *>(mpEaseMove),			//타이틀을 EsMove로 설정
		static_cast<FiniteTimeAction *>(mpFadeOut),				//타이틀을 사라지게 함.
		CallFunc::create(CC_CALLBACK_0(HelloWorld::OnCompleteEndTileAction, this)),			//타이틀이 사라지면 슬라임을 보이도록한다.
		NULL);

	mplblTitle->runAction(mpSeq);
}

void HelloWorld::CreateSlime()
{
	mpSprSlime = Sprite::create("slime.png");
	mpSprSlime->setPosition(Vec2(400, 240));
	this->addChild(mpSprSlime);
	
	DoSlimeInvisible();							//슬라임을 생성과 동시에 사라지게한다.
}

void HelloWorld ::DoSlimeInvisible()
{
	mpSprSlime->setVisible(false);
}
void HelloWorld::OnCompleteEndTileAction()
{
	mpSprSlime->setVisible(true);
}


void HelloWorld::onEnter()
{
	Scene::onEnter();// 장면 진입

	mpListener = EventListenerTouchOneByOne::create();

	mpListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);
}

void HelloWorld::onExit()
{
	//마우스 이벤트 등록 해지
	_eventDispatcher->removeEventListener(mpListener);

	Scene::onExit();
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tTouchPos = touch->getLocation();

	char tszTemp[512];
	memset(tszTemp, 0, 512);
	sprintf(tszTemp, "x: %f, y: %f, ID: %d", tTouchPos.x, tTouchPos.y, touch->getID());

	std::string tString = "onTouchBegan ";
	tString = tString + tszTemp;

	bool tIsTouch = mpSprSlime->getBoundingBox().containsPoint(tTouchPos);
	
	if (true == tIsTouch)
	{
		tString = tString + ", sprite is touched.";
	}
	else
	{
		tString = tString + ", sprite is NOT touched.";
	}

	mplblTest->setString(tString);

	return true;
}

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
