#include "CVirtualPad.h"

#include "GameScene.h"

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
	sprite->setOpacity(100);
	_joystickPad = sprite;
	layer->addChild(sprite);

	sprite = Sprite::create("CloseSelected.png");
	sprite->setPosition(tVec);
	sprite->setScale(PADSIZE);
	sprite->setOpacity(150);
	layer->addChild(sprite);
	_joystick = sprite;

	_startPoint = tVec;
	_joystickTouched = false;


}

float CVirtualPad::getDLength()
{
	_joystickPoint = _joystick->getPosition();

	return _dLength = sqrtf((_startPoint.x - _joystickPoint.x)
		*(_startPoint.x - _joystickPoint.x) + (_startPoint.y - _joystickPoint.y)
		*(_startPoint.y - _joystickPoint.y)) / 
		((_joystickPad->getContentSize().width / 2)*PADSIZE);
}

Point CVirtualPad::getDPoint()
{
	_joystickPoint = _joystick->getPosition();
	_dPoint.x = (_joystickPoint.x - _startPoint.x) / ((_joystickPad->getContentSize().width / 2)*PADSIZE);
	_dPoint.y = (_joystickPoint.y - _startPoint.y) / ((_joystickPad->getContentSize().width / 2)*PADSIZE);
	return _dPoint;
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

			if (_joystickPad->getBoundingBox().containsPoint(tap) && _joystickTouched == false) {

				_joystick->setPosition(touch->getLocation());
				_joystickTouched = true;
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

	if (_joystickTouched) {

		for (int i = 0; i<touches.size(); i++) {

			touch = (Touch*)(*it);
			if (touch) {
				tap = touch->getLocation();
				CCLOG("%f , %f", tap.x, _startPoint.x + (_joystickPad->getContentSize().width / 2)*PADSIZE);

				if (tap.x>_startPoint.x + (_joystickPad->getContentSize().width / 2)*PADSIZE) {
					ntap.x = _startPoint.x + (_joystickPad->getContentSize().width / 2)*PADSIZE;
				}
				else if (tap.x<_startPoint.x - (_joystickPad->getContentSize().width / 2)*PADSIZE) {
					ntap.x = _startPoint.x - (_joystickPad->getContentSize().width / 2)*PADSIZE;
				}
				else {
					ntap.x = tap.x;
				}



				if (tap.y>_startPoint.y + (_joystickPad->getContentSize().height / 2)*PADSIZE) {
					ntap.y = _startPoint.y + (_joystickPad->getContentSize().height / 2)*PADSIZE;
				}
				else if (tap.y<_startPoint.y - (_joystickPad->getContentSize().height / 2)*PADSIZE) {
					ntap.y = _startPoint.y - (_joystickPad->getContentSize().height / 2)*PADSIZE;
				}
				else {
					ntap.y = tap.y;
				}
				
				_joystick->setPosition(ntap);
				
			}
			it++;
		}
	}
}

void CVirtualPad::TouchesEnded(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{
	_joystick->setPosition(_startPoint);
	_joystickTouched = false;
}

void CVirtualPad::TouchesCancelled(const std::vector<Touch *> &touches, cocos2d::Event *unused_event)
{

	_joystick->setPosition(_startPoint);
	_joystickTouched = false;
}