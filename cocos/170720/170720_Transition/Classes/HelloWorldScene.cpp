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

	// 종료 버튼 
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	// 종료 버튼 

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
	Scene::onEnter();// 장면 진입

	//마우스 이벤트 등록

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
		// 점프하면서 Zoom
	case 0: return TransitionJumpZoom::create(t, s);


		// 시계방향으로 침이 돌면서 장면이 바뀜
	case 1: return TransitionProgressRadialCCW::create(t, s);
		// 시계반대방향으로 침이 돌면서 장면이 바뀜
	case 2: return TransitionProgressRadialCW::create(t, s);
	case 3: return TransitionProgressHorizontal::create(t, s);
	case 4: return TransitionProgressVertical::create(t, s);
	case 5: return TransitionProgressInOut::create(t, s);
	case 6: return TransitionProgressOutIn::create(t, s);

		// 교차
	case 7: return TransitionCrossFade::create(t, s);


		// 페이지넘김형식 : PageTransitionForward
	case 8: return TransitionPageTurn::create(t, s, false);
		// 페이지넘김형식 : PageTransitionBackward
	case 9: return TransitionPageTurn::create(t, s, true);
		// 바둑판무늬 좌측하단부터 우측상단순으로 사라짐
	case 10: return TransitionFadeTR::create(t, s);
		// 바툭판무늬 우측상단부터 좌측하단순으로 사라짐
	case 11: return TransitionFadeBL::create(t, s);
		// 하단에서 상단으로 잘라냄
	case 12: return TransitionFadeUp::create(t, s);
		// 상단에서 하단으로 잘라냄
	case 13: return TransitionFadeDown::create(t, s);


		// 바둑판무늬 뿌리기
	case 14: return TransitionTurnOffTiles::create(t, s);


		// 가로로 세등분 나눔
	case 15: return TransitionSplitRows::create(t, s);
		// 세로로 세등분 나눔, 양끝의 두둥분은 밑으로 나머지는 위로
	case 16: return TransitionSplitCols::create(t, s);


		// 페이드인아웃 : 검정 화면
	case 17: return TransitionFade::create(t, s);
		// 페이드인아웃 : 하얀 화면
	case 18: return TransitionFade::create(t, s, Color3B::WHITE);


		// X축(횡선)을 기준으로 회전 : FlipXLeftOver
	case 19: return TransitionFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// X축(횡선)을 기준으로 회전 : FlipXRightOver
	case 20: return TransitionFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// Y축(종선)을 기준으로 회전 : FlipYUpOver
	case 21: return TransitionFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
		// Y축(종선)을 기준으로 회전 : FlipYDownOver
	case 22: return TransitionFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);
		// 뒤집어지면서 다음장면으로 넘어감 : FlipAngularLeftOver
	case 23: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// 뒤집어지면서 다음장면으로 넘어감 : FlipAngularRightOver
	case 24: return TransitionFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);


		// X축(횡선)을 기준으로 회전 (확대) : ZoomFlipXLeftOver
	case 25: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// X축(횡선)을 기준으로 회전 (확대) : ZoomFlipXRightOver
	case 26: return TransitionZoomFlipX::create(t, s, TransitionScene::Orientation::RIGHT_OVER);
		// Y축(종선)을 기준으로 회전 (확대) : ZoomFlipYUpOver
	case 27: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::UP_OVER);
		// Y축(종선)을 기준으로 회전 (확대) : ZoomFlipYDownOver
	case 28: return TransitionZoomFlipY::create(t, s, TransitionScene::Orientation::DOWN_OVER);
		// 뒤집어지면서 다음장면으로 넘어감 (확대) : ZoomFlipAngularLeftOver
	case 29: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::LEFT_OVER);
		// 뒤집어지면서 다음장면으로 넘어감 (확대) : ZoomFlipAngularRightOver
	case 30: return TransitionZoomFlipAngular::create(t, s, TransitionScene::Orientation::RIGHT_OVER);


		// 이전장면 수축 다음장면 확대
	case 31: return TransitionShrinkGrow::create(t, s);
		// 회전하면서 Zoom
	case 32: return TransitionRotoZoom::create(t, s);


		// 왼쪽에서 다음장면이 나타나서 이전장면을 덮어씀
	case 33: return TransitionMoveInL::create(t, s);
		// 오른쪽에서 다음장면이 나타남
	case 34: return TransitionMoveInR::create(t, s);
		// 위쪽에서 다음장면이 나타남
	case 35: return TransitionMoveInT::create(t, s);
		// 아래쪽에서 다음장면이 나타남
	case 36: return TransitionMoveInB::create(t, s);


		// 왼쪽에서 다음장면이 나타나서 이전장면을 밀어냄
	case 37: return TransitionSlideInL::create(t, s);
		// 오른쪽에서 다음장면이 나타나서 이전장면을 밀어냄
	case 38: return TransitionSlideInR::create(t, s);
		// 위쪽에서 다음장면이 나타나서 이전장면을 밀어냄
	case 39: return TransitionSlideInT::create(t, s);
		// 아래쪽에서 다음장면이 나타나서 이전장면을 밀어냄
	case 40: return TransitionSlideInB::create(t, s);

	default: break;
	}

	return NULL;

}