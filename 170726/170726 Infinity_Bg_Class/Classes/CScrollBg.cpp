#include "CScrollBg.h"


CScrollBg::CScrollBg()
{
	mpScene = NULL;

	mpSpriteA = NULL;
	mVecA.x = 0.0f;
	mVecA.y = 0.0f;


	mpSpriteB = NULL;
	mVecB.x = 0.0f;
	mVecB.y = 0.0f;

	mScrollSpeed = 0.0f;
	mZOrder = 0.0f;
}//ÃÊ±âÈ­

CScrollBg::~CScrollBg()
{

}

void CScrollBg::Create(float tScrollSpeed, float tZOrder)
{
	mScrollSpeed = tScrollSpeed;
	mZOrder = tZOrder;



	auto tSpriteSrc = Sprite::create("bg.png");
	auto tTexture = tSpriteSrc->getTexture();

	mpSpriteA = Sprite::createWithTexture(tTexture);
	mpSpriteA->retain();
	mpSpriteA->setAnchorPoint(Vec2(0.0f, 0.0f));

	mpSpriteB = Sprite::createWithTexture(tTexture);
	mpSpriteB->retain();
	mpSpriteB->setAnchorPoint(Vec2(0.0f, 0.0f));

	mVecA.x = 0.0f;
	mVecA.y = 0.0f;
	mpSpriteA->setPosition(mVecA);

	mVecB.x = 0.0f;
	mVecB.y = mpSpriteA->getContentSize().height;
	mpSpriteB->setPosition(mVecB);

	tHeight = mpSpriteA->getContentSize().height;

}

void CScrollBg::Destroy()
{

}

void CScrollBg::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}

void CScrollBg::Build()
{
	mpScene->addChild(mpSpriteA, mZOrder);
	mpScene->addChild(mpSpriteB, mZOrder);
}

void CScrollBg:: UnBuild()
{
	mpScene->removeChild(mpSpriteA, mZOrder);
	mpScene->removeChild(mpSpriteB, mZOrder);
}

void CScrollBg::UpdateScroll(float dt)
{
	mVecA.y = mVecA.y - mScrollSpeed*dt;
	mpSpriteA->setPosition(mVecA);

	mVecB.y = mVecB.y - mScrollSpeed*dt;
	mpSpriteB->setPosition(mVecB);

	if (mVecA.y <= -tHeight)
	{
		mVecA.y = tHeight;
	}

	if (mVecB.y <= -tHeight)
	{
		mVecB.y = tHeight;
	}
}