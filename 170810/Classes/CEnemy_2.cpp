#include "CEnemy.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CActorBullet.h"

USING_NS_CC;

void CEnemy::Create()
{
	mpUnitImage = Sprite::create("coin.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mSpeedPower = 300.0f;
	mCharacterHP = 100.0f;
}

void CEnemy::Build()
{
	mpScene->addChild(mpUnitImage, 10);
}

void CEnemy::Destroy()
{
	mpScene->removeChild(mpUnitImage, 10);
}