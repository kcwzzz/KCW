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
	Sprite *mpActor;
	Vec2 mVec;
	Texture2D *mpTexture = NULL;

	Animation *mpAnimationLt = NULL;
	Animate *mpAnimateLt = NULL;

	Animation *mpAnimationRt = NULL;
	Animate *mpAnimateRt = NULL;

	Animation *mpAnimationUp = NULL;
	Animate *mpAnimateUp = NULL;

	Animation *mpAnimationDown = NULL;
	Animate *mpAnimateDown = NULL;

	Animate *mpCurAnimate = NULL;	//현재 Animate정보


	int mState = 0;			//Actor 상태 FSM
	int mLevel = 0;

	float mEXP = 0.0f;
	float mHP = 0.0f;
	float mAP = 0.0f;
	float mDefence = 0.0f;
	float mSpeed = 0.0f;
	float mSpeedRatio = 1.0f;



	int mDir = 0;		//0:up, 1: down, 2: left, 3: right



	float mDirX = 0.0f;
	float mDirY = 0.0f;
			
	Node *mpScene = NULL;
	CVirtualPad *mpVirtualPad = NULL;	

public:
	virtual void Clear();
	virtual void CreateTexture();

	void CreateAnimation();
	void CreateSprite();
	virtual void SetScene(Node *tpScene);
	virtual void SetVirtualPad(CVirtualPad *tpVirtualPad);

	void CreateAniMoveUp();
	void CreateAniMoveDown();
	void CreateAniMoveLeft();
	void CreateAniMoveRight();

	void AnimationFSMSelector();
	void RunAnimation();

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

	Sprite *GetSprite();

public:
	CActor();
	virtual ~CActor();
};