#pragma once

#include "cocos2d.h"
#include <vector>


using namespace std;
using namespace cocos2d;

class CVirtualPad;

class GameScene;

class CUILayer : public Layer
{
protected:
	GameScene *mpScene = NULL;

protected:

	Layer *mpUILayer = NULL;
	CVirtualPad	*mpVirtualPad = NULL;
	Label *mpGameOverLabel = NULL;
	EventListenerTouchAllAtOnce *mpListener = NULL;

public:

	static CUILayer *create();


	void CreateLayer();
	void VirtualPad();
	void CreateBtnAttack();
	void menuAttackCallback(Ref* pSender);
	
	//void CreateBtnTestDamaged();
	//void menuAttackdCallback(Ref* pSender);
	
	void GameOver();

	CVirtualPad* GetVirtualPad();
	void SetUpListener();
	void RemoveListener();



	void SetScene(GameScene *tpScene);
	

	int GetDir();

	virtual void onTouchesBegan(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesMoved(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesEnded(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesCancelled(const vector<Touch*>&touches, Event* unused_event);
};