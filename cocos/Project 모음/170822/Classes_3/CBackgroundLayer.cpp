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


	mpSpriteA->setPosition(Vec2(0, 0));
	mpSpriteB->setPosition(Vec2(0, Scene_Height));
	mpSpriteC->setPosition(Vec2(Scene_Width, 0));
	mpSpriteD->setPosition(Vec2(Scene_Width, Scene_Height));

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
	tpNodeMap = Node::create();
	tpNodeMap->addChild(mpSpriteA);
	tpNodeMap->addChild(mpSpriteB);
	tpNodeMap->addChild(mpSpriteC);
	tpNodeMap->addChild(mpSpriteD);

	mpParallaxNode = ParallaxNode::create();
	mpParallaxNode->addChild(tpNodeMap, 1, Vec2(1.0f, 1.0f), Vec2(0, 0));	
}
void CBackgroundLayer::Build()
{
	this->addChild(mpParallaxNode, 0);

	mpScene->addChild(this);
}

void CBackgroundLayer::MoveBackground(CActor *tpActor)
{
	this->runAction(Follow::create(tpActor->GetSprite(), Rect(0, 0, Map_Width, Map_Height)));
}

void CBackgroundLayer::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CBackgroundLayer::SetActor(CActor *tpActor)
{
	mpActor = tpActor;
}