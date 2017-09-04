#include "CGuageHP.h"

CGuageHP::CGuageHP()
{
	Clear();
}

CGuageHP::~CGuageHP()
{
	Destroy();
}

void CGuageHP::Clear()
{
	mCurHP = 0.0f;
	mMaxHP = 0.0f;

	mHPUIRatio = 0.0f;

	mpParentNode = NULL;
	mpSprGuargeBar = NULL;
	mpProgressTimer = NULL;

}

void CGuageHP:: Create(float tCurHP, float tMaxHP)
{
	mCurHP = tCurHP;
	mMaxHP = tMaxHP;

	mpSprGuargeBar = Sprite::create("sliderProgress.png");
	mpSprGuargeBar->retain();

	mpProgressTimer = ProgressTimer::create(mpSprGuargeBar);
	mpProgressTimer->retain();

	mpProgressTimer->setAnchorPoint(Vec2(0, 0));

	mpProgressTimer->setType(ProgressTimer::Type::BAR);
	mpProgressTimer->setMidpoint(Vec2(0, 0));
	mpProgressTimer->setBarChangeRate(Vec2(1, 0));
	mpProgressTimer->setReverseDirection(false);

	mpProgressTimer->setPercentage(100.0f);
	
}

void CGuageHP::Destroy()
{
	if (NULL != mpProgressTimer)
	{
		mpProgressTimer->release();
		mpProgressTimer = NULL;
	}
	Clear();
}

void CGuageHP::SetScene(Node *tpParentNode)
{
	mpParentNode = tpParentNode;

}

void CGuageHP:: AddToScene()
{
	mpParentNode->addChild(mpProgressTimer);
}


void CGuageHP::RemoveFromScene()
{
	mpParentNode->removeChild(mpProgressTimer);
}

void CGuageHP::SetPosition(Vec2 tVec)
{
	mpProgressTimer->setPosition(tVec);
}

void CGuageHP::BuildGuageWithDamage(float tDamage)
{
	mCurHP = mCurHP - tDamage;

	float tRatio = (mCurHP*100.0f) / mMaxHP;

	mpProgressTimer->setPercentage(tRatio);

	/*
	log("%f", tRatio);

	if (tRatio < 50)
	{
		log("half");
	}
	*/

}

void Clean()
{

}
