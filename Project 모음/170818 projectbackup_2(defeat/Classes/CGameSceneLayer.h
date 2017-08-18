#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class CGameSceneLayer : public Layer
{
protected:
	Layer *mpGameSceneLayer = NULL;

public:
	void CreateLayer();

};