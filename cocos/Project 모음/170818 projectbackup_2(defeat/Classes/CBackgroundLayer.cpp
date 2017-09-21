#include "CBackgroundLayer.h"

#include "CActor.h"
#include "GameScene.h"
#include "Define.h"
#include "CUILayer.h"

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

	mpScene->runAction(Follow::create(mpActor->GetSprite(), Rect(0, 0, Map_Width, Map_Height)));

}


void CBackgroundLayer::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CBackgroundLayer::SetActor(CActor *tpActor)
{
	mpActor = tpActor;
}