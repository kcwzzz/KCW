#include "CUILayer.h"
#include "cocos2d.h"
#include "CVirtualPad.h"
#include "GameScene.h"
#include "CGuageHP.h"

CUILayer *CUILayer::create()
{

	
	CUILayer *ret = new (std::nothrow) CUILayer();
		if (ret && ret->init())
		{
			ret->autorelease();
			return ret;
		}
		else
		{
			CC_SAFE_DELETE(ret);
			return nullptr;
		}
	
}

void CUILayer::CreateLayer()
{
	mpUILayer = Layer::create();
	mpUILayer->setAnchorPoint(Vec2(0, 0));
	mpUILayer->setPosition(Vec2(0, 0));
	this->addChild(mpUILayer, 10);
}


void CUILayer::VirtualPad()
{
	mpVirtualPad = new CVirtualPad();
	mpVirtualPad->create(mpUILayer, Vec2(200, 200));

}

void CUILayer::CreateBtnAttack()
{
	
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CUILayer::menuAttackCallback, this));

	closeItem->setPosition(Vec2(800, 300));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);
	
}

void CUILayer::menuAttackCallback(Ref* pSender)
{
	mpScene->AttackBehavior();
}


void CUILayer::CreateBtnTestDamaged()
{

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CUILayer::menuAttackdCallback, this));

	closeItem->setPosition(Vec2(450, 25));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

}

void CUILayer::menuAttackdCallback(Ref* pSender)
{
	mpScene->DamagedActor();
}

void CUILayer::SetUpListener()
{
	mpListener = EventListenerTouchAllAtOnce::create();

	mpListener->onTouchesBegan = CC_CALLBACK_2(CUILayer::onTouchesBegan, this);
	mpListener->onTouchesMoved = CC_CALLBACK_2(CUILayer::onTouchesMoved, this);
	mpListener->onTouchesEnded = CC_CALLBACK_2(CUILayer::onTouchesEnded, this);
	mpListener->onTouchesCancelled = CC_CALLBACK_2(CUILayer::onTouchesCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);
}

void CUILayer::RemoveListener()
{
	_eventDispatcher->removeEventListener(mpListener);
}

void CUILayer::GameOver()
{
	mpGameOverLabel = Label::createWithTTF("GAME OVER", "fonts/BMJUA_ttf.ttf", 50);
	mpGameOverLabel->setPosition(Vec2(240, 360));
	this->addChild(mpGameOverLabel, 15);
}


void  CUILayer::onTouchesBegan(const vector<Touch*>&touches, cocos2d::Event *unused_event)
{
	this->scheduleUpdate();
	mpVirtualPad->TouchesBegan(touches, unused_event);
	this->GetDir();
}

void CUILayer::onTouchesMoved(const vector<Touch*>&touches, cocos2d::Event *unused_event)
{
	mpScene->MoveBehavior();
	mpVirtualPad->TouchesMoved(touches, unused_event);
	this->GetDir();

}

void CUILayer::onTouchesEnded(const vector<Touch*>&touches, cocos2d::Event* unused_event)
{
	mpScene->IdleBehavior();
	this->unscheduleUpdate();
	mpVirtualPad->TouchesEnded(touches, unused_event);
}

void CUILayer::onTouchesCancelled(const vector<Touch*>&touches, cocos2d::Event* unused_event)
{
	mpVirtualPad->TouchesCancelled(touches, unused_event);
}

CVirtualPad* CUILayer::GetVirtualPad()
{
	return mpVirtualPad;
}

int CUILayer::GetDir()
{
	return mpVirtualPad->GetDir();
}

void CUILayer::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}