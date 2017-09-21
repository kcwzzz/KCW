#pragma once

#include<stdio.h>

#include "cocos2d.h"

using namespace cocos2d;

class CGrid
{
private :
	Sprite *mpSprTileCache[2] = { NULL, NULL };
	//캐시에 타일을 넣어두고 빠르게 로딩

protected:
	Node *mpScene = NULL;

	Vec2 mVec;
	Sprite *mpSprTile[4][6];

	int mImgTile[4][6];

	int mAttrib[4][6];

	void Clear();
	
public:
	CGrid();
	~CGrid();

	void Create();
	void Destroy();

	void SetScene(Node *tpScene);
	void Build();
	void UnBuild();

	int GetAttrib(int tCol, int tRow);
};