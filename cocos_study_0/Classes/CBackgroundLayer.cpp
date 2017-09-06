#include "CBackgroundLayer.h"

#include "CActor.h"
#include "GameScene.h"
#include "Define.h"

using namespace cocos2d;

void CBackgroundLayer::Create()
{
	mpTiledMap = TMXTiledMap::create("Dungeon_0.tmx");
	mpTiledMap->retain();
}

void CBackgroundLayer::SetAnchorPoint(Vec2 tVec)
{
	mpTiledMap->setAnchorPoint(tVec);
}

void CBackgroundLayer::SetPosition()
{
	mpTiledMap->setPosition(Vec2(0, 0));
}

void CBackgroundLayer::ParallaxBackground()
{
	mpParallaxNode = ParallaxNode::create();
	mpParallaxNode->addChild(mpTiledMap, 1, Vec2(1.0f, 1.0f), Vec2(0, 0));
}

void CBackgroundLayer::Build()
{
	this->addChild(mpParallaxNode, 0);
	mpScene->addChild(this);

}

void CBackgroundLayer::MoveBackground(CActor *tpActor)
{
	this->runAction(Follow::create(tpActor->GetSprite(), Rect(0, 0, Map_Width, Map_Height)));
}

void CBackgroundLayer::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CBackgroundLayer::SetActor(CActor *tpActor)
{
	mpActor = tpActor;
}

//int CBackgroundLayer::GetAttributeWith(int tRow, int tCol)
int CBackgroundLayer::GetAttributeWith(int tRow, int tCol, int tWidth, int tHeight)
{
	int tResult = 0;
	int tResult_1 = 0;
	int tResult_2 = 0;
	int tResult_3 = 0;
	int tResult_4 = 0;


	int tGID_1 = 0;
	int tGID_2 = 0;
	int tGID_3 = 0;
	int tGID_4 = 0;

	Value tValue_1;
	Value tValue_2;
	Value tValue_3;
	Value tValue_4;

	
	tGID_1 = mpTiledMap->getLayer("Layer1")->getTileGIDAt(Vec2(tCol, tRow + tHeight / 2));
	tValue_1 = mpTiledMap->getPropertiesForGID(tGID_1);
	
	tGID_2 = mpTiledMap->getLayer("Layer1")->getTileGIDAt(Vec2(tCol, tRow - tHeight / 2));
	tValue_2 = mpTiledMap->getPropertiesForGID(tGID_2);
	
	tGID_3 = mpTiledMap->getLayer("Layer1")->getTileGIDAt(Vec2(tCol -  tWidth /2 , tRow));
	tValue_3 = mpTiledMap->getPropertiesForGID(tGID_3);

	tGID_4 = mpTiledMap->getLayer("Layer1")->getTileGIDAt(Vec2(tCol +  tWidth /2 , tRow));
	tValue_4 = mpTiledMap->getPropertiesForGID(tGID_4);
	
	if (false == tValue_1.isNull())
	{
		tResult_1 = tValue_1.asValueMap()["Attribute"].asInt();
	}

	if (false == tValue_2.isNull())
	{
		tResult_2 = tValue_2.asValueMap()["Attribute"].asInt();
	}

	if (false == tValue_3.isNull())
	{
		tResult_3 = tValue_3.asValueMap()["Attribute"].asInt();
	}

	if (false == tValue_4.isNull())
	{
		tResult_4 = tValue_4.asValueMap()["Attribute"].asInt();
	}

	if (false == tResult_1 && false == tResult_2 && false == tResult_3 && false == tResult_4)
	{
		tResult = 0;
	}
	else if (true == tResult_1)
	{
		// 위 충돌
		tResult = 1;
	}

	else if (true == tResult_2)
	{
		//아래 충돌
		tResult = 2;
	}
	else if (true == tResult_3)
	{
		//좌 충돌
		tResult = 3;
	}

	else if (true == tResult_4)
	{
		//우 충돌
		tResult = 4;
	}
	else
	{
		tResult = 5;
	}

	//log("%d %d %d %d %d", tResult_1, tResult_2, tResult_3, tResult_4,tResult);
	return tResult;
}

TMXTiledMap* CBackgroundLayer::GetTileMap()
{
	return mpTiledMap;
}
