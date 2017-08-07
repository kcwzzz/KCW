#include "CActor.h"
#include "cocos2d.h"

#include "GameScene.h"

USING_NS_CC;

void CActor::Create()
{
	//Create
	mpUnitImage = Sprite::create("actor.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mSpeedPower = 300.0f;
}


void CActor::Build()
{
	mpScene->addChild(mpUnitImage, 10);
}