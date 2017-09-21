//
//  CUnit.cpp
//  BuildAndStudio_2
//
//  Created by pokpoongryu on 2016. 8. 9..
//
//

#include "CUnit.hpp"


CUnit::CUnit()
{
    Clear();
}
CUnit::~CUnit()
{
    
}

void CUnit::Clear()
{
    mpScene = NULL;
    
    mName = "";
    
    mpSprite = NULL;
}

void CUnit::Create()
{
    
}
void CUnit::Destroy()
{
    if( NULL != mpSprite )
    {
        mpSprite->release();
        
        mpSprite = NULL;
    }
    
    Clear();
}

void CUnit::SetScene(Node *tpScene)
{
    mpScene = tpScene;
}

void CUnit::Build()
{
    mpScene->addChild( mpSprite );
}
void CUnit::UnBuild()
{
    mpScene->removeChild( mpSprite );
}


void CUnit::SetPos(Vec2 tVec)
{
    mVec = tVec;
    
    mpSprite->setPosition( mVec );
}



void CUnit::SetPosOnGrid(int tRow, int tCol)
{
    mRow = tRow;
    mCol = tCol;
    
    
    int tY = 480 - 80*tRow;
    int tX = 80*tCol;
    
    mVec.x = tX;
    mVec.y = tY;
    
    mpSprite->setPosition( mVec );
}

int CUnit::GetRow()
{
    return mRow;
}

int CUnit::GetCol()
{
    return mCol;
}



std::string CUnit::GetName()
{
    return mName;
}