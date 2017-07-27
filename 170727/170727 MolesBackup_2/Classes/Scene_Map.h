#ifndef __SCENE_MAP_SCENE_H__
#define __SCENE_MAP_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Scene_Map : public cocos2d::Scene
{

private :
	bool mIsUpdate = false;

protected:

	TMXTiledMap *tMap = NULL;
	//월드와 UI를 레이어로 나눔
	cocos2d::Layer *mpLayerForWorld = NULL;
	cocos2d::Layer *mpLayerForUI = NULL;

	cocos2d::Sprite *mpSprDragon = NULL;

	//화살표 이미지
	cocos2d::Sprite *rightSprite;
	cocos2d::Sprite *rightPressedSprite;
	cocos2d::Sprite *leftSprite;
	cocos2d::Sprite *leftPressedSprite;

	cocos2d::Size winSize;

	bool isLeftPressed;
	bool isRightPressed;

	void CreateBackgroundParallax();
	void CreateDragon();
	void CreateVoidArrowButtons();

	virtual void onEnter();
	virtual void onExit();
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

	bool isTouchInside(cocos2d::Sprite * sprite, cocos2d::Touch* touch);
	void startMovingBackground();
	void stopMovingBackground();
	void moveBackground(float t);

	int GetAttributeWith(int tRow, int tCol);

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
