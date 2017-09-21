//
//  CActor.hpp
//  BuildAndStudio_2
//
//  Created by pokpoongryu on 2016. 8. 10..
//
//

#ifndef CActor_hpp
#define CActor_hpp

#include <stdio.h>

#include <iostream>

#include "CUnit.hpp"


using namespace std;

class CActor: public CUnit
{
private:
    
    float mSpeed = 0.0f;
    
public:
    
    bool mIsMove = false;
    
    int mCurTargetIndex = 0;
    
    std::vector<Vec2> m_RoadVec;
    
    
public:
    
    CActor();
    ~CActor();
    
    virtual void Create();
    
    
    void BeginMove();
    void UpdateMove(float dt);
};

#endif /* CActor_hpp */
