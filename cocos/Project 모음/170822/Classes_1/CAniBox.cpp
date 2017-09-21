#include "CAniBox.h"
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;

CAniBox::CAniBox()
{
}


CAniBox::~CAniBox()
{
}


void CAniBox::Create()
{
	mpTexture = Director::getInstance()->getTextureCache()->addImage("Hero.png");
	mpAnimation = Animation::create();
	mpAnimation->setDelayPerUnit(0.3f);
}

void CAniBox::AniMoveDown()
{
	for (int i = 0; i < 3;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::AniMoveLeft()
{
	for (int i = 3; i < 6;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::AniMoveRight()
{
	for (int i = 7; i < 9;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::AniMoveUp()
{
	for (int i = 9; i < 12;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::CreateSprite()
{
	mpActor = Sprite::createWithTexture(mpTexture, Rect(0, 0, 32, 32));

}

void CAniBox::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}

void CAniBox::Build()
{
	mpScene->addChild(mpActor,10);
}

void CAniBox::RunAnimation()
{
	mpAnimate = Animate::create(mpAnimation);
	mpActor->runAction(mpAnimate);
}

void CAniBox::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpActor->setPosition(mVec);
}

void CAniBox::SetState(int tState)
{
	mState = tState;
}

void CAniBox::Execute()
{
	(this->*mArray[mState])();
}

/*

void GameScene :: AnimationFSMSelector()
{
float tVecX = 0.0f;
float tVecY = 0.0f;

tVecX = mpActor->GetDirectionX();
tVecY = mpActor->GetDirectionY();

if (tVecY >= 0 && tVecX < tVecY && tVecY > -tVecX)
{
SetState(0);
}
else if (tVecY < 0 && tVecX > tVecY && tVecY < -tVecX)
{
SetState(1);
}
else if (tVecX < 0 && tVecX < tVecY && tVecY < -tVecX)
{
SetState(2);
}
else if (tVecX >= 0 && tVecX > tVecY && tVecY > -tVecX)
{
SetState(3);
}
}
*/