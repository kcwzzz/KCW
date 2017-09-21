#pragma once

#include "cocos2d.h"
#include <iostream>

using namespace cocos2d;
using namespace std;

class GameScene;

class CAniBox
{
protected:
	 Sprite *mpActor = NULL;
	 Texture2D *mpTexture = NULL;
	 Animation *mpAnimation = NULL;
	 Animate *mpAnimate = NULL;
	 GameScene *mpScene = NULL;
	 Vec2 mVec;

public:
    CAniBox();
    ~CAniBox();

	void Create();
	void AniMoveUp();
	void AniMoveDown();
	void AniMoveLeft();
	void AniMoveRight();

	void SetScene(GameScene *tpScene);
	void setPosition(Vec2 tVec);
	void Build();
	void RunAnimation();

};

