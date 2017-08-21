#pragma once

#include "cocos2d.h"

#include <vector>

using namespace std;

USING_NS_CC;

class CBackgroundLayer;
class CUILayer;
//class CGameSceneLayer;

class CActor;
class CAniBox;



class GameScene : public cocos2d::Scene
{

private:
	
protected:
	CUILayer *mpUILayer = NULL;
	CBackgroundLayer *mpBackgroundLayer = NULL;

	ActionCamera *mpCamera = NULL;
	CActor *mpActor = NULL;			//�ʱ�ȭ
	CAniBox *mpAniBox = NULL;			//�ʱ�ȭ

	Size winSize;

public:
	void CreateBackgroundLayer();
	void CreateUILayer();

	
	void onEnter();				//��ġ ��� On
	void onExit();				//��ġ ��� Off

	void CreateActor();
	void CreateAnimation();
	

	void update(float dt);

public:

	static cocos2d::Scene *createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

};