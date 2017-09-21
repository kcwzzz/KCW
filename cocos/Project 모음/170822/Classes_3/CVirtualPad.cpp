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

	sprite = Sprite::create("coin.png");
	sprite->setPosition(Vec2(800, 200));
	sprite->setScale(PADSIZE);
	layer->addChild(sprite, 20);
	mpAttackButton_0 = sprite;
}

float CVirtualPad::GetPadScale()
{
	float tScale = 0.0f;
	tScale = (mpSprJoysticPad->getContentSize().width / 2)*PADSIZE;//¹ÝÁö¸§

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

			if (mpAttackButton_0->getBoundingBox().containsPoint(tap))
			{
				mpAttackButtonTouched = true;
			//	log("Under Attack");
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

		for (int i = 0; i < touches.size(); i++) {

			touch = (Touch*)(*it);
			if (touch) {
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
	mpAttackButtonTouched = false;
}

void CVirtualPad::TouchesCancelled(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{

	mpSprJoystic->setPosition(mVecStart);
	mpJoysticTouched = false;
	mpAttackButtonTouched = false;
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

bool CVirtualPad::GetAttackButton()
{
	return mpAttackButtonTouched;
}