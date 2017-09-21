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

	 int mState = 0;
	 typedef void (CAniBox::*CallFuncState)(void);

	 CallFuncState mArray[4] = { &CAniBox::AniMoveUp,&CAniBox::AniMoveDown,
							 &CAniBox::AniMoveLeft ,&CAniBox::AniMoveRight };

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
	
	void SetState(int tState);
	void Execute();
};