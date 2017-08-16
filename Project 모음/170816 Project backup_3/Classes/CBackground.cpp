#include "CBackground.h"

#include "CActor.h"
#include "GameScene.h"

using namespace cocos2d;

#define Map_Height 768
#define Map_Height_Reverse -768
#define Map_Width 1024
#define Map_Width_Reverse -1024

void CBackground:: Create()
{
	mpSpriteA = Sprite::create("BackGround_0.jpg");
	mpSpriteA->retain();

	mpSpriteB = Sprite::create("BackGround_1.jpg");
	mpSpriteB->retain();

	mpSpriteC = Sprite::create("BackGround_2.jpg");
	mpSpriteC->retain();

	mpSpriteD = Sprite::create("BackGround_3.jpg");
	mpSpriteD->retain();
}

void CBackground::SetAnchorPoint(Vec2 tVec)
{
	mpSpriteA->setAnchorPoint(tVec);
	mpSpriteB->setAnchorPoint(tVec);
	mpSpriteC->setAnchorPoint(tVec);
	mpSpriteD->setAnchorPoint(tVec);
}

void CBackground::SetPosition()
{
	mVecBackgroundA.x = 0;
	mVecBackgroundA.y = 0;
	mpSpriteA->setPosition(mVecBackgroundA);

	mVecBackgroundB.x = 0;
	mVecBackgroundB.y = Map_Height;
	mpSpriteB->setPosition(mVecBackgroundB);

	mVecBackgroundC.x = Map_Width;
	mVecBackgroundC.y = 0;
	mpSpriteC->setPosition(mVecBackgroundC);

	mVecBackgroundD.x = Map_Width;
	mVecBackgroundD.y = Map_Height;
	mpSpriteD->setPosition(mVecBackgroundD);
}

void CBackground::ParallaxBackground()
{
	mpParallaxNode = new ParallaxNode();
	mpParallaxNode->addChild(mpSpriteA, 1, Vec2(1.0f, 1.0f), Vec2(0, 0));
	mpParallaxNode->addChild(mpSpriteB, 1, Vec2(1.0f, 1.0f), Vec2(0, Map_Height));
	mpParallaxNode->addChild(mpSpriteC, 1, Vec2(1.0f, 1.0f), Vec2(Map_Width, 0));
	mpParallaxNode->addChild(mpSpriteD, 1, Vec2(1.0f, 1.0f), Vec2(Map_Width, Map_Height));
}
void CBackground::Build()
{
	mpScene->addChild(mpParallaxNode, 0);
}

void CBackground::MoveBackground(float t)
{

	auto moveStepX = 3;
	auto moveStepY = 3;
	
	if (mpActor->GetDirectionX() < 0)
	{
		moveStepX = -3;
	}
	else if (mpActor->GetDirectionX() > 0)
	{
		moveStepX = 3;
	}

	if (mpActor->GetDirectionX() < 0)
	{
		moveStepY = -3;
	}
	else if (mpActor->GetDirectionX() > 0)
	{
		moveStepY = 3;
	}
	auto newPos = Vec2(mpActor->GetVec().x + moveStepX, mpActor->GetVec().y+moveStepY);

	mpActor->setPosition(newPos);
	mpScene->runAction(Follow::create(mpActor->GetSprite(), Rect(0, 0, 2048, 768*2)));
}


void CBackground::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CBackground::SetActor(CActor *tpActor)
{
	mpActor = tpActor;
}