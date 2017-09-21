#include "TitleScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
	return TitleScene::create();
}

bool TitleScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	CreateWorldLayer();
	CreateUILayer();
	TitleBackGround();
	TitleText();
	CloseGame();
	BtnStartGame();
		
	return true;
}
void TitleScene:: TitleText()
{
	mpTitleLabel = Label::createWithTTF("GALAXY INVADER", "fonts/BMJUA_ttf.ttf", 50);
	mpTitleLabel->setPosition(Vec2(240, 540));
	this->addChild(mpTitleLabel, 5);

	auto Change_Red = TintTo::create(3, 192, 0, 0);
	auto Change_Green = TintTo::create(3, 0, 192, 0);
	auto Change_Blue = TintTo::create(3, 0, 0, 192);
	auto Change_White = TintTo::create(3, 255, 255, 255);

	auto Seq_ChangeColor = Sequence::create(Change_Red, Change_Green, Change_Blue, Change_White, NULL);
	auto Repeat_Forever = RepeatForever::create(Seq_ChangeColor);

	mpTitleLabel->runAction(Repeat_Forever);
}

void  TitleScene::CreateWorldLayer()
{
	mpWorldLayer = Layer::create();
	this->addChild(mpWorldLayer);
}

void  TitleScene::CreateUILayer()
{
	mpUILayer = Layer::create();
	this->addChild(mpUILayer);
}

//배경 셋업 및 카메라 이동
void  TitleScene::TitleBackGround()
{
	ParallaxNode *tpNode = ParallaxNode::create();
	this->addChild(tpNode, 3);
	
	tBackground_0 = Sprite::create("TitleImage.jpg");
	tBackground_0->setAnchorPoint(Vec2(0, 0));

	tpNode->addChild(tBackground_0,1,Vec2(1.0f, 0.0f), Vec2(0,0) );
	//tpNode->setPosition(0, 0);

	auto go = MoveBy::create(6, Vec2(-1280+480, 0));
	auto goBack = go->reverse();
	auto seq = Sequence::create(go, goBack, NULL);
	auto tRepeatFoever = RepeatForever::create(seq);

	tpNode->runAction(tRepeatFoever);
}

//GameScece으로 넘어가는 임시 버튼
void TitleScene::BtnStartGame()
{
	auto BtnStartGame = MenuItemFont::create("GAME START",
		CC_CALLBACK_1(TitleScene::SceneChange, this));
	BtnStartGame->setFontSize(200);

	auto tStartMenu = Menu::create(BtnStartGame, NULL);
	tStartMenu->setPosition(Vec2(240, 180));
	this->addChild(tStartMenu, 5);
}

// GameScene으로 이동합니다. createTransition(장면 트랜지션)함수를 사용
void TitleScene::SceneChange(Object *pSender)
{
	auto pScene = GameScene::createScene();
	Director::getInstance()->replaceScene(createTransition(1,1, pScene));
}

//장면 트랜지션 함수
TransitionScene* TitleScene::createTransition(int nIndex, float t, Scene *s)
{
	Director::getInstance()->setDepthTest(false);
	return TransitionProgressRadialCCW::create(t, s);
}

// 게임 종료 버튼
void TitleScene::CloseGame()
{
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(TitleScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(450, 25));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
}

void TitleScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}