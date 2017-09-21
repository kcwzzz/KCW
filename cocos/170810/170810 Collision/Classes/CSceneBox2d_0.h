#ifndef __BOX2D_0_SCENE_H__
#define __BOX2D_0_SCENE_H__

#include "cocos2d.h"
//물리세계 구축
#include "Box2D/Box2D.h"
#include "CContactListener.h"




//debug
#include "GLES-Render.h"

#include <vector>


USING_NS_CC;

//Pixel to Meter Ratio
#define PTM_RATIO 32

/*
created by pokpoongryu

Box2d 의 예시 장면이다.
간단한 포쏘기 예시를 보이고 있다.
*/
class CSceneBox2d_0 : public cocos2d::Scene
{
protected:

	std::vector<Sprite *> mSpriteVec;

	cocos2d::Label *mplblDebug = NULL;

	EventListenerTouchOneByOne *mpListener = NULL;


	b2Body *mpCurBody = NULL;

public:

	virtual void update(float dt) override;
	virtual void onEnter() override;

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);



	//물리세계 관련
public:
	cocos2d::Layer *mpLayerUI = NULL;

	Sprite *mpSprBtn = NULL;
	Size mWinSize;


	b2World *mpb2World = NULL;
	CContactListener *mpContactListener = NULL;


	void CreatePhysicsWorld();
	void DestroyPhysicsWorld();
	void UpdatePhysicsWorld(float dt);


	void DoFire();


	//debug
protected:
	cocos2d::CustomCommand _customCmd;

	void onDraw(const cocos2d::Mat4& transform, uint32_t flags);

public:
	GLESDebugDraw* m_debugDraw;

	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;




public:
	static cocos2d::Scene* createScene();

	virtual bool init() override;

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(CSceneBox2d_0);

};

#endif // __BOX2D_0_SCENE_H__
