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
	
	cocos2d::Sprite *mpSpriteA;	//��� �̹���1
	cocos2d::Sprite *mpSpriteB; //��� �̹���2
	cocos2d::Sprite *mpSpriteC;	//��� �̹���1
	cocos2d::Sprite *mpSpriteD; //��� �̹���2

	Vec2 mVecBackgroundA;					//��� �̹���1�� ��ġ ��
	Vec2 mVecBackgroundB;					//��� �̹���2�� ��ġ ��
	Vec2 mVecBackgroundC;					//��� �̹���1�� ��ġ ��
	Vec2 mVecBackgroundD;					//��� �̹���2�� ��ġ ��

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