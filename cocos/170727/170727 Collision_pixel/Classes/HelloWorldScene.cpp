#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "CScrollBg.h"

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

	auto tKeyListener = EventListenerKeyboard::create();
	tKeyListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	tKeyListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(tKeyListener, this);

	auto tBtnLt = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnLt, this));
	tBtnLt->setPosition(Vec2(50, 50));

	auto tBtnRt = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnRt, this));
	tBtnLt->setPosition(Vec2(150, 50));

	auto tBtnUp = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnUp, this));
	tBtnLt->setPosition(Vec2(100, 100));

	auto tBtnDown = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::OnClickBtnDown, this));
	tBtnLt->setPosition(Vec2(100, 50));

	auto tMenu = Menu::create(tBtnLt, tBtnRt, tBtnUp, tBtnDown, NULL);
	tMenu->setPosition(Vec2::ZERO);
	this->addChild(tMenu, 200);

	/*I
	mpSpriteA = NULL;
	mpSpriteA = Sprite :: create("enemy.png");

	mVecA.x = 240.0f;
	mVecA.y = 160.0f;
	mpSpriteA->setPosition(mVecA);
	this->addChild(mpSpriteA, 10);

	mpSpriteB = NULL;
	mpSpriteB = Sprite::create("actor.png");

	mVecB.x = 140.0f;
	mVecB.y = 160.0f;
	mpSpriteB->setPosition(mVecB);
	this->addChild(mpSpriteB, 10);

	*/

	mpSpriteA = NULL;
	mpSpriteA = Sprite::create("actor.png");

	mVecA.x = 240.0f;
	mVecA.y = 160.0f;
	mpSpriteA->setPosition(mVecA);
	this->addChild(mpSpriteA, 10);

	mpSpriteB = NULL;
	mpSpriteB = Sprite::create("idle_00.png");

	mVecB.x = 140.0f;
	mVecB.y = 160.0f;
	mpSpriteB->setPosition(mVecB);
	this->addChild(mpSpriteB, 10);

	mpScrollBgFar = NULL;
	mpScrollBgFar = new CScrollBg();
	mpScrollBgFar->Create(200.0f, 0);
	mpScrollBgFar->SetScene(this);

	mpScrollBgFar->Build();

	mpScrollBgNear = NULL;
	mpScrollBgNear = new CScrollBg();
	mpScrollBgNear->Create(400.0f, 0);
	mpScrollBgNear->SetScene(this);

	mpScrollBgNear->Build();


	Size tSizeA = mpSpriteA->getContentSize();

	pImageB = new Image();
	pImageB->initWithImageFile("idle_00.png");

	int tLen = tSizeA.width*tSizeA.height * 4;

	log("pImage: %d", tLen);

	log("pImageB.data Len: %zd", pImageB->getDataLen());


	this->scheduleUpdate();

	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	this->unscheduleUpdate();
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::update(float dt)
{
	mpScrollBgFar->UpdateScroll(dt);
	mpScrollBgNear->UpdateScroll(dt);

	//if (true == IsCollision())
	if (true == IsCollisionWithPixel())
	{
		log("collision %d", mCollisionCount);

		mCollisionCount++;
	}
}

bool HelloWorld::IsCollision()
{
	bool tResult = false;

	float tRB = mpSpriteB->getContentSize().width*0.5f;

	Rect tRectA = mpSpriteA->getBoundingBox();

	if (true == tRectA.intersectsCircle(mVecB, tRB))
	{
		tResult = true;
	}

	return tResult;
}

bool HelloWorld::IsCollisionWithPixel()
{
	bool tResult = false;

	Rect tRectA = mpSpriteA->getBoundingBox();
	Rect tRectB = mpSpriteB->getBoundingBox();

	if (true == tRectA.intersectsRect(tRectB))
	{
		Vec2 tVecIn = mpSpriteB->convertToNodeSpace(mVecA);

		int tX = tVecIn.x;
		int tY = tVecIn.y;

		if (tX <0 || tX > mpSpriteB->getContentSize().width || tY<0 || tY>mpSpriteB->getContentSize().height)
		{
			return false;
		}


		tY = mpSpriteB->getContentSize().height - tY;

		unsigned char *pData = pImageB->getData();

		int tIndex = (tY*mpSpriteB->getContentSize().width + tX) * 4 + 3;
		unsigned char tAlpha = pData[tIndex];

		if (0 != tAlpha)
		{
			tResult = true;
		}
		else
		{
			tResult = false;
		}
	}

	return tResult;
}

void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		mVecA.x = mVecA.x - 5.0f;
		mpSpriteA->setPosition(mVecA);
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		mVecA.x = mVecA.x + 5.0f;
		mpSpriteA->setPosition(mVecA);
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		mVecA.y = mVecA.y + 5.0f;
		mpSpriteA->setPosition(mVecA);
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		mVecA.y = mVecA.y - 5.0f;
		mpSpriteA->setPosition(mVecA);
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{

	}
}
void HelloWorld::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{

}
void HelloWorld::OnClickBtnLt(cocos2d::Ref *pSender)
{

}
void HelloWorld::OnClickBtnRt(cocos2d::Ref *pSender)
{

}
void HelloWorld::OnClickBtnUp(cocos2d::Ref *pSender)
{

}
void HelloWorld::OnClickBtnDown(cocos2d::Ref *pSender)
{

}