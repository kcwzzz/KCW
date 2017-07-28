#include "Scene_Map.h"
#include "SimpleAudioEngine.h"
#include "Scene_0.h"
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
	this->CreateMoles();

	//this->update();
	//메뉴버튼을 만든다.
	//this->CreateVoidArrowButtons();

	mpLayerForWorld->runAction(Follow::create(mpSprDragon, Rect(0, 0, 512, 512)));
	
	this->scheduleUpdate();

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
{/*
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
	mpSprDragon->runAction(tRepeatForever);
	*/

	mpSprDragon = Sprite::create("actor.png");

	mVecActor.x = 240.f;
	mVecActor.y = 160.f;

	mpSprDragon->setPosition(mVecActor);
	this->addChild(mpSprDragon, 10);
}
void Scene_Map::CreateMoles()
{
	mpSprMoles = Sprite::create("mole_1.png");

	mVecMoles.x = 350.f;
	mVecMoles.y = 160.0f;

	mpSprMoles->setPosition(mVecMoles);
	this->addChild(mpSprMoles, 10);
}

void Scene_Map::onEnter()
{
	Scene::onEnter();

	auto listener = EventListenerKeyboard::create();
	//listener->setSwallowTouches(true);

	listener->onKeyPressed = CC_CALLBACK_2(Scene_Map::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Scene_Map::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void Scene_Map::onExit()
{
	this->unscheduleUpdate();

	Scene::onExit();
}
void Scene_Map::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	tSpeed = 10;

	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if (mVecActor.x < 0)
		{
			mVecActor.x = mVecActor.x;
		}
		else
		{
			mVecActor.x = mVecActor.x - tSpeed;
		}
	}

	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if (mVecActor.x > 512)
		{
			mVecActor.x = mVecActor.x;
		}
		else
		{
			mVecActor.x = mVecActor.x + tSpeed;
		}
	}

	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if (mVecActor.y < 0)
		{
			mVecActor.y = mVecActor.y;
		}
		else
		{
			mVecActor.y = mVecActor.y + tSpeed;
		}
	}

	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{

		if (mVecActor.y > 512)
		{
			mVecActor.y = mVecActor.y;
		}
		else
		{
			mVecActor.y = mVecActor.y - tSpeed;
		}

	}
	mpSprDragon->setPosition(mVecActor);
}

void Scene_Map::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

}

bool Scene_Map::IsCollision()
{	
	float tRA = mpSprDragon->getContentSize().width*0.5f;
	float tRB = mpSprMoles->getContentSize().width*0.5f;

	float tL = (tRA + tRB)*(tRA + tRB);
	float tD = (mVecActor.x - mVecMoles.x)*(mVecActor.x - mVecMoles.x) + (mVecActor.y - mVecMoles.y)*(mVecActor.y - mVecMoles.y);

	if (tD <= tL)
	{
		tResult = true;
	}

	return tResult;
}

#pragma mark -
#pragma mark Touch Event Handling

void Scene_Map::update(float dt)
{
	if (true == IsCollision())
	{
		auto pScene = Scene_0::createScene();
		Director::getInstance()->replaceScene(pScene);
	}
}
/*
void Scene_Map::moveBackground(float t)
{
	auto tSpeed = 80;

	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		tSpeed = -80;
		mpSprDragon->setFlippedX(false);
	}
	else
	{
		tSpeed = 80;
		mpSprDragon->setFlippedX(true);
		// setFlippedX : 좌우 반전 setFlippe6dY : 상하 반전
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
/*
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
}*/
void Scene_Map::menuCloseCallback(Ref* pSender)
{
	//this->unscheduleUpdate();

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}