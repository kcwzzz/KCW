#include "CActor.h"
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;

CActor::CActor()
{
	Clear();
}

CActor::~CActor()
{

}

void CActor::Clear()
{
	 mState = 0;			//Actor ป๓ลย FSM
	 mLevel = 0;

	 mEXP = 0;
	 mHP = 0;
	 mAP = 0;
	 mDefence = 0;
	 mSpeed = 0;
	 mVec = Vec2(0, 0);
}

void CActor::Create()
{
	mpSprite = Sprite::create("Hero.png");
	mpSprite->retain();
	mSpeed = 600.0f;
}

void CActor::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CActor::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpSprite->setPosition(mVec);
}

Vec2 CActor::GetVec()
{
	return mVec;
}

void CActor::SetVec(Vec2 tVec)
{
	mVec = tVec;
}

float CActor::GetSpeedPower()
{
	return mSpeed;
}
void CActor::Build()
{
	mpScene->addChild(mpSprite, 10);
}