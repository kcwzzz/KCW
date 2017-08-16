#pragma once

#include "cocos2d.h"
#include <iostream>

using namespace cocos2d;
using namespace std;

//class HelloWorld;

/*  
	Hello World랑 밖에 쓸 수 없음.
	created by pokpoongryu  
	스프라이트 애니메이션을 담당하는 클래스.
 
 */
class GameScene;

class CAniBox
{
protected:
    //HelloWorld *mpScene = NULL;
    //HelloWorld가 씬그래프
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

    /*
    void Create(string tAniName, int tTotalFrameCount, float tDelayTime);
    void Destroy();
    
    void Build();       //HelloWorld에 addChild한다.
    void UnBuild();     //HelloWorld에서 removeChild한다.
    
    
    void SetScene(Node *tpScene);
    
    
    void SetPosition(Vec2 tVec);
    
    void RunAni();
    void StopAni();
    
    void Show();
    void Hide();
    
    bool IsShow();
	*/
};

