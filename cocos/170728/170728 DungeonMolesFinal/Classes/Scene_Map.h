#ifndef __SCENE_MAP_SCENE_H__
#define __SCENE_MAP_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Scene_Map : public cocos2d::Scene
{

private :
	bool mIsUpdate = false;

protected:
	bool tResult = false;
	int tSpeed = 0;
	TMXTiledMap *tMap = NULL;
	//월드와 UI를 레이어로 나눔
	cocos2d::Layer *mpLayerForWorld = NULL;
	cocos2d::Layer *mpLayerForUI = NULL;
	cocos2d::Sprite *mpSprDragon = NULL;
	cocos2d::Sprite *mpSprMoles = NULL;

	cocos2d::Size winSize;

	cocos2d::Vec2 mVecActor;
	cocos2d::Vec2 mVecMoles;
	cocos2d::Sprite *mpSprActor = NULL;
	
	void CreateBackgroundParallax();
	void CreateDragon();
	void CreateMoles();
	
	
	virtual void onEnter();
	virtual void onExit();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	bool IsCollision();

	/*

	bool isTouchInside(cocos2d::Sprite * sprite, cocos2d::Touch* touch);
//	void startMovingBackground();
	void stopMovingBackground();
//	

	int GetAttributeWith(int tRow, int tCol);
	*/

public:

	virtual void update(float dt);

    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Scene_Map);
};

#endif // __HELLOWORLD_SCENE_H__
