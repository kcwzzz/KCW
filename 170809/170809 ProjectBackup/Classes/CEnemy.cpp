#include "CEnemy.h"
#include "cocos2d.h"

#include "GameScene.h"

USING_NS_CC;

void CEnemy::Create()
{
	//Create
	mpUnitImage = Sprite::create("coin.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mSpeedPower = 300.0f;
	mCharacterHP = 200.0f;
}


void CEnemy::Build()
{
	mpScene->addChild(mpUnitImage, 10);
}