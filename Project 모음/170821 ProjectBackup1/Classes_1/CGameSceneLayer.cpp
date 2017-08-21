#include "CGameSceneLayer.h"


using namespace cocos2d;

void CGameSceneLayer::CreateLayer()
{
	mpGameSceneLayer = new Layer();
	mpGameSceneLayer = Layer::create();
	mpGameSceneLayer->setAnchorPoint(Vec2(0, 0));
	mpGameSceneLayer->setPosition(Vec2(0, 0));
	this->addChild(mpGameSceneLayer, 0);
}