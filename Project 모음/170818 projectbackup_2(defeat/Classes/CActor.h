#pragma once

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

class GameScene;
class CVirtualPad;
class CBackgroundLayer;
class CUILayer;

class CActor
{	
private :

protected:		
	Sprite *mpSprite;
	Vec2 mVec;

	int mState = 0;			//Actor ป๓ลย FSM
	int mLevel = 0;

	float mEXP = 0.0f;
	float mHP = 0.0f;
	float mAP = 0.0f;
	float mDefence = 0.0f;
	float mSpeed = 0.0f;
	float mSpeedRatio = 1.0f;
			
	GameScene *mpScene = NULL;
	CVirtualPad *mpVirtualPad = NULL;	
	CBackgroundLayer *mpBGLayer = NULL;
	CUILayer *mpUILayer = NULL;


	float mDirX = 0.0f;
	float mDirY = 0.0f;


	
	float mDistance;
		
public:
	virtual void Clear();
	virtual void create();
	virtual void SetScene(GameScene *tpScene);
	virtual void SetVirtualPad(CVirtualPad *tpVirtualPad);
	virtual void SetBGLayer(CBackgroundLayer *tpBGLayer);
	virtual void SetUILayer(CUILayer *tpUILayer);

	virtual void CalcDir();

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