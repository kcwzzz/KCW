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

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	return true;
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

	tBackground_0 = Sprite::create("Images/background1.png");
	tBackground_0->setAnchorPoint(Vec2(0, 0));

	tBackground_1 = Sprite::create("Images/background2.png");
	tBackground_1->setAnchorPoint(Vec2(0, 0));

	tpNode->addChild(tBackground_0, 1, Vec2(1.0f, 0.0f), Vec2(0, 0));
	tpNode->addChild(tBackground_1, 1, Vec2(1.0f, 0.0f), Vec2(512, 0));
	//addChild(변수 이름, Z높이, 이동 속도(x축 y축), 시작 위치(x축, y축));

	//mpLayerForWorld->addChild(tpNode, 0);

	auto go = MoveBy::create(4, Vec2(-512, 0));
	auto goBack = go->reverse();
	auto seq = Sequence::create(go, goBack, NULL);
	auto tRepeatFoever = RepeatForever::create(seq);

	tpNode->runAction(tRepeatFoever);
}
*/
