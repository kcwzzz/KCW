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

	// ���� ��ư 
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
	// ���� ��ư 

	DoSetupTitle();
	BeginTitleAction();
	CreateSlime();			// �������� �����ϴ� �Լ�


	return true;
}

void HelloWorld::DoSetupTitle()
{
	mplblTitle = Label::createWithCharMap("fonts/larabie-16.plist");
	mplblTitle->retain();
	mplblTitle->setString("HUNTSLIME!");
	mplblTitle->setPosition(400, 0);		//�⺻��ġ
	mplblTitle->setScale(4);
	this->addChild(mplblTitle);
}

void HelloWorld::BeginTitleAction()
{
	mpMove = MoveTo::create(6.0f, Vec2(400, 240));
	mpEaseMove = EaseElasticInOut::create(static_cast<ActionInterval *>(mpMove->clone()), 0.15f);
	mpFadeOut = FadeOut::create(0.7f);

	//�������� FiniteTimeAction������ �ٲ���� ����� �����ϴ� ����
	auto mpSeq = Sequence::create(
		static_cast<FiniteTimeAction *>(mpEaseMove),			//Ÿ��Ʋ�� EsMove�� ����
		static_cast<FiniteTimeAction *>(mpFadeOut),				//Ÿ��Ʋ�� ������� ��.
		CallFunc::create(CC_CALLBACK_0(HelloWorld::OnCompleteEndTileAction, this)),			//Ÿ��Ʋ�� ������� �������� ���̵����Ѵ�.
		NULL);

	mplblTitle->runAction(mpSeq);
}

void HelloWorld::CreateSlime()
{
	mpSprSlime = Sprite::create("slime.png");
	mpSprSlime->setPosition(Vec2(400, 240));
	this->addChild(mpSprSlime);
	
	DoSlimeInvisible();							//�������� ������ ���ÿ� ��������Ѵ�.
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
	Scene::onEnter();// ��� ����

	mpListener = EventListenerTouchOneByOne::create();

	mpListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);
}

void HelloWorld::onExit()
{
	//���콺 �̺�Ʈ ��� ����
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
