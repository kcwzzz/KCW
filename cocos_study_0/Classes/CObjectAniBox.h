#pragma once

#include "cocos2d.h"
#include <iostream>

using namespace cocos2d;
using namespace std;


class CObjectAniBox
{
protected:
	Node *mpScene = NULL;
	string mAniName = "";
	float mDelayTime = 0.0f;
	Vec2 mVec;
	int mFrameCount = 0;
	int mDir = 0;

	Sprite *mpSprite = NULL;
	Texture2D *mpTexture = NULL;

	Animation *mpAnimationObject = NULL;
	Animate *mpAnimateObject = NULL;

	Animate *mpCurAnimate = NULL;

public:

	void SetScene(Node *tpNode);

	void CreateAniBox(string tAniName, Vec2 tVec, int tWidth, int tHeight, float tSetDelay, int tFrameCount);

	void CreateTexture(string tAniName, int tWidth, int tHeight);
	void SetPosition(Vec2 tVec);

	void CreateAniObject(int tWidth, int tHeight, float tSetDelay, int tFrameCount);
		


	void RunAniObject();
	void RunAniWithCallback(CallFunc *tpFunc);
		//void OnCompleteAni();

	void Build();
	void setRotation(int tAngle);

	void StopAnimation();

	void Show();
	void Hide();

	Sprite* GetSprite();
};