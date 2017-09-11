#include "ActorSelectScene.h"
#include "SimpleAudioEngine.h"
#include "DataDriven.h"
#include "GameScene.h"
#include "CSound.h"

USING_NS_CC;

Scene* ActorSelectScene::createScene()
{
	return ActorSelectScene::create();
}

bool ActorSelectScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	DataDriven::GetInstance()->CreateActor();
	CSound::Getinstance()->Create();
	CSound::Getinstance()->PlayBGM(1);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(ActorSelectScene::menuCloseCallback, this));

	mpBGsprite_0 = Sprite::create("Antor_1.png");
	mpBGsprite_0->retain();
	mpBGsprite_0->setAnchorPoint(Vec2(0, 0));
	mpBGsprite_0->setPosition(Vec2(0, 0));
	this->addChild(mpBGsprite_0);

	mpBGsprite_1 = Sprite::create("Antor_2.png");
	mpBGsprite_1->retain();
	mpBGsprite_1->setAnchorPoint(Vec2(0, 0));
	mpBGsprite_1->setPosition(Vec2(512, 0));
	this->addChild(mpBGsprite_1);

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	
	auto SelectActor_0 = MenuItemImage::create(
		"Hero_1_Select.png",
		"Hero_1_Select.png",
		CC_CALLBACK_0(ActorSelectScene::SeqStageChange_0, this));
	SelectActor_0->setPosition(Vec2(300, 200));


	auto SelectActor_1 = MenuItemImage::create(
		"Hero_2_Select.png",
		"Hero_2_Select.png",
		CC_CALLBACK_0(ActorSelectScene::SeqStageChange_1, this));
	SelectActor_1->setPosition(Vec2(700, 200));


	auto menu = Menu::create(closeItem, SelectActor_0, SelectActor_1, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	return true;
}

void ActorSelectScene::SeqStageChange_0()
{
	auto tSeq = Sequence::create(
		CallFunc::create(CC_CALLBACK_0(ActorSelectScene::FadeOutBG_1, this)),
		CallFunc::create(CC_CALLBACK_0(ActorSelectScene::OnLoadStage_0, this)), 
		NULL);

	mpBGsprite_0->runAction(tSeq);
}

void ActorSelectScene::SeqStageChange_1()
{
	auto tSeq = Sequence::create(
		CallFunc::create(CC_CALLBACK_0(ActorSelectScene::FadeOutBG_0, this)),
		CallFunc::create(CC_CALLBACK_0(ActorSelectScene::OnLoadStage_1, this)),
		NULL);

	mpBGsprite_1->runAction(tSeq);
}


void ActorSelectScene::OnLoadStageInfo_0(Ref* pSender)
{
	DataDriven::GetInstance()->SetCurActorInfo(0);

	auto pScene = GameScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void ActorSelectScene::OnLoadStageInfo_1(Ref* pSender)
{
	DataDriven::GetInstance()->SetCurActorInfo(1);

	auto pScene = GameScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void ActorSelectScene::OnLoadStage_0()
{
	DataDriven::GetInstance()->SetCurActorInfo(0);

	auto pScene = GameScene::createScene();
	Director::getInstance()->pushScene(pScene);
}

void ActorSelectScene::OnLoadStage_1()
{
	DataDriven::GetInstance()->SetCurActorInfo(1);

	auto pScene = GameScene::createScene();
	Director::getInstance()->pushScene(pScene);
}


void ActorSelectScene::FadeOutBG_0()
{
	auto tAction = FadeOut::create(5.0f);

	mpBGsprite_0->runAction(tAction);
}

void ActorSelectScene::FadeOutBG_1()
{
	auto tAction = FadeOut::create(5.0f);

	mpBGsprite_1->runAction(tAction);
}

void ActorSelectScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}