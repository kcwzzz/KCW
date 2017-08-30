#include "CVirtualPad.h"
#include "GameScene.h"
#include "CActor.h"

USING_NS_CC;
using namespace cocos2d;

CVirtualPad::CVirtualPad()
{

}

CVirtualPad::~CVirtualPad()
{

}

void CVirtualPad::create(Layer* layer, Vec2 tVec)
{
	auto sprite = Sprite::create("coin.png");
	sprite->setPosition(tVec);
	sprite->setScale(PADSIZE);
	//sprite->setOpacity(100);
	mpSprJoysticPad = sprite;
	layer->addChild(sprite, 20);

	sprite = Sprite::create("CloseSelected.png");
	sprite->setPosition(tVec);
	sprite->setScale(PADSIZE);
	//sprite->setOpacity(150);
	layer->addChild(sprite, 30);
	mpSprJoystic = sprite;

	mVecStart = tVec;
	mpJoysticTouched = false;
}

float CVirtualPad::GetPadScale()
{
	float tScale = 0.0f;
	tScale = (mpSprJoysticPad->getContentSize().width / 2)*PADSIZE;//������

	return tScale;
}

float CVirtualPad::GetDistance()
{
	float tDistance = 0.0f;
	mVecJoystic = mpSprJoystic->getPosition();
	tDistance = sqrt((mVecStart.x - mVecJoystic.x)
		*(mVecStart.x - mVecJoystic.x) + (mVecStart.y - mVecJoystic.y)
		*(mVecStart.y - mVecJoystic.y));

	mDisatance = tDistance / GetPadScale();

	return mDisatance;
}

Vec2 CVirtualPad::GetVec()
{

	mVecJoystic = mpSprJoystic->getPosition();
	mVec.x = (mVecJoystic.x - mVecStart.x) / GetPadScale();
	mVec.y = (mVecJoystic.y - mVecStart.y) / GetPadScale();

	return mVec;
}

void CVirtualPad::TouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{
	std::vector<Touch *>::const_iterator it = touches.begin();

	Touch* touch;
	Vec2 tap;


	for (int i = 0; i < touches.size(); i++) {
		touch = (Touch*)(*it);
		if (touch) {
			tap = touch->getLocation();

			if (mpSprJoysticPad->getBoundingBox().containsPoint(tap) && mpJoysticTouched == false)
			{

				mpSprJoystic->setPosition(touch->getLocation());
				mpJoysticTouched = true;
			}

		}
		it++;
	}
}


void CVirtualPad::TouchesMoved(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{
	std::vector<Touch *>::const_iterator it = touches.begin();
	Touch* touch;
	Vec2 tap;
	float theta = 0.0f;

	if (mpJoysticTouched) {
		mActorFSM = MOVE;
		for (int i = 0; i < touches.size(); i++)
		{

			touch = (Touch*)(*it);
			if (touch)
			{
				tap = touch->getLocation();

				if (tap.x > mVecStart.x + GetPadScale())
				{
					mVecResult.x = mVecStart.x + GetPadScale();
				}

				else if (tap.x < mVecStart.x - GetPadScale())
				{
					mVecResult.x = mVecStart.x - GetPadScale();
				}

				else
				{
					mVecResult.x = tap.x;
				}


				if (tap.y > mVecStart.y + GetPadScale())
				{
					mVecResult.y = mVecStart.y + GetPadScale();
				}
				else if (tap.y < mVecStart.y - GetPadScale())
				{
					mVecResult.y = mVecStart.y - GetPadScale();
				}

				else {
					mVecResult.y = tap.y;
				}

				mpSprJoystic->setPosition(mVecResult);
			}
			it++;
		}
	}
}

void CVirtualPad::TouchesEnded(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{

	mpSprJoystic->setPosition(mVecStart);
	mpJoysticTouched = false;
	mActorFSM = IDLE;
	
}

void CVirtualPad::TouchesCancelled(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{

	mpSprJoystic->setPosition(mVecStart);
	mpJoysticTouched = false;
}

Vec2 CVirtualPad::GetVecResult()
{
	Vec2 tVecResult;

	tVecResult.x = mVecResult.x - mVecStart.x;
	tVecResult.y = mVecResult.y - mVecStart.y;

	return tVecResult;
}

float CVirtualPad::GetResultDistance()
{
	float t = 0.0f;

	t = sqrt((mVecResult.x - mpSprJoysticPad->getPosition().x)*(mVecResult.x - mpSprJoysticPad->getPosition().x)
		+ (mVecResult.y - mpSprJoysticPad->getPosition().y)*(mVecResult.y - mpSprJoysticPad->getPosition().y));

	return t;
}

bool CVirtualPad::GetStateJoyStic()
{
	return mpJoysticTouched;
}

int CVirtualPad::GetDir()
{
	float tVecX = mVecResult.x - mVecStart.x;
	float tVecY = mVecResult.y - mVecStart.y;

	if (tVecY >= 0 && tVecY >= tVecX && tVecY >= -tVecX)
	{
		mDir = 0;
	}

	else if (tVecY < 0 && tVecX > tVecY && tVecY < -tVecX)
	{
		mDir = 1;
	}

	else if (tVecX < 0 && tVecX <= tVecY && tVecY < -tVecX)
	{
		mDir = 2;
	}

	else if (tVecX >= 0 && tVecX > tVecY && tVecY >= -tVecX)
	{
		mDir = 3;
	}
	return mDir;
}

void CVirtualPad::GetIsAttack()
{
	mActorFSM = ATTACK;
}

void CVirtualPad::GetIsIdle()
{
	mActorFSM = IDLE;
}

int CVirtualPad::GetActorFSM()
{
	return mActorFSM;
}