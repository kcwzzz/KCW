#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    if ( !Scene::init() )
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
							
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));


//	auto tBtnTest = MenuItemImage::create(	)
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
    
	MenuItemFont::setFontSize(18);

	auto tpBtnDoSelectState = MenuItemFont::create(
		"DoSelectState",
		CC_CALLBACK_1(HelloWorld::DoSelectState, this));

	tpBtnDoSelectState->setColor(Color3B(255, 255, 255));

	auto tpBtnDoSelectType = MenuItemFont::create("DoSelectType",
		CC_CALLBACK_1(HelloWorld::DoSelectType, this));

	tpBtnDoSelectType->setColor(Color3B(255, 255, 255));
	
	auto tpBtnDoAction = MenuItemFont::create("DoAction", 
		CC_CALLBACK_1(HelloWorld::DoAction, this));

	tpBtnDoAction->setColor(Color3B(255, 255, 255));


	auto tpMenuForTest = Menu::create(tpBtnDoSelectState, tpBtnDoSelectType, tpBtnDoAction, NULL);

	tpMenuForTest->alignItemsVertically();

	tpMenuForTest->setPosition(Vec2(240, 50));

	this->addChild(tpMenuForTest);


	mplblStatus = Label::createWithTTF("State: 0 and Type: 0", "fonts/Marker Felt.ttf", 24);
	
	mplblStatus->setPosition(Vec2(440, 450));

	this->addChild(mplblStatus, 1);

	mpSprBall = Sprite::create("CloseNormal.png");
	mpSprBall->retain();

	mpSprBall->setPosition(Vec2(50, 240));
	this->addChild(mpSprBall);

	
    return true;
}


void HelloWorld::DoSelectState(Ref* pSender)
{
	if (mState < STATE_FADEIN)
	{
		mState++;

	}
	else
	{
		mState = 0;
	}
	mType = 0;

	char tszTemp[512];
	memset(tszTemp, 0, 512);
	std::sprintf(tszTemp, "State : %d, Type: %d", mState, mType);
	std::string tString = tszTemp;

	mplblStatus->setString(tString);

}


void HelloWorld::DoSelectType(Ref* pSender)
{
	if (mState < STATE_PLACE)
	{
		if (0 == mType)
		{
			mType = 1;
		}
		else
		{
			mType = 0;
		}
	}

	char tszTemp[512];
	memset(tszTemp, 0, 512);
	std::sprintf(tszTemp, "State : %d, Type: %d", mState, mType);
	std::string tString = tszTemp;

	mplblStatus->setString(tString);

}

void HelloWorld :: DoAction(Ref* pSender)
{
	mpSprBall->setPosition(Vec2(50, 240));

	if (STATE_FADEIN == mState)
	{
		mpSprBall->setOpacity(0);
	}

	DoActionWithStateAndType();
}

void HelloWorld::DoActionWithStateAndType()
{
	switch (mState)
	{
	case STATE_MOVE:
	{
		if (TYPE_TO == mType)
		{
			mpAction = MoveTo::create(2, Vec2(400, 240));
		}
		else if (TYPE_BY == mType)
		{
			mpAction = MoveBy::create(2, Vec2(400, 240));
		}

	}
	break;

	case STATE_ROTATE:
	{
		if (TYPE_TO == mType)
		{
			mpAction = RotateTo::create(2, 2, 270);
		}
		else if (TYPE_BY == mType)
		{
			mpAction = RotateBy::create(2, 2, 270);
		}

	}
	break;

	case STATE_SCALE:
	{
		if (TYPE_TO == mType)
		{
			mpAction = ScaleTo::create(2, 2.0);
		}
		else if (TYPE_BY == mType)
		{
			mpAction = ScaleBy::create(2, 2.0);
		}

	}
	break;

	case STATE_JUMP:
	{
		if (TYPE_TO == mType)
		{
			mpAction = JumpTo::create(2, Vec2(400, 240), 50, 3);

		}
		else if (TYPE_BY == mType)
		{
			mpAction = JumpTo::create(2, Vec2(400, 240), 50, 3);
		}

	}
	break;

	case STATE_TINT:
	{
		if (TYPE_TO == mType)
		{
			mpAction = TintTo::create(2, 128, 128, 128);

		}
		else if (TYPE_BY == mType)
		{
			mpAction = TintBy::create(2, 0, -30, 30);
		}

	}
	break;

	case STATE_BEZIER:
	{
		ccBezierConfig bezier1;
		bezier1.controlPoint_1 = Vec2(150, 150);
		bezier1.controlPoint_2 = Vec2(250, -150);
		bezier1.endPosition = Vec2(350, 0);

		ccBezierConfig bezier2;
		bezier2.controlPoint_1 = Vec2(200, 150);
		bezier2.controlPoint_2 = Vec2(200, 150);
		bezier2.endPosition = Vec2(350, 0);


		if (TYPE_TO == mType)
		{
			mpAction = BezierTo::create(3, bezier1);

		}
		else if (TYPE_BY == mType)
		{
			mpAction = BezierBy::create(3, bezier1);
		}

	}
	break;

	case STATE_PLACE:
	{
		mpAction = Place::create(Vec2(300, 200));
	}
	break;

	case STATE_BLINK:
	{
		mpAction = Blink::create(2, 5);

	}
	break;

	case STATE_FADEOUT:
	{
		mpAction = FadeOut::create(1.5);
	}
	break;

	case STATE_FADEIN:
	{
		mpAction = FadeIn::create(1.5);
	}
	break;
	}
	mpSprBall->runAction(mpAction);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{

	this->removeChild (mpSprBall);
	if (NULL !=	mpSprBall)
	{
		mpSprBall->release();
		mpSprBall = NULL;
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
