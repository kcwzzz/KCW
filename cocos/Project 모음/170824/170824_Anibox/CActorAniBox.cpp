#include "cocos2d.h"
#include "CActorAniBox.h"
#include "Define.h"
#include "HelloWorldScene.h"
void CActorAniBox::CreateAniBox(string tAniName, Vec2 tVec, int tWidth, int tHeight, float tSetDelay)
{
	this->CreateTexture(tAniName, tWidth, tHeight);

	this->SetPosition(tVec);

	this->CreateAniMoveDown(tWidth, tHeight, tSetDelay);
	this->CreateAniMoveUp(tWidth, tHeight, tSetDelay);
	this->CreateAniMoveLeft(tWidth, tHeight, tSetDelay);
	this->CreateAniMoveRight(tWidth, tHeight, tSetDelay);

	this->Build();
}

void CActorAniBox::SetScene(Node *tpNode)
{
	mpScene = tpNode;
}

void  CActorAniBox::Build()
{
	mpScene->addChild(mpSprite, 10);
}

void CActorAniBox::CreateTexture(string tAniName, int tWidth, int tHeight)
{
	mAniName = tAniName;
	mpTexture = Director::getInstance()->getTextureCache()->addImage(mAniName);
	mpSprite = Sprite::createWithTexture(mpTexture, Rect(0, 0, tWidth, tHeight));
}

void CActorAniBox::SetPosition(Vec2 tVec)
{
	mVec = tVec;

	mpSprite->setPosition(mVec);

}


void CActorAniBox::CreateAniMoveDown(int tWidth, int tHeight, float tSetDelay)
{
	mpAnimationDown = Animation::create();
	mpAnimationDown->setDelayPerUnit(tSetDelay);

	for (int i = 0; i < 3;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationDown->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * tWidth, row * tHeight, tWidth, tHeight));
	}

	mpAnimateDown = Animate::create(mpAnimationDown);
	mpAnimateDown->retain();
	RepeatForeverDown = RepeatForever::create(mpAnimateDown);
	RepeatForeverDown->retain();
}

void CActorAniBox::CreateAniMoveUp(int tWidth, int tHeight, float tSetDelay)
{
	mpAnimationUp = Animation::create();
	mpAnimationUp->setDelayPerUnit(tSetDelay);

	for (int i = 9; i < 12;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationUp->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * tWidth, row * tHeight, tWidth, tHeight));
	}

	mpAnimateUp = Animate::create(mpAnimationUp);
	mpAnimateUp->retain();
	RepeatForeverUp = RepeatForever::create(mpAnimateUp);
	RepeatForeverUp->retain();
}

void CActorAniBox::CreateAniMoveLeft(int tWidth, int tHeight, float tSetDelay)
{
	mpAnimationLeft = Animation::create();
	mpAnimationLeft->setDelayPerUnit(tSetDelay);

	for (int i = 3; i < 6;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationLeft->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * tWidth, row * tHeight, tWidth, tHeight));
	}

	mpAnimateLeft = Animate::create(mpAnimationLeft);
	mpAnimateLeft->retain();
	RepeatForeverLeft = RepeatForever::create(mpAnimateLeft);
	RepeatForeverLeft->retain();
}

void CActorAniBox::CreateAniMoveRight(int tWidth, int tHeight, float tSetDelay)
{
	mpAnimationRight = Animation::create();
	mpAnimationRight->setDelayPerUnit(tSetDelay);
	for (int i = 6; i < 9;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimationRight->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * tWidth, row * tHeight, tWidth, tHeight));
	}
	mpAnimateRight = Animate::create(mpAnimationRight);
	mpAnimateRight->retain();
	RepeatForeverRight = RepeatForever::create(mpAnimateRight);
	RepeatForeverRight->retain();
}

void CActorAniBox::RunMoveAniUp()
{
	mpSprite->runAction(RepeatForeverUp);
}

void CActorAniBox::RunMoveAniDown()
{
	mpSprite->runAction(RepeatForeverDown);
}
void CActorAniBox::RunMoveAniLeft()
{

	mpSprite->runAction(RepeatForeverLeft);
}

void CActorAniBox::RunMoveAniRight()
{
	mpSprite->runAction(RepeatForeverRight);
}

void CActorAniBox::CreateAniDamaged()
{
	
}

void CActorAniBox::StopMoveAnimation()
{
	mpSprite->stopAction(RepeatForeverUp);
	mpSprite->stopAction(RepeatForeverDown);
	mpSprite->stopAction(RepeatForeverLeft);
	mpSprite->stopAction(RepeatForeverRight);
}

void CActorAniBox::RunAttack()
{

}

void CActorAniBox::Show()
{
	mpSprite->setVisible(true);
}

void CActorAniBox::Hide()
{
	mpSprite->setVisible(false);
}

void CActorAniBox::UnBuild()
{
	mpScene->removeChild(mpSprite);
}

void CActorAniBox::Damaged()
{
	
}