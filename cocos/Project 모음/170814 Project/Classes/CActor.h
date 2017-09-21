#pragma once

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

class GameScene;

class CActor  
{	
private :

protected:		
	Sprite *mpSprite;
	Vec2 mVec;

	int mState = 0;			//Actor ป๓ลย FSM
	int mLevel = 0;

	float mEXP = 0;
	float mHP = 0;
	float mAP = 0;
	float mDefence = 0;
	float mSpeed = 0;
	GameScene *mpScene = NULL;

		
public:
	virtual void Clear();
	virtual void Create();
	virtual void SetScene(GameScene *tpScene);
	virtual void setPosition(Vec2 tVec);
	virtual Vec2 GetVec();
	virtual void SetVec(Vec2 tVec);
	virtual float GetSpeedPower();
	virtual void Build();

public:
	CActor();
	virtual ~CActor();
};