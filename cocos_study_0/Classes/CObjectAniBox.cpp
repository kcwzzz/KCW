#include "cocos2d.h"
#include "CObjectAniBox.h"
#include "Define.h"
#include "GameScene.h"

void CObjectAniBox::CreateAniBox(string tAniName, Vec2 tVec, int tWidth, int tHeight, float tSetDelay, int tFrameCount )
{

	this->CreateTexture(tAniName, tWidth, tHeight);
	this->SetPosition(tVec);
	this->CreateAniObject(tWidth, tHeight, tSetDelay, tFrameCount);
	this->Hide();

}

void CObjectAniBox::SetScene(Node *tpNode)
{
	mpScene = tpNode;
}

void CObjectAniBox::Build()
{
	mpScene->addChild(mpSprite, 10);
}

void CObjectAniBox::CreateTexture(string tAniName, int tWidth, int tHeight)
{
	mAniName = tAniName;
	mpTexture = Director::getInstance()->getTextureCache()->addImage(mAniName);
	mpSprite = Sprite::createWithTexture(mpTexture, Rect(0, 0, tWidth, tHeight));
}

void CObjectAniBox::SetPosition(Vec2 tVec)
{
	mVec = tVec;
	mpSprite->setPosition(mVec);
}

void CObjectAniBox::CreateAniObject(int tWidth, int tHeight, float tSetDelay, int tFrameCount)
{
	mpAnimationObject = Animation::create();
	mpAnimationObject->setDelayPerUnit(tSetDelay);

	for (int i = 0; i < tFrameCount;i++)
	{
		int column = i % tFrameCount;
		int row = i / tFrameCount;
		mpAnimationObject->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * tWidth, row * tHeight, tWidth, tHeight));
	}

	mpAnimateObject = Animate::create(mpAnimationObject);
	mpAnimateObject->retain();
}

void CObjectAniBox::setRotation(int tAngle)
{
	mpSprite->setRotation(tAngle);
}

void CObjectAniBox::RunAniObject()
{
	mpSprite->runAction(mpAnimateObject);
}

void CObjectAniBox::RunAniWithCallback(CallFunc *tpFunc)
{
	//mpSprite->runAction(mpAnimateObject);

	auto tSeq = Sequence::create(
		mpAnimateObject,
		tpFunc,
		NULL);

	auto tRepeat = Repeat::create(tSeq, 1);

	mpSprite->runAction(tRepeat);

}

	/*
	void CObjectAniBox::OnCompleteAni()
	{
		int tA = 0;
	}
	*/


void CObjectAniBox::StopAnimation()
{
	mpSprite->stopAction(mpAnimateObject);	
}

void CObjectAniBox::Show()
{
	mpSprite->setVisible(true);
}

void CObjectAniBox::Hide()
{
	mpSprite->setVisible(false);
}