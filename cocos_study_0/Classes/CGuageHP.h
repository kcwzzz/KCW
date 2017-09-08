#pragma once

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

class CGuageHP
{
protected:
	static CGuageHP *mpInstance;
	
	float mMaxHP = 0.0f;
	float mCurHP = 0.0f;
	float mHPUIRatio = 0.0f;

	char tszTemp[64];
	Sprite* mpSprGuargeBar = NULL;
	Sprite* mpSprHalfHPBar = NULL;
	Sprite* mpSprBGbar = NULL;

	ProgressTimer *mpProgressTimer = NULL;
	ProgressTimer *mpProgressTimerHalf = NULL;

	Label *mpHPbar= NULL;

	Node *mpParentNode = NULL;

public:
	CGuageHP();
	~CGuageHP();

	static CGuageHP *Getinstance();


	void Create(float tCurHP, float tMaxHP);


	void SetScene(Node *tpParentNode);
	void SetCurHP(int tCurHP);

	void AddToScene();
	void RemoveFromScene();

	void PrintScore();

	void SetPosition(Vec2 tVec);

	void BuildGuageWithDamage(float tDamage);

	void Destroy();

};
