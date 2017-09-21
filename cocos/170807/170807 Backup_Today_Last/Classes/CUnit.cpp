#include "CUnit.h"
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;

CUnit::CUnit()
{

}

CUnit::~CUnit()
{

}

void CUnit::Create()
{

}


void CUnit::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CUnit::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpUnitImage->setPosition(mVec);
}

void CUnit::Build()
{

}

Vec2 CUnit::GetVec()
{
	return mVec;
}

void CUnit::SetVec(Vec2 tVec)
{
	mVec = tVec;
}

float CUnit::GetSpeedPower()
{
	return mSpeedPower;
}