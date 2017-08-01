//
//  CUnit.hpp
//  cocos_study_2
//
//  Created by YangBruce on 2017. 1. 24..
//
//

#ifndef CUnit_hpp
#define CUnit_hpp

#include <stdio.h>

class CUnit
{
private:
    int mX = 0;
    int mY = 0;
    
public:
    CUnit();
    ~CUnit();
    
    int GetX() { return mX; };
    int GetY() { return mY;  };
    
    void SetX(int tX) { mX = tX; };
    void SetY(int tY) { mX = tY; };
};


#endif /* CUnit_hpp */
