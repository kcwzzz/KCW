#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class GameScene;
class CActor;

class CBackgroundLayer : public Layer
{
protected:
	GameScene *mpScene = NULL;
	CActor *mpActor = NULL;
	
	cocos2d::Sprite *mpSpriteA;	//배경 이미지1
	cocos2d::Sprite *mpSpriteB; //배경 이미지2
	cocos2d::Sprite *mpSpriteC;	//배경 이미지1
	cocos2d::Sprite *mpSpriteD; //배경 이미지2

	Vec2 mVecBackgroundA;					//배경 이미지1의 위치 값
	Vec2 mVecBackgroundB;					//배경 이미지2의 위치 값
	Vec2 mVecBackgroundC;					//배경 이미지1의 위치 값
	Vec2 mVecBackgroundD;					//배경 이미지2의 위치 값

	ParallaxNode *mpParallaxNode = NULL;

	Node *tpNodeMap = NULL;

	TMXTiledMap *mpTiledMap = NULL;
	
public:
	void Create();
	void SetAnchorPoint(Vec2 tVec);
	void SetPosition();
	void Build();
	void ParallaxBackground();
	
	void MoveBackground(CActor *tpActor);

	void SetScene(GameScene *tpScene);
	void SetActor(CActor *tpActor);

	int GetAttributeWith(int tRow, int tCol);
};