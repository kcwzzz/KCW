#include "CBackgroundLayer.h"

#include "CActor.h"
#include "GameScene.h"
#include "Define.h"

using namespace cocos2d;

void CBackgroundLayer:: Create()
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