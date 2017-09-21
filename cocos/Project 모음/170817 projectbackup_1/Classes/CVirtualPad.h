#pragma once

#include "cocos2d.h"


#define PADSIZE 1

using namespace cocos2d;
USING_NS_CC;



class CVirtualPad 
{

public:
	CVirtualPad();
	~CVirtualPad(void);
	
	//void initPad();
	void create(Layer* layer, Point point);

	Vec2 mVecStart;
	Vec2 mVecJoystic;

	Sprite* mpSprJoystic;
	Sprite* mpSprJoysticPad;

	bool mpJoysticTouched;


	//--------handle direct
	Vec2 mVec;
	float mDisatance;

	Vec2 GetVec();
	float GetDistance();
	
	//--------touch events
	virtual void TouchesBegan(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesMoved(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesEnded(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

};