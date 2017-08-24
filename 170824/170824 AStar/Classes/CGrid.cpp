//
//  CGrid.cpp
//  exam_onemap_tileattrib
//
//  Created by pokpoongryu on 2016. 7. 16..
//
//

#include "CGrid.hpp"

//#include "HelloWorldScene.h"


CGrid::CGrid()
{
    Clear();
}
CGrid::~CGrid()
{
    
}


void CGrid::Clear()
{
    mVec.x = 0.0f;
    mVec.y = 0.0f;
    
    
    memset( mImgTile, 0, ROW_COUNT*COL_COUNT*sizeof(int) );
    memset( mAttrib, 0, ROW_COUNT*COL_COUNT*sizeof(int) );
    
}


void CGrid::Create()
{
    //타일 세트 준비.
    mpTileSet[0] = NULL;
    mpTileSet[0] = Sprite::create("tile_0.png");
    mpTileSet[0]->retain();
    
    
    
    mpTileSet[1] = NULL;
    mpTileSet[1] = Sprite::create("tile_1.png");
    mpTileSet[0]->retain();
    
    
    
    
    mpNodeThis = Node::create();
    mpNodeThis->retain();
    mpNodeThis->setAnchorPoint(Vec2(0,0));
    
    
    mVec.x = 0;
    mVec.y = 0;
    mpNodeThis->setPosition(mVec);
    
    
    //스프라이트 위치 설정.
    mVec.x = 0.0f;
    mVec.y = 0.0f;
    
    
    
    
    
    
    
    //타일 이미지 격자들의 이미지 인덱스 값 준비.
    mImgTile[2][0] = 1;
    mImgTile[2][1] = 1;
    mImgTile[2][2] = 1;
    
    mImgTile[2][4] = 1;
    mImgTile[3][4] = 1;
    //...
    
    
    
    
    //속성격자들의 속성값 준비.
    mAttrib[2][0] = 1;
    mAttrib[2][1] = 1;
    mAttrib[2][2] = 1;
    
    mAttrib[2][4] = 1;
    mAttrib[3][4] = 1;
    //...
    
    
}
void CGrid::Destroy()
{
    
    
    
    
    if( NULL != mpNodeThis )
    {
        mpNodeThis->release();
        mpNodeThis = NULL;
    }
    
    Clear();
}

void CGrid::SetScene( Node *tpScene )
{
    mpScene = tpScene;
}

void CGrid::Build()
{
    
    int tRow = 0;
    int tCol = 0;
    
    int tIndex = 0;
    
    for( tRow = 0; tRow<ROW_COUNT; tRow++ )
    {
        for( tCol = 0; tCol<COL_COUNT; tCol++ )
        {
            
            tIndex = mImgTile[ tRow ][ tCol ];
            
            
            
            
            auto tTexture = mpTileSet[tIndex]->getTexture();
            
            mpSprTile[ tRow ][tCol ] = Sprite::createWithTexture(tTexture);
            mpSprTile[ tRow ][tCol ]->retain();
            mpSprTile[ tRow ][tCol ]->setAnchorPoint(Vec2(0.0f, 1.0f));
            
            
            
            Vec2 tVec   = Vec2::ZERO;
            tVec.x      = tCol*TILE_SIZE;
            tVec.y      = ROW_COUNT*TILE_SIZE - tRow*TILE_SIZE;
            
            mpSprTile[ tRow ][tCol ]->setPosition( tVec );
            
            
            mpNodeThis->addChild( mpSprTile[ tRow ][tCol ] );
        }
    }
    
    
    mpScene->addChild( mpNodeThis );
    
    
    
    //자동으로 계산해주지 않는군.
    int tWidth = mpNodeThis->getContentSize().width;
    int tHeight = mpNodeThis->getContentSize().height;
    
    log("Grid:With,Height: %d, %d ", tWidth, tHeight );
    
    mSize.width     = TILE_SIZE*COL_COUNT;
    mSize.height    = TILE_SIZE*ROW_COUNT;
    
    
    log("Grid:With,Height: %d, %d ", (int)mSize.width, (int)mSize.height );
    
    
}

void CGrid::UnBuild()
{
    
    Node *tpNode = mpNodeThis->getChildByName("coin_0");
    
    if( NULL !=  tpNode )
    {
        mpNodeThis->removeChild( tpNode );
    }
    
    
    
    mpScene->removeChild( mpNodeThis );
    
    
    int tRow = 0;
    int tCol = 0;
    
    for( tRow = 0; tRow<ROW_COUNT; tRow++ )
    {
        for( tCol = 0; tCol<COL_COUNT; tCol++ )
        {
            
            if( NULL != mpSprTile[ tRow ][tCol ] )
            {
                mpNodeThis->removeChild( mpSprTile[ tRow ][tCol ] );
            }
        }
    }
    
}


int CGrid::GetAttrib(int tCol, int tRow)
{
    int tResult = 0;
    
    tResult = mAttrib[tRow][tCol];
    
    return tResult;
}

void CGrid::SetPos(Vec2 tVec)
{
    mVec = tVec;
    
    mpNodeThis->setPosition( mVec );
}



Vec2 CGrid::GetPosition( int tRow, int tCol )
{
    Vec2 tResult = Vec2::ZERO;
    
    
    tResult.y = 480 - TILE_SIZE*tRow;
    tResult.x = TILE_SIZE*tCol;
    
    
    return tResult;
}

