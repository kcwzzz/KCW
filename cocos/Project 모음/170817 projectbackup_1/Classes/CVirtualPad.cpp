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
	layer->addChild(sprite,20);

	sprite = Sprite::create("CloseSelected.png");
	sprite->setPosition(tVec);
	sprite->setScale(PADSIZE);
	//sprite->setOpacity(150);
	layer->addChild(sprite,30);
	mpSprJoystic = sprite;

	mVecStart = tVec;
	mpJoysticTouched = false;
}

float CVirtualPad::GetDistance()
{
	mVecJoystic = mpSprJoystic->getPosition();
	mDisatance = sqrt((mVecStart.x - mVecJoystic.x)
		*(mVecStart.x - mVecJoystic.x) + (mVecStart.y - mVecJoystic.y)
		*(mVecStart.y - mVecJoystic.y)) /
		((mpSprJoysticPad->getContentSize().width / 2)*PADSIZE);

	return mDisatance;
}

Vec2 CVirtualPad::GetVec()
{

	mVecJoystic = mpSprJoystic->getPosition();
	mVec.x = (mVecJoystic.x - mVecStart.x) / ((mpSprJoysticPad->getContentSize().width / 2)*PADSIZE);
	mVec.y = (mVecJoystic.y - mVecStart.y) / ((mpSprJoysticPad->getContentSize().width / 2)*PADSIZE);
	return mVec;
}


void CVirtualPad::TouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{
	std::vector<Touch *>::const_iterator it = touches.begin();

	Touch* touch;
	Vec2 tap;

	for (int i = 0; i<touches.size(); i++) {
		touch = (Touch*)(*it);
		if (touch) {
			tap = touch->getLocation();

			if (mpSprJoysticPad->getBoundingBox().containsPoint(tap) && mpJoysticTouched == false) {

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
	Vec2 ntap;

	if (mpJoysticTouched) {

		for (int i = 0; i<touches.size(); i++) {

			touch = (Touch*)(*it);
			if (touch) {
				tap = touch->getLocation();
				CCLOG("%f , %f", tap.x, mVecStart.x + (mpSprJoysticPad->getContentSize().width / 2)*PADSIZE);

				if (tap.x>mVecStart.x + (mpSprJoysticPad->getContentSize().width / 2)*PADSIZE) {
					ntap.x = mVecStart.x + (mpSprJoysticPad->getContentSize().width / 2)*PADSIZE;
				}
				else if (tap.x<mVecStart.x - (mpSprJoysticPad->getContentSize().width / 2)*PADSIZE) {
					ntap.x = mVecStart.x - (mpSprJoysticPad->getContentSize().width / 2)*PADSIZE;
				}
				else {
					ntap.x = tap.x;
				}



				if (tap.y>mVecStart.y + (mpSprJoysticPad->getContentSize().height / 2)*PADSIZE) {
					ntap.y = mVecStart.y + (mpSprJoysticPad->getContentSize().height / 2)*PADSIZE;
				}
				else if (tap.y<mVecStart.y - (mpSprJoysticPad->getContentSize().height / 2)*PADSIZE) {
					ntap.y = mVecStart.y - (mpSprJoysticPad->getContentSize().height / 2)*PADSIZE;
				}
				else {
					ntap.y = tap.y;
				}
				
				mpSprJoystic->setPosition(ntap);
				
			}
			it++;
		}
	}
}

void CVirtualPad::TouchesEnded(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{
	mpSprJoystic->setPosition(mVecStart);
	mpJoysticTouched = false;
}

void CVirtualPad::TouchesCancelled(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{

	mpSprJoystic->setPosition(mVecStart);
	mpJoysticTouched = false;
}