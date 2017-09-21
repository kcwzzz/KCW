//
//  CGrid.hpp
//  exam_onemap_tileattrib
//
//  Created by pokpoongryu on 2016. 7. 16..
//
//

#ifndef CGrid_hpp
#define CGrid_hpp

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;


/*
 
     created by pokpoongryu
 
     
     이 클래스는 800*480크기의 맵을 나타내며
     Row*Col ( 6*10 ) 갯수만큼의 속성격자를 가진다.( 속성격자의 크기는 80*80 이다. )
 
 */


#define ROW_COUNT 6
#define COL_COUNT 10


#define TILE_SIZE 80


class CGrid
{
protected:
    
    Node *mpScene = NULL;
    
    
    //그리드의 관련한 데이터들.
    Node *mpNodeThis = NULL;
    //그리드의 위치.
    Vec2 mVec;
    Size mSize;
    
    
    
    //격자들을 구성하는 데이터들.
    
    //각 격자들의 표시 이미지
    Sprite *mpSprTile[ROW_COUNT][COL_COUNT];
    //격자들 이미지 번호
    int mImgTile[ROW_COUNT][COL_COUNT];
    //격자들의 속성
    //int mAttrib[ROW_COUNT][COL_COUNT];
    
    
    
    
    Sprite *mpTileSet[2] = { NULL, NULL };
    
    
    
protected:
    
    void Clear();
    
public:
    
    //격자들의 속성
    int mAttrib[ROW_COUNT][COL_COUNT];
    
    
    
    
    void Create();
    void Destroy();
    
    void SetScene( Node *tpScene );
    
    void Build();
    void UnBuild();
    
    
    int GetAttrib(int tCol, int tRow);
    
    
    void SetPos(Vec2 tVec);
    
    
    
    Vec2 GetPosition( int tRow, int tCol );
    
    
    
    
public:
    CGrid();
    ~CGrid();
    
    
    
};

#endif /* CGrid_hpp */
