#pragma once

#include "cocos2d.h"

using namespace cocos2d;

class CVirtualPad;

class CUILayer : public Layer
{

protected:
	Layer *mpUILayer = NULL;
	CVirtualPad	*mpVirtualPad = NULL;

public:
	void CreateLayer();
	void VirtualPad();
	void CloseGame();
	void menuCloseCallback(Ref* pSender);
};