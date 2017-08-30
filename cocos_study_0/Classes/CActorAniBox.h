#pragma once

#include "cocos2d.h"
#include <iostream>

using namespace cocos2d;
using namespace std;



class CActorAniBox
{
protected:
	Node *mpScene = NULL;
	string mAniName = "";
	float mDelayTime = 0.0f;
	Vec2 mVec;
	
	int mDir = 2;

	Sprite *mpSprite = NULL;
	Texture2D *mpTexture = NULL;
	
	Animation *mpAnimationLeft = NULL;
	Animate *mpAnimateLeft = NULL;

	Animation *mpAnimationRight = NULL;
	Animate *mpAnimateRight = NULL;

	Animation *mpAnimationUp = NULL;
	Animate *mpAnimateUp = NULL;

	Animation *mpAnimationDown = NULL;
	Animate *mpAnimateDown = NULL;

	Animate *mpCurAnimate = NULL;

	RepeatForever *RepeatForeverUp = NULL;
	RepeatForever *RepeatForeverDown = NULL;
	RepeatForever *RepeatForeverLeft = NULL;
	RepeatForever *RepeatForeverRight = NULL;


public:

	virtual void SetScene(Node *tpNode);

	virtual void CreateAniBox(string tAniName, Vec2 tVec, int tWidth, int tHeight, float tSetDelay);

	virtual void CreateTexture(string tAniName, int tWidth, int tHeight);
	virtual void SetPosition(Vec2 tVec);
		
	virtual void CreateAniMoveUp(int tWidth, int tHeight, float tSetDelay);
	virtual void CreateAniMoveDown(int tWidth, int tHeight, float tSetDelay);
	virtual void CreateAniMoveLeft(int tWidth, int tHeight, float tSetDelay);
	virtual void CreateAniMoveRight(int tWidth, int tHeight, float tSetDelay);
	
	virtual void CreateAniDamaged();

	virtual void Build();

	virtual void RunMoveAniUp();
	virtual void RunMoveAniDown();
	virtual void RunMoveAniLeft();
	virtual void RunMoveAniRight();	
	virtual void StopMoveAnimation();

	virtual void RunAttack();
	virtual void Show();
	virtual void Hide();
	virtual void UnBuild();
	virtual void Damaged();

	Sprite* GetSprite();


};