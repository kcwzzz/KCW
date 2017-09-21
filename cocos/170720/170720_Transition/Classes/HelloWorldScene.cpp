#include "HelloWorldScene.h"
#include "TestScene2.h"
#include "TestScene3.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ���� ��ư 
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	// ���� ��ư 

	auto menu = Menu::create(closeItem, NULL);
	menu->retain();
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto item1 = MenuItemFont::create(
		"pushScene",
		CC_CALLBACK_1(HelloWorld::doPushScene, this));

	item1->setColor(Color3B(255, 255, 0));

	auto item2 = MenuItemFont::create(
		"pushScene transition",
		CC_CALLBACK_1(HelloWorld::doPushSceneTran, this));

	item2->setColor(Color3B(255, 255, 0));

	auto item3 = MenuItemFont::create(
		"replaceScene",
		CC_CALLBACK_1(HelloWorld::doReplaceScene, this));

	item3->setColor(Color3B(255, 255, 0));

	auto item4 = MenuItemFont::create(
		"replaceScene transition",
		CC_CALLBACK_1(HelloWorld::doReplaceSceneTran, this));

	item4->setColor(Color3B(255, 255, 0));

	auto pMenu = Menu::create(item1, item2, item3, item4, nullptr);

	pMenu->alignItemsVertically();

	this->addChild(pMenu, 10);

	auto tpSprite = Sprite::create("HelloWorld.png");
	tpSprite->setPosition(Vec2(400, 240));
	this->addChild(tpSprite, 0);
	
	return true;
}

//void HelloWorld::
/*
void HelloWorld::onEnter()
{
	Scene::onEnter();// ��� ����

	//���콺 �̺�Ʈ ���

	mpListenerCustom = EventListenerCustom::create("Custom Event", CC_CALLBACK_1(HelloWorld::OnCustomEvent, this));

	_eventDispatcher->addEventListenerWithFixedPriority(mpListenerCustom, 1);
}

void HelloWorld::OnClickBtnTest(Ref *pSender)
{
	static int tCount = 0;
	mplblTest->setString(" ");

	char tBuffer[512];
	memset(tBuffer, 0, 512);
	sprintf(tBuffer, "this is Event Test : %d, tCount");

	EventCustom tEventCustom("Custom Evnet");
	tEventCustom.setUserData(tBuffer);
	_eventDispatcher->dispatchEvent(&tEventCustom);

	tCount++;
}
*/
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}


void HelloWorld::doPushScene(Ref* pSender)
{
	auto pScene = TestScene2::createScene();
	Director::getInstance()->pushScene(pScene);
}
void HelloWorld::doPushSceneTran(Ref* pSender)
{
	static int nIndex1 = 0;

	auto pScene = TestScene2::createScene();
	Director::getInstance()->pushScene(createTransition(nIndex1, 1, pScene));

	nIndex1++;

	if (nIndex1 > 40)
	{
		nIndex1 = 0;
	}
}
void HelloWorld::doReplaceScene(Ref* pSender)
{
	auto pScene = TestScene3::createScene();
	Director::getInstance()->replaceScene(pScene);
	
}
void HelloWorld::doReplaceSceneTran(Ref* pSender)
{
	static int nIndex2 = 2;

	auto pScene = TestScene3::createScene();
	Director::getInstance()->replaceScene(createTransition(nIndex2,1, pScene));

	nIndex2--;

	if (nIndex2 < 0)
	{
		nIndex2 = 40;
	}
}

TransitionScene* HelloWorld::createTransition(int nIndex, float t, Scene* s)
{

	Director::getInstance()->setDepthTest(false);

	switch (nIndex)
	{
		// �����ϸ鼭 Zoom
	case 0: return TransitionJumpZoom::create(t, s);


		// �ð�������� ħ�� ���鼭 ����� �ٲ�
	case 1: return TransitionProgressRadialCCW::create(t, s);
		// �ð�ݴ�������� ħ�� ���鼭 ����� �ٲ�
	case 2: return TransitionProgressRadialCW::create(t, s);
	case 3: return TransitionProgressHorizontal::create(t, s);
	case 4: return TransitionProgressVertical::create(t, s);
	case 5: return TransitionProgressInOut::create(t, s);
	case 6: return TransitionProgressOutIn::create(t, s);

		// ����
	case 7: return TransitionCrossFade::create(t, s);


		// �������ѱ����� : PageTransitionForward
	case 8: return TransitionPageTurn::create(t, s, false);
		// �������ѱ����� : PageTransitionBackward
	case 9: return TransitionPageTurn::create(t, s, true);
		// �ٵ��ǹ��� �����ϴܺ��� ������ܼ����� �����
	case 10: return TransitionFadeTR::create(t, s);
		// �����ǹ��� ������ܺ��� �����ϴܼ����� �����
	case 11: return TransitionFadeBL::create(t, s);
		// �ϴܿ��� ������� �߶�
	case 12: return TransitionFadeUp::create(t, s);
		// ��ܿ��� �ϴ����� �߶�
	case 13: return TransitionFadeDown::create(t, s);


		// �ٵ��ǹ��� �Ѹ���
	case 14: return TransitionTurnOffTiles::create(t, s);


		// ���η� ����� ����
	case 15: return TransitionSplitRows::create(t, s);
		// ���η� ����� ����, �糡�� �εպ��� ������ �������� ����
	case 16: return TransitionSplitCols::create(t, s);


		// ���̵��ξƿ� : ���� ȭ��
	case 17: return TransitionFade::create(t, s);
		// ���̵��ξƿ� : �Ͼ� ȭ��
	case 18: return TransitionFade::create(t, s, Color3B::WHITE);


		// X��(Ⱦ��)�� �������� ȸ�� : FlipXLeftOver
	case 19: return TransitionFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// X��(Ⱦ��)�� �������� ȸ�� : FlipXRightOver
	case 20: return TransitionFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// Y��(����)�� �������� ȸ�� : FlipYUpOver
	case 21: return TransitionFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
		// Y��(����)�� �������� ȸ�� : FlipYDownOver
	case 22: return TransitionFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);
		// ���������鼭 ����������� �Ѿ : FlipAngularLeftOver
	case 23: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// ���������鼭 ����������� �Ѿ : FlipAngularRightOver
	case 24: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);


		// X��(Ⱦ��)�� �������� ȸ�� (Ȯ��) : ZoomFlipXLeftOver
	case 25: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// X��(Ⱦ��)�� �������� ȸ�� (Ȯ��) : ZoomFlipXRightOver
	case 26: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// Y��(����)�� �������� ȸ�� (Ȯ��) : ZoomFlipYUpOver
	case 27: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
		// Y��(����)�� �������� ȸ�� (Ȯ��) : ZoomFlipYDownOver
	case 28: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);
		// ���������鼭 ����������� �Ѿ (Ȯ��) : ZoomFlipAngularLeftOver
	case 29: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// ���������鼭 ����������� �Ѿ (Ȯ��) : ZoomFlipAngularRightOver
	case 30: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);


		// ������� ���� ������� Ȯ��
	case 31: return TransitionShrinkGrow::create(t, s);
		// ȸ���ϸ鼭 Zoom
	case 32: return TransitionRotoZoom::create(t, s);


		// ���ʿ��� ��������� ��Ÿ���� ��������� ���
	case 33: return TransitionMoveInL::create(t, s);
		// �����ʿ��� ��������� ��Ÿ��
	case 34: return TransitionMoveInR::create(t, s);
		// ���ʿ��� ��������� ��Ÿ��
	case 35: return TransitionMoveInT::create(t, s);
		// �Ʒ��ʿ��� ��������� ��Ÿ��
	case 36: return TransitionMoveInB::create(t, s);


		// ���ʿ��� ��������� ��Ÿ���� ��������� �о
	case 37: return TransitionSlideInL::create(t, s);
		// �����ʿ��� ��������� ��Ÿ���� ��������� �о
	case 38: return TransitionSlideInR::create(t, s);
		// ���ʿ��� ��������� ��Ÿ���� ��������� �о
	case 39: return TransitionSlideInT::create(t, s);
		// �Ʒ��ʿ��� ��������� ��Ÿ���� ��������� �о
	case 40: return TransitionSlideInB::create(t, s);

	default: break;
	}

	return NULL;

}