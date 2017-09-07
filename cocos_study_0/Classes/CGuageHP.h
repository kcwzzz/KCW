#pragma once

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

class CGuageHP
{
protected:
	static CGuageHP *mpInstance;

	float mCurHP = 0.0f;
	Label *mpCurHP= NULL;
	float mMaxHP = 0.0f;

	float mHPUIRatio = 0.0f;

	Node *mpParentNode = NULL;
	Sprite* mpSprGuargeBar = NULL;
	Sprite* mpSprHalfHPBar = NULL;

	ProgressTimer *mpProgressTimer = NULL;
	ProgressTimer *mpProgressTimerHalf = NULL;

	Label *mpTitleLabel = NULL;


public:
	CGuageHP();
	~CGuageHP();

	static CGuageHP *Getinstance();

	void Clear();

	void Create(float tCurHP, float tMaxHP);
	void Destroy();

	void SetScene(Node *tpParentNode);

	void AddToScene();
	void RemoveFromScene();

	void PrintScore();

	void SetPosition(Vec2 tVec);

	void BuildGuageWithDamage(float tDamage);
};
