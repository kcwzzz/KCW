#include "Scene_Map.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Scene_Map::createScene()
{
	return Scene_Map::create();
}

// on "init" you need to initialize your instance
bool Scene_Map::init()
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
		CC_CALLBACK_1(Scene_Map::menuCloseCallback, this));

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

	 // add "Scene_Map" splash screen"
	 auto sprite = Sprite::create("Scene_Map.png");

	 // position the sprite on the center of the screen
	 sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	 // add the sprite as a child to this layer
	 this->addChild(sprite, 0);
	 */

	mpLayerForWorld = Layer::create();
	this->addChild(mpLayerForWorld);
	//

	mpLayerForUI = Layer::create();
	this->addChild(mpLayerForUI);

	//화면 픽셀 크기를 구한다.
	winSize = Director::getInstance()->getWinSize();

	//배경을 만든다.
	this->CreateBackgroundParallax();

	//드래곤을 만든다.
	this->CreateDragon();

	//메뉴버튼을 만든다.
	this->CreateVoidArrowButtons();

	mpLayerForWorld->runAction(Follow::create(mpSprDragon, Rect(0, 0, 480, 320)));

	return true;
}
//게임루프에서 호출되는 멤버함수
	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);

void Scene_Map::CreateBackgroundParallax()
{
	tMap = TMXTiledMap::create("TileMap_0.tmx");
	//tMap = TMXTiledMap::create("test.tmx");
	tMap->setAnchorPoint(Vec2(0, 0));

	auto tpNode = ParallaxNode::create();
	tpNode->addChild(tMap, 1, Vec2(1, 0), Vec2(0, 0));
	
	mpLayerForWorld->addChild(tpNode, 0);
}
void Scene_Map::CreateDragon()
{
	int tRow = 0;
	int tCol = 0;
	int ti = 0;

	auto texture = Director::getInstance()->getTextureCache()->addImage("actor.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1f);

	for (ti = 0; ti < 6; ti++)
	{
		tCol = ti % 4;
		tRow = ti / 4;
		animation->addSpriteFrameWithTexture(texture, Rect(tCol * 130, tRow * 140, 130, 140));
	}


	mpSprDragon = Sprite::createWithTexture(texture, Rect(0, 0, 130, 140));
	mpSprDragon->setPosition(Vec2(240, 160+80));
	mpLayerForWorld->addChild(mpSprDragon);

	auto animate = Animate::create(animation);
	auto tRepeatForever = RepeatForever::create(animate);

	//용이 움직이는 애니메이션 추가
	mpSprDragon->runAction(tRepeatForever);
}
void Scene_Map::CreateVoidArrowButtons()
{
	//왼쪽 화살표
	leftSprite = Sprite::create("Images/b1.png");
	leftSprite->setPosition(Vec2(180, 30));

	mpLayerForUI->addChild(leftSprite, 2);

	leftPressedSprite = Sprite::create("Images/b2.png");
	leftPressedSprite->setPosition(leftSprite->getPosition());

	mpLayerForUI->addChild(leftPressedSprite, 1);


	//오른쪽 화살표
	rightSprite = Sprite::create("Images/f1.png");
	rightSprite->setPosition(Vec2(300, 30));

	mpLayerForUI->addChild(rightSprite, 2);

	rightPressedSprite = Sprite::create("Images/f2.png");
	rightPressedSprite->setPosition(rightSprite->getPosition());

	mpLayerForUI->addChild(rightPressedSprite, 1);
}

void Scene_Map::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Scene_Map::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Scene_Map::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Scene_Map::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Scene_Map::onExit()
{
	this->unscheduleUpdate();

	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Scene::onExit();
}

#pragma mark -
#pragma mark Touch Event Handling


//손가락이 닫는 순간 호출된다.
bool Scene_Map::onTouchBegan(Touch *touch, Event *event)
{
	isLeftPressed = false;
	isRightPressed = false;

	if (true == this->isTouchInside(leftSprite, touch))
	{
		leftSprite->setVisible(false);
		isLeftPressed = true;
	}
	else if (true == this->isTouchInside(rightSprite, touch))
	{
		rightSprite->setVisible(false);
		isRightPressed = true;
	}

	if (isLeftPressed == true || isRightPressed == true)
	{
		this->startMovingBackground();
	}

	return true;
}

void Scene_Map::onTouchMoved(Touch *touch, Event *event)
{
	if (true == isLeftPressed && false == this->isTouchInside(leftSprite, touch))
	{
		leftSprite->setVisible(true);
		this->stopMovingBackground();
	}
	else if (true == isRightPressed && false == this->isTouchInside(rightSprite, touch))
	{
		rightSprite->setVisible(true);
		this->stopMovingBackground();
	}
}

void Scene_Map::onTouchEnded(Touch *touch, Event *event)
{
	if (true == isLeftPressed || true == isRightPressed)
	{
		this->stopMovingBackground();
	}

	if (true == isLeftPressed)
	{
		leftSprite->setVisible(true);
	}

	if (true == isRightPressed)
	{
		rightSprite->setVisible(true);
	}
}

bool Scene_Map::isTouchInside(Sprite *sprite, Touch *touch)
{
	auto touchVec2 = touch->getLocation();

	bool bTouch = sprite->getBoundingBox().containsPoint(touchVec2);

	return bTouch;
}

void Scene_Map::startMovingBackground()
{
	if (isLeftPressed == true && isRightPressed == true)
	{
		return;
	}
	log("start moving");

	this->schedule(schedule_selector(Scene_Map::moveBackground));

	mIsUpdate = true;


}

void Scene_Map::stopMovingBackground()
{
	log("Stop moving");
	this->unschedule(schedule_selector(Scene_Map::moveBackground));
	mIsUpdate = false;

}

void Scene_Map::moveBackground(float t)
{
	auto tSpeed = 80;

	if (isLeftPressed)
	{
		tSpeed = -80;
		mpSprDragon->setFlippedX(false);
	}
	else
	{
		tSpeed = 80;
		mpSprDragon->setFlippedX(true);
		// setFlippedX : 좌우 반전 setFlippedY : 상하 반전
	}

	auto tPos = Vec2(mpSprDragon->getPosition().x + tSpeed*t, mpSprDragon->getPosition().y);

	if (tPos.x < 0)
	{
		tPos.x = 0;

	}
	else if (tPos.x > 480)
	{
		tPos.x = 480;
	}
	else
	{
		auto tPosInNode = tPos;
		float tTileW = tMap->getTileSize().width;
		float tTileH = tMap->getTileSize().height;

		float tTotalRowCount = tMap->getMapSize().height;

		int tCol = tPosInNode.x / tTileW;
		int tRow = tTotalRowCount - tPosInNode.y / tTileH;

		log("Row : %d, Col : %d", tRow, tCol);

		int tAttribute = GetAttributeWith(tRow, tCol);
		
		if (0 != tAttribute)
		{
			tPos.x = mpSprDragon->getPosition().x;
			tPos.y = mpSprDragon->getPosition().y;
		}
	}
	mpSprDragon->setPosition(tPos);
}

void Scene_Map::update(float dt)
{
	if (true == mIsUpdate)
	{
		moveBackground(dt);
	}
}

int Scene_Map::GetAttributeWith(int tRow, int tCol)
{
	int tResult = 0;

	int tGID = tMap->getLayer("layer_tile_bg")->getTileGIDAt(Vec2(tCol, tRow));
	//int tGID = tMap->getLayer("Tile Layer 1")->getTileGIDAt(Vec2(tCol, tRow));
	Value tValue = tMap->getPropertiesForGID(tGID);


	if (false == tValue.isNull())
	{
		tResult = tValue.asValueMap()["mAttrib"].asInt();

		log("tAttrib: %d", tResult);

	}
	return tResult;
}

void Scene_Map::menuCloseCallback(Ref* pSender)
{
	//this->unscheduleUpdate();

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
}