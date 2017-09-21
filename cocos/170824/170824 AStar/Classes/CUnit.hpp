//
//  CUnit.hpp
//  BuildAndStudio_2
//
//  Created by pokpoongryu on 2016. 8. 9..
//
//

#ifndef CUnit_hpp
#define CUnit_hpp

#include <stdio.h>
#include <iostream>


#include "cocos2d.h"

using namespace cocos2d;

class CUnit
{
protected:
    
    Node *mpScene = NULL;
    
    
    std::string mName = "";
    
    
    Sprite *mpSprite = NULL;
    
    
    Vec2 mVec;
    
    int mRow = 0;
    int mCol = 0;
    
    
protected:
    
    void Clear();
    
public:
    
    CUnit();
    ~CUnit();
    
    virtual void Create();
    void Destroy();
    
    void SetScene(Node *tpScene);
    
    void Build();
    void UnBuild();
    
    
    void SetPos(Vec2 tVec);
    
    
    void SetPosOnGrid(int tRow, int tCol);
    
    int GetRow();
    int GetCol();
    
    
    std::string GetName();
};

#endif /* CUnit_hpp */
