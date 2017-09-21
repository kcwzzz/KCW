#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CloseGame();
	CreateBackground();

	return true;
}

void  GameScene::CreateBackground()
{
	ParallaxNode *tpNode = ParallaxNode::create();
	this->addChild(tpNode, 3);

	mpSpriteA = Sprite::create("GameImage.jpg");
	mpSpriteA->setAnchorPoint(Vec2(0, 0));

	mpSpriteB = Sprite::create("bg_1.png");
	mpSpriteB->setAnchorPoint(Vec2(0, 0));

	tpNode->addChild(mpSpriteA, 1, Vec2(0.0f, 1.0f), Vec2(0, 0));
	tpNode->addChild(mpSpriteB, 1, Vec2(0.0f, 1.0f), Vec2(0, 720));
	tpNode->setPosition(0, 0);

	auto go = MoveBy::create(6, Vec2(0, -720));
	//auto goBack = go->reverse();
	//auto seq = Sequence::create(go, goBack, NULL);	

	//auto seq = Sequence::create(go, NULL);

	auto tRepeatFoever = RepeatForever::create(go);

	tpNode->runAction(tRepeatFoever);
}

void GameScene::CloseGame()
{
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(450, 25));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
}

void GameScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}



/*
void GameScene::SceneChange(Object *pSender)
{
	//auto pScene = Scene_0::createScene();	
	auto pScene = Scene_Map::createScene();
	Director::getInstance()->replaceScene(pScene);
}
void GameScene::CreateBackgroundParallax()
{
	ParallaxNode *tpNode = ParallaxNode::create();
	this->addChild(tpNode, 3);

	mpSpriteA = Sprite::create("Images/background1.png");
	mpSpriteA->setAnchorPoint(Vec2(0, 0));

	mpSpriteB = Sprite::create("Images/background2.png");
	mpSpriteB->setAnchorPoint(Vec2(0, 0));

	tpNode->addChild(mpSpriteA, 1, Vec2(1.0f, 0.0f), Vec2(0, 0));
	tpNode->addChild(mpSpriteB, 1, Vec2(1.0f, 0.0f), Vec2(512, 0));
	//addChild(변수 이름, Z높이, 이동 속도(x축 y축), 시작 위치(x축, y축));

	//mpLayerForWorld->addChild(tpNode, 0);

	auto go = MoveBy::create(4, Vec2(-512, 0));
	auto goBack = go->reverse();
	auto seq = Sequence::create(go, goBack, NULL);
	auto tRepeatFoever = RepeatForever::create(seq);

	tpNode->runAction(tRepeatFoever);
}
*/
