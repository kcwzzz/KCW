#include "CBackgroundLayer.h"

#include "CActor.h"
#include "GameScene.h"
#include "Define.h"

using namespace cocos2d;


void CBackgroundLayer:: Create()
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

void CBackgroundLayer::SetAnchorPoint(Vec2 tVec)
{
	mpSpriteA->setAnchorPoint(tVec);
	mpSpriteB->setAnchorPoint(tVec);
	mpSpriteC->setAnchorPoint(tVec);
	mpSpriteD->setAnchorPoint(tVec);
}

void CBackgroundLayer::SetPosition()
{
	mVecBackgroundA.x = 0;
	mVecBackgroundA.y = 0;
	mpSpriteA->setPosition(mVecBackgroundA);

	mVecBackgroundB.x = 0;
	mVecBackgroundB.y = Scene_Height;
	mpSpriteB->setPosition(mVecBackgroundB);

	mVecBackgroundC.x = Scene_Width;
	mVecBackgroundC.y = 0;
	mpSpriteC->setPosition(mVecBackgroundC);

	mVecBackgroundD.x = Scene_Width;
	mVecBackgroundD.y = Scene_Height;
	mpSpriteD->setPosition(mVecBackgroundD);
}

void CBackgroundLayer::ParallaxBackground()
{
	mpParallaxNode = new ParallaxNode();
	mpParallaxNode->addChild(mpSpriteA, 1, Vec2(1.0f, 1.0f), Vec2(0, 0));
	mpParallaxNode->addChild(mpSpriteB, 1, Vec2(1.0f, 1.0f), Vec2(0, Scene_Height));
	mpParallaxNode->addChild(mpSpriteC, 1, Vec2(1.0f, 1.0f), Vec2(Scene_Width, 0));
	mpParallaxNode->addChild(mpSpriteD, 1, Vec2(1.0f, 1.0f), Vec2(Scene_Width, Scene_Height));
}
void CBackgroundLayer::Build()
{
	mpScene->addChild(mpParallaxNode, 0);
}

void CBackgroundLayer::MoveBackground(float t)
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


void CBackgroundLayer::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CBackgroundLayer::SetActor(CActor *tpActor)
{
	mpActor = tpActor;
}