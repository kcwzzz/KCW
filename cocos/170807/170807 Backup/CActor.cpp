#include "CActor.h"
#include "cocos2d.h"

#include "GameScene.h"

USING_NS_CC;


CActor::CActor()
{

}

CActor:: ~CActor()
{


}


void CActor::Create()
{
	//Create
	mpUnitImage = Sprite::create("actor.png");
	mpUnitImage->retain();
	mpUnitImage->setAnchorPoint(Vec2(0.5, 0));	
}

void CActor::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CActor::setPosition(Vec2 tVec)
{		
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpUnitImage->setPosition(mVec);
}

void CActor::Build()
{
	mpScene->addChild(mpUnitImage, 10);
}


