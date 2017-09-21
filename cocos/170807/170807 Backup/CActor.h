#pragma once

#include "cocos2d.h"
#include "CUnit.h"
//#include "CCharacter.h"

USING_NS_CC;


class GameScene;

class CActor :public CUnit//CCharacter
{	
private :

protected:

	GameScene *mpScene = NULL;

public:
	CActor();
	virtual ~CActor();
	
	void Create();
	void setPosition(Vec2 tVec);
	void SetScene(GameScene *tpScene);
	void Build();
};