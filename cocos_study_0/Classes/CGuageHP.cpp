#include "CGuageHP.h"

CGuageHP *CGuageHP::mpInstance = NULL;

CGuageHP *CGuageHP::Getinstance()
{
	if (NULL == mpInstance)
	{
		mpInstance = new CGuageHP();
		return mpInstance;
	}
	return mpInstance;
}

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

	mpSprGuargeBar = Sprite::create("HPbar_Green.png");
	mpSprGuargeBar->retain();

	mpSprHalfHPBar = Sprite::create("HPbar.png");
	mpSprHalfHPBar->retain();

	mpProgressTimer = ProgressTimer::create(mpSprGuargeBar);
	mpProgressTimer->retain();
	mpProgressTimer->setAnchorPoint(Vec2(0, 0));
	mpProgressTimer->setType(ProgressTimer::Type::BAR);
	mpProgressTimer->setMidpoint(Vec2(0, 0));
	mpProgressTimer->setBarChangeRate(Vec2(1, 0));
	mpProgressTimer->setReverseDirection(false);
	mpProgressTimer->setPercentage(100.0f);
	
	mpProgressTimerHalf = ProgressTimer::create(mpSprHalfHPBar);
	mpProgressTimerHalf->retain();
	mpProgressTimerHalf->setAnchorPoint(Vec2(0, 0));
	mpProgressTimerHalf->setType(ProgressTimer::Type::BAR);
	mpProgressTimerHalf->setMidpoint(Vec2(0, 0));
	mpProgressTimerHalf->setBarChangeRate(Vec2(1, 0));
	mpProgressTimerHalf->setReverseDirection(false);
	mpProgressTimerHalf->setPercentage(100.0f);
	mpProgressTimerHalf->setVisible(false);
}

void CGuageHP::PrintScore()
{
	char tszTemp[512];
	memset(tszTemp, 0, 512);
	std::sprintf(tszTemp, "%d / %d", mCurHP, mMaxHP);
	std::string tString = tszTemp;
	mpCurHP->setString(tString);
}

void CGuageHP::Destroy()
{
	if (NULL != mpProgressTimer)
	{
		mpProgressTimer->release();
		mpProgressTimer = NULL;
	}
	if (NULL != mpProgressTimerHalf)
	{
		mpProgressTimerHalf->release();
		mpProgressTimerHalf = NULL;
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
	mpParentNode->addChild(mpProgressTimerHalf);
	mpParentNode->addChild(mpTitleLabel, 5);
}


void CGuageHP::RemoveFromScene()
{
	mpParentNode->removeChild(mpProgressTimer);
	mpParentNode->removeChild(mpProgressTimerHalf);
}

void CGuageHP::SetPosition(Vec2 tVec)
{
	mpProgressTimer->setPosition(tVec);
	mpProgressTimerHalf->setPosition(tVec);
	mpTitleLabel->setPosition(tVec);
}

void CGuageHP::BuildGuageWithDamage(float tDamage)
{
	mCurHP = mCurHP - tDamage;
	float tRatio = mCurHP*100 / mMaxHP;
	mpProgressTimer->setPercentage(tRatio);
	mpProgressTimerHalf->setPercentage(tRatio);

	auto tint = TintTo ::create(0.1, 128, 0, 0);

	if (tRatio < 30)
	{
		mpProgressTimer->setVisible(false);
		mpProgressTimerHalf->setVisible(true);
	}

	this->PrintScore();
}

void Clean()
{

}
