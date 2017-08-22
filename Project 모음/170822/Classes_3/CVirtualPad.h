#pragma once

#include "cocos2d.h"

#define PADSIZE 1

using namespace cocos2d;
USING_NS_CC;


class CActor;

class CVirtualPad 
{

public:
	CVirtualPad();
	~CVirtualPad(void);

	void create(Layer* layer, Vec2 tVec);

	Vec2 mVecStart;			//조이스틱 기본 생성 위치
	Vec2 mVecJoystic;

	Vec2 mVecResult;

	Sprite* mpSprJoystic;
	Sprite* mpSprJoysticPad;

	Sprite* mpAttackButton_0;

	bool mpJoysticTouched = false;
	bool mpAttackButtonTouched = false;

	CActor *mpActor;


	//--------handle direct
	Vec2 mVec;
	float mDisatance;

	Vec2 GetVec();
	float GetDistance();
	float GetPadScale();
	float GetResultDistance();

	bool GetStateJoyStic();
	bool GetAttackButton();

	Vec2 GetVecResult();

	//--------touch events
	virtual void TouchesBegan(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesMoved(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesEnded(const std::vector<Touch*>&touches, Event *unused_event);
	virtual void TouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

};

