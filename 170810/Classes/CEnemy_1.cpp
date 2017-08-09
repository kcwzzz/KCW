#include "CEnemy_1.h"
#include "cocos2d.h"

#include "GameScene.h"
#include "CEnemyBullet.h"

USING_NS_CC;


CEnemy_1::CEnemy_1()
{
	Clear();
}

CEnemy_1::~CEnemy_1()
{

}

void CEnemy_1::Create()
{
	mpUnitImage = Sprite::create("coin.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));

	mSpeedPower = 300.0f;
	mCharacterHP = 100.0f;
}

void CEnemy_1::Build()
{
	mpScene->addChild(mpUnitImage, 10);
}


void CEnemy_1::Update(float dt)
{
	mVec.y = mVec.y - mSpeedPower*dt;

	setPosition(mVec);
}

void CEnemy_1::ReadyToFire(float dt)
{

}

void CEnemy_1::SetScene(GameScene *tpScene)
{
	CUnit::SetScene(tpScene);

}

void CEnemy_1::Destroy()
{
	mpScene->removeChild(mpUnitImage, 10);
}