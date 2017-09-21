#pragma once

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

class GameScene;
class CVirtualPad;
class CBackgroundLayer;


class CActor
{	
private :

protected:		
	Sprite *mpSprite;
	Vec2 mVec;

	int mState = 0;			//Actor ���� FSM
	int mLevel = 0;

	float mEXP = 0.0f;
	float mHP = 0.0f;
	float mAP = 0.0f;
	float mDefence = 0.0f;
	float mSpeed = 0.0f;
	float mSpeedRatio = 1.0f;

	float mDirX = 0.0f;
	float mDirY = 0.0f;
			
	Node *mpScene = NULL;
	CVirtualPad *mpVirtualPad = NULL;	
		
public:
	virtual void Clear();
	virtual void create();
	virtual void SetScene(Node *tpScene);
	virtual void SetVirtualPad(CVirtualPad *tpVirtualPad);

	virtual void CalcDir();
	void FollowActor();

	virtual void setPosition(Vec2 tVec);
	virtual Vec2 GetVec();
	virtual void SetVec(Vec2 tVec);
	virtual float GetSpeedPower();
	virtual void Build();
	virtual void MoveActor(float dt);
	virtual float IncreaseSpeed(float dt);


	float GetDirectionX();
	float GetDirectionY();


	//float GetDistance();

	Sprite *GetSprite();

public:
	CActor();
	virtual ~CActor();
};