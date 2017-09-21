#pragma once

#include "cocos2d.h"
#include <iostream>

using namespace cocos2d;
using namespace std;

//class HelloWorld;

/*  
	Hello World�� �ۿ� �� �� ����.
	created by pokpoongryu  
	��������Ʈ �ִϸ��̼��� ����ϴ� Ŭ����.
 
 */
class GameScene;

class CAniBox
{
protected:
    //HelloWorld *mpScene = NULL;
    //HelloWorld�� ���׷���
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
    
    void Build();       //HelloWorld�� addChild�Ѵ�.
    void UnBuild();     //HelloWorld���� removeChild�Ѵ�.
    
    
    void SetScene(Node *tpScene);
    
    
    void SetPosition(Vec2 tVec);
    
    void RunAni();
    void StopAni();
    
    void Show();
    void Hide();
    
    bool IsShow();
	*/
};

