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

	void SetScene(Node *tpNode);

	void CreateAniBox(string tAniName, Vec2 tVec, int tWidth, int tHeight, float tSetDelay);

	void CreateTexture(string tAniName, int tWidth, int tHeight);
	void SetPosition(Vec2 tVec);
		
	void CreateAniMoveUp(int tWidth, int tHeight, float tSetDelay);
	void CreateAniMoveDown(int tWidth, int tHeight, float tSetDelay);
	void CreateAniMoveLeft(int tWidth, int tHeight, float tSetDelay);
	void CreateAniMoveRight(int tWidth, int tHeight, float tSetDelay);

	void Build();

	void RunAniUp();
	void RunAniDown();
	void RunAniLeft();
	void RunAniRight();


	void StopAnimation();

};