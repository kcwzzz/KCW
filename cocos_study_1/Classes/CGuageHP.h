#pragma once

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

class CGuageHP
{
protected:
	float mCurHP = 0.0f;
	float mMaxHP = 0.0f;

	float mHPUIRatio = 0.0f;

	Node *mpParentNode = NULL;
	cocos2d::Sprite* mpSprGuargeBar = NULL;
	ProgressTimer *mpProgressTimer = NULL;

public:
	CGuageHP();
	~CGuageHP();

	void Clear();
	void Clean();

	void Create(float tCurHP, float tMaxHP);
	void Destroy();

	void SetScene(Node *tpParentNode);

	void AddToScene();
	void RemoveFromScene();

	void SetPosition(Vec2 tVec);

	void BuildGuageWithDamage(float tDamage);
};
