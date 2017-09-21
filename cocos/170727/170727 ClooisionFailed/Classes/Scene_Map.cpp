/*
#include "Scene_Map.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Scene_Map::createScene()
{
	return Scene_Map::create();
}

bool Scene_Map::init()
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
		CC_CALLBACK_1(Scene_Map::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	mpListener = EventListenerTouchOneByOne::create();
	mpListener->setSwallowTouches(true);
	mpListener->onTouchBegan = CC_CALLBACK_2(Scene_Map::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);

	tMap = TMXTiledMap::create("TileMap_0.tmx");
	tMap->setAnchorPoint(Vec2(0.0f, 0.0f));

	this->addChild(tMap, 0, 11);

	int tRow = 0;
	int tCol = 0;
	for (tRow = 0; tRow < 4; tRow++)
	{
		for (tCol = 0; tCol < 4; tCol++)
		{
			int tGID = tMap->getLayer("layer_tile_bg")->getTileGIDAt(Vec2(tCol, tRow));
			Value tValue = tMap->getPropertiesForGID(tGID);

			if (false == tValue.isNull())
			{
				int tAttrib = tValue.asValueMap()["mAttrib"].asInt();

				log("tAttrib : %d", tAttrib);
			}
		}
	}

	return true;
}


bool Scene_Map::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tPos = tMap->convertTouchToNodeSpace(touch);

	float tTileW = tMap->getTileSize().width;
	float tTileH = tMap->getTileSize().height;

	float tTotalRowCount = tMap->getMapSize().height;

	int tCol = tPos.x / tTileW;
	int tRow = tTotalRowCount - tPos.y / tTileH;

	log("Row : %d, Col : %d ", tRow, tCol);

	int tResult = GetAttributeWith(tRow, tCol);
	log("GetAttributeWith : %d", tResult);

	return true;
}

int Scene_Map::GetAttributeWith(int tRow, int tCol)
{
	int tResult = 0;

	int tGID = tMap->getLayer("layer_tile_bg")->getTileGIDAt(Vec2(tCol, tRow));
	Value tValue = tMap->getPropertiesForGID(tGID);

	if (false == tValue.isNull())
	{
		tResult = tValue.asValueMap()["mAttrib"].asInt();
		log("tAttrib : %d", tResult);
	}

	return tResult;
}



void Scene_Map::menuCloseCallback(Ref* pSender)
{
	if (NULL != mpSprCoin)
	{
		mpSprCoin->release();
		mpSprCoin = NULL;
	}

	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
*/