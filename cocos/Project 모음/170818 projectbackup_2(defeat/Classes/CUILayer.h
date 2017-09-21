#pragma once

#include "cocos2d.h"
#include <vector>


using namespace std;
using namespace cocos2d;

class CVirtualPad;
class CActor;
class GameScene;


class CUILayer : public Layer
{

protected:
	Layer *mpUILayer = NULL;
	CVirtualPad	*mpVirtualPad = NULL;
	Label *mpGameOverLabel = NULL;
	EventListenerTouchAllAtOnce *mpListener = NULL;
	CActor *mpActor = NULL;
	GameScene *mpScene = NULL;


public:

	static CUILayer *create();

	void CreateLayer();
	void VirtualPad();
	void CloseGame();
	void menuCloseCallback(Ref* pSender);
	void GameOver();

	void MoveBackground(float t);
	CVirtualPad* GetVirtualPad();
	void SetUpListener();
	void RemoveListener();


	void SetScene(GameScene *tpScene);
	void SetActor(CActor *tpActor);

	virtual void onTouchesBegan(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesMoved(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesEnded(const vector<Touch*>&touches, Event* unused_event);
	virtual void onTouchesCancelled(const vector<Touch*>&touches, Event* unused_event);


	
};