//
//  CActor.cpp
//  BuildAndStudio_2
//
//  Created by pokpoongryu on 2016. 8. 10..
//
//

#include "CActor.hpp"



#include <math.h> //in C
#include <cmath> // in C++

//#define EPSILON 0.00001  //정확도.
#define EPSILON 0.00001  //정확도.

bool DoFloatCompare(float tA, float tB)
{
    return fabs(tA-tB) < EPSILON;
}




CActor::CActor()
{
    
    
    
}
CActor::~CActor()
{
    
}

void CActor::Create()
{
    mName = "name is CActor";
    
    mpSprite = Sprite::create("actor.png");
    mpSprite->setAnchorPoint(Vec2(0, 1));
    mpSprite->retain();
    
    mSpeed = 90.0f; //1초당 90 pixel
}

void CActor::BeginMove()
{
    mIsMove = true;
    
    mCurTargetIndex = 0;
}
//경로정보들을 기반으로 이동한다. 
void CActor::UpdateMove(float dt)
{
    if( m_RoadVec.size() <= 0 )
    {
        return;
    }
    
    if( true == mIsMove )
    {
        
        int tRow = m_RoadVec[ mCurTargetIndex ].y;
        int tCol = m_RoadVec[ mCurTargetIndex ].x;
        
        
        if( mVec.y < 480 - tRow*80 )
        {
            mVec.y += mSpeed*dt;
        }
        else if( mVec.y > 480 - tRow*80)
        {
            mVec.y-= mSpeed*dt;
        }
        
        if( mVec.x < tCol*80 )
        {
            mVec.x += mSpeed*dt;
        }
        else if( mVec.x > tCol*80)
        {
            mVec.x-= mSpeed*dt;
        }
        
        mpSprite->setPosition(mVec);
        
        
        
        
        //if( mVec.x == tCol*80 && mVec.y == 480 - tRow*80 )
        
        //좌표값이 실수임을 고려하여 보정하고 비교.
        //( 실수는 수학이론을 기반으로 태어난 컴퓨터의 태생상 완벽히 표현할 수 없다 )
        if(mSpeed*dt >= fabs(mVec.x - tCol*80) )
        {
            mVec.x = tCol*80;
        }
        
        if(mSpeed*dt >= fabs(mVec.y - (480 - tRow*80) ) )
        {
            mVec.y = 480 - tRow*80;
        }
        
        if( DoFloatCompare( mVec.x, tCol*80 ) &&
           DoFloatCompare( mVec.y, 480 - tRow*80) )
        {
            mRow = tRow;
            mCol = tCol;
            
            
            mVec.x = mCol*80;
            mVec.y = 480 - mRow*80;
            
            
            mpSprite->setPosition(mVec);
            
            if( mCurTargetIndex < m_RoadVec.size() - 1 )
            {
                mCurTargetIndex++;
            }
            else
            {
                
                m_RoadVec.clear();
                
                
                mIsMove = false;
                
                mCurTargetIndex = 0;
            }
        }
        
    }
}
