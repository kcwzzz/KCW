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

}

CGuageHP::~CGuageHP()
{
	Destroy();
}


void CGuageHP:: Create(float tCurHP, float tMaxHP)
{
	mCurHP = tCurHP;
	mMaxHP = tMaxHP;

	//HPBar ³ì»ö
	mpSprGuargeBar = Sprite::create("HPbar_Green.png");
	mpSprGuargeBar->retain();

	mpProgressTimer = ProgressTimer::create(mpSprGuargeBar);
	mpProgressTimer->retain();
	mpProgressTimer->setAnchorPoint(Vec2(0, 0));
	mpProgressTimer->setType(ProgressTimer::Type::BAR);
	mpProgressTimer->setMidpoint(Vec2(0, 0));
	mpProgressTimer->setBarChangeRate(Vec2(1, 0));
	mpProgressTimer->setReverseDirection(false);
	mpProgressTimer->setPercentage(100.0f);

	//HPBar »¡°£»ö
	mpSprHalfHPBar = Sprite::create("HPbar.png");
	mpSprHalfHPBar->retain();
		
	mpProgressTimerHalf = ProgressTimer::create(mpSprHalfHPBar);
	mpProgressTimerHalf->retain();
	mpProgressTimerHalf->setAnchorPoint(Vec2(0, 0));
	mpProgressTimerHalf->setType(ProgressTimer::Type::BAR);
	mpProgressTimerHalf->setMidpoint(Vec2(0, 0));
	mpProgressTimerHalf->setBarChangeRate(Vec2(1, 0));
	mpProgressTimerHalf->setReverseDirection(false);
	mpProgressTimerHalf->setPercentage(100.0f);
	mpProgressTimerHalf->setVisible(false);

	mpSprBGbar = Sprite::create("HPbar_BG.png");
	mpSprBGbar->retain();
	mpSprBGbar->setAnchorPoint(Vec2(0, 0));

	mpHPbar = new Label();
	memset(tszTemp, 0, 64);

}

void CGuageHP::PrintScore()
{
	std::sprintf(tszTemp, "Hero HP :     %d / %d", (int)mCurHP, (int)mMaxHP);
	std::string tString = tszTemp;
	mpHPbar->setString(tString);
	mpHPbar->setSystemFontSize (25.0f);
	mpHPbar->setColor(Color3B( 0, 0, 0));
	mpHPbar->setAnchorPoint(Vec2(0, 0));
}

void CGuageHP::SetScene(Node *tpParentNode)
{
	mpParentNode = tpParentNode;

}

void CGuageHP:: AddToScene()
{
	mpParentNode->addChild(mpProgressTimer,3);
	mpParentNode->addChild(mpProgressTimerHalf,3);
	mpParentNode->addChild(mpHPbar, 5);
	mpParentNode->addChild(mpSprBGbar,1);
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
	mpSprBGbar->setPosition(tVec);
	mpHPbar->setPosition(tVec + Vec2(70,5));
}

void CGuageHP::BuildGuageWithDamage(float tDamage)
{
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


void CGuageHP::SetCurHP(int tCurHP)
{
	mCurHP = tCurHP;
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
}