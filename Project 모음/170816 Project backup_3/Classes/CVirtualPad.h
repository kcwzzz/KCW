#pragma once

#include "cocos2d.h"

#define PADSIZE 0.5

using namespace cocos2d;
USING_NS_CC;

//class GameScene;

class CVirtualPad 
{

public:
	CVirtualPad();
	~CVirtualPad(void);
	
	void initPad();
	void create(Layer* layer, Point point);


	Vec2 _startPoint;
	Vec2 _joystickPoint;
	Sprite* _joystick;
	Sprite* _joystickPad;

	bool _joystickTouched;


	//--------handle direct
	Vec2 _dPoint;
	float _dLength;

	Point getDPoint();
	float getDLength();
	
	//--------touch events
	virtual void TouchesBegan(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesMoved(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesEnded(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

};