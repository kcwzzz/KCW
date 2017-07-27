//
//  CScrollBg.hpp
//  exam_scroll
//
//  Created by pokpoongryu on 2016. 7. 10..
//
//

#ifndef CScrollBg_hpp
#define CScrollBg_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d;

class CScrollBg :public cocos2d::Scene
{
protected:

	Node *mpScene = NULL;

	Sprite *mpSpriteA = NULL;
	Vec2 mVecA;

	Sprite *mpSpriteB = NULL;
	Vec2 mVecB;

	float mScrollSpeed = 0.0f;
	float mZOrder = 0.0f;
	float tHeight = 0.0f;

public:
	CScrollBg();
	~CScrollBg();


	void Create(float tScrollSpeed, float tZOrder);
	void Destroy();

	void SetScene(Node *tpScene);

	void Build();
	void UnBuild();

	void UpdateScroll(float dt);
};

#endif /* CScrollBg_hpp */
