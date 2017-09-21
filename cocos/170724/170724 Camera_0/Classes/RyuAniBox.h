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
class CRyuAniBox
{
protected:
	 Node *mpScene = NULL;
    //HelloWorld *mpScene = NULL;
    //HelloWorld가 씬그래프
    
    string mAniName = "";
    
    int mTotalFrameCount = 0;
    float mDelayTime = 0.0f;
    
    //코코스객체
    Sprite *tSpriteC = NULL;
    RepeatForever *tRepeatForeverC = NULL;
    
    
    
    cocos2d::Vector<SpriteFrame *> tSpriteFrameVec;
    
    
public:
    CRyuAniBox();
    ~CRyuAniBox();
    
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
};

