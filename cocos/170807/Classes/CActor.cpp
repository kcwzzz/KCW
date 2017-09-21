#include "CActor.h"
#include "cocos2d.h"

USING_NS_CC;


CActor::CActor()
{
	mpUnitImage = Sprite::create("actor.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mVec.x = 240;
	mVec.y = 0;
	mpUnitImage->setPosition(mVec);

	//this->addChild(mpUnitImage, 10);
}

CActor:: ~CActor()
{


}


void CActor::Setup()
{
	mpUnitImage = Sprite::create("actor.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));
	mVec.x = 240;
	mVec.y = 0;
	mpUnitImage->setPosition(mVec);	

	//this->addChild(mpUnitImage, 10); <- 클래스로 뺀 녀석을 어떻게 
}

