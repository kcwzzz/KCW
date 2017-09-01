//
//  CScenePlayGame.cpp
//  cocos_study_2
//
//  Created by YangBruce on 2017. 1. 24..
//
//

#include "CScenePlayGame.hpp"
#include "HelloWorldScene.h"



#include "CStageMgr.hpp"
#include "CStageInfo.hpp"
#include "CUnitInfo.hpp"




USING_NS_CC;

Scene* CScenePlayGame::createScene()
{
	return CScenePlayGame::create();
}

// on "init" you need to initialize your instance
bool CScenePlayGame::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
















	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CScenePlayGame::OnClickBtnGoTitle, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));




	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	mplblTitle = Label::createWithTTF("Hello World", "fonts/arial.ttf", 12);

	// position the label on the center of the screen
	mplblTitle->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - mplblTitle->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(mplblTitle, 10);


	mplblTotalEnemyCount = Label::createWithTTF("", "fonts/arial.ttf", 12);

	mplblTotalEnemyCount->setPosition(Vec2(mplblTitle->getPositionX(),
		mplblTitle->getPositionY() - 20));

	this->addChild(mplblTotalEnemyCount, 10);











	//스테이지 정보 얻기
	CStageInfo *tpInfo = NULL;
	tpInfo = CStageMgr::GetInstance()->GetCurStageInfo();

	//스테이지 정보에 기반하여 게임 세계를 구성한다.
	if (NULL != tpInfo)
	{
		char tszTemp[512];

		memset(tszTemp, 0, 512);
		sprintf(tszTemp, "STAGE: %d", tpInfo->mId);
		mplblTitle->setString(tszTemp);




		memset(tszTemp, 0, 512);
		sprintf(tszTemp, "Total Enemy Count: %d", tpInfo->mTotalEnemyCount);
		mplblTotalEnemyCount->setString(tszTemp);





		int ti = 0;
		int tCount = 0;
		int tX = 0;
		int tY = 0;
		Sprite *tpSprite = NULL;

		tCount = tpInfo->mUnitInfoVec.size();

		for (ti = 0; ti<tCount; ti++)
		{
			tX = tpInfo->mUnitInfoVec[ti]->mX;
			tY = tpInfo->mUnitInfoVec[ti]->mY;


			tpSprite = NULL;
			tpSprite = Sprite::create("actor.png");
			tpSprite->setPosition(Vec2(tX, tY));


			mSpriteVec.push_back(tpSprite);

		}




		for (ti = 0; ti<mSpriteVec.size(); ti++)
		{
			mSpriteVec[ti]->retain();

			this->addChild(mSpriteVec[ti]);
		}


	}













	// add "CScenePlayGame" splash screen"
	//auto sprite = Sprite::create("CScenePlayGame.png");

	// position the sprite on the center of the screen
	//sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	//this->addChild(sprite, 0);

	return true;
}


void CScenePlayGame::OnClickBtnGoTitle(Ref* pSender)
{
	int ti = 0;

	for (ti = 0; ti<mSpriteVec.size(); ti++)
	{
		this->removeChild(mSpriteVec[ti]);
	}



	for (ti = 0; ti<mSpriteVec.size(); ti++)
	{
		if (NULL != mSpriteVec[ti])
		{
			mSpriteVec[ti]->release();
			mSpriteVec[ti] = NULL;
		}
	}

	mSpriteVec.clear();




	Director::getInstance()->popScene();
	//auto pScene = HelloWorld::createScene();
	//Director::getInstance()->pushScene(pScene);
}

