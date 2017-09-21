#include "CSceneBox2d_0.h"
#include "SimpleAudioEngine.h"

#include "HelloWorldScene.h"
#include <iostream>

USING_NS_CC;

using namespace std;

Scene* CSceneBox2d_0::createScene()
{
	return CSceneBox2d_0::create();
}

// on "init" you need to initialize your instance
bool CSceneBox2d_0::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}


	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.










	//물리 적용 월드 생성.
	CreatePhysicsWorld();







	mpListener = EventListenerTouchOneByOne::create();

	//임의의 객체가 터치 이벤트를 받으면 터치 이벤트가 사라짐.
	mpListener->setSwallowTouches(true);

	mpListener->onTouchBegan = CC_CALLBACK_2(CSceneBox2d_0::onTouchBegan, this);
	mpListener->onTouchMoved = CC_CALLBACK_2(CSceneBox2d_0::onTouchMoved, this);
	mpListener->onTouchEnded = CC_CALLBACK_2(CSceneBox2d_0::onTouchEnded, this);

	//이벤트리스너를 추가한다.
	//씬 그래프 상의 우선순위에 따라 터치 이벤트를 받는다.
	//( 이를테면, 위에 있는 스프라이트가 먼저 터치 이벤트를 받는다. )
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mpListener, this);







	mpLayerUI = Layer::create();
	mpLayerUI->retain();







	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CSceneBox2d_0::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));






	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100);


	mpSprBtn = Sprite::create("btn_push.png");
	mpSprBtn->retain();
	mpSprBtn->setPosition(Vec2(380, 240));
	mpLayerUI->addChild(mpSprBtn, 0);




	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	mplblDebug = Label::createWithTTF("DEBUG: ", "fonts/BMJUA_ttf.ttf", 18);
	mplblDebug->setOpacity(128);
	mplblDebug->setAnchorPoint(Vec2(0, 0));
	mplblDebug->setPosition(Vec2(50, 50));

	mpLayerUI->addChild(mplblDebug, 1);






	this->addChild(mpLayerUI, 101);








	this->scheduleUpdate();


	return true;
}



void CSceneBox2d_0::onEnter()
{
	Scene::onEnter();


}




void CSceneBox2d_0::update(float dt)
{

}



void CSceneBox2d_0::menuCloseCallback(Ref* pSender)
{
	this->unscheduleUpdate();

	_eventDispatcher->removeEventListener(mpListener);


	DestroyPhysicsWorld();

	Director::getInstance()->popScene();
}

bool CSceneBox2d_0::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tTouchPos = touch->getLocation();

	return true;
}

void CSceneBox2d_0::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tTouchPos = touch->getLocation();
}


void CSceneBox2d_0::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto tTouchPos = touch->getLocation();

	//해당 사각영역에 터치가 이루어지면 발사한다.
	if ((tTouchPos.x >= 380 - 40 && tTouchPos.x <= 380 + 40) &&
		(tTouchPos.y >= 240 - 40 && tTouchPos.y <= 240 + 40))
	{
		DoFire();

		return;
	}



	//dipslay debug
	char szTemp[512];
	memset(szTemp, 0, 512);

	sprintf(szTemp, "Touch point: %f, %f",
		tTouchPos.x, tTouchPos.y);

	if (NULL != mplblDebug)
	{
		mplblDebug->setString(szTemp);
	}

	//스프라이트를 하나 만들고, 물리적용을 위해 BodyDef와 연결시킨다.
	//BodyDef는 물리바디의 형태를 정의하는 것이다.( 타입, 위치, 연결된 스프라이트 )
	//이 정의를 바탕으로 물리바디를 하나 만들게 되고
	//이 물리바디를 기반으로 하여 Fixture를 만든다.
	//What is Fixture?
	//Fixtures are used to describe the size, shape, and material properties of
	//an object in the physics scene.


	Sprite *tpSprite = Sprite::create("enemy.png");
	tpSprite->retain();

	tpSprite->setPosition(tTouchPos);
	this->addChild(tpSprite);


	b2BodyDef tBodyDef;
	tBodyDef.type = b2_dynamicBody;
	tBodyDef.position.Set(tTouchPos.x / PTM_RATIO, tTouchPos.y / PTM_RATIO);
	tBodyDef.userData = tpSprite;
	b2Body *tpBody = mpb2World->CreateBody(&tBodyDef);


	//A shape can be a circle or a polygon.

	//원을 만듦.
	b2CircleShape tCircle;
	tCircle.m_radius = 1.0f;//0.55f;

	b2FixtureDef tFixtureDef;
	tFixtureDef.shape = &tCircle;     //모양
	tFixtureDef.density = 1.0f;         //밀도
	tFixtureDef.friction = 0.5f;//0.2f;  //마찰력
	tFixtureDef.restitution = 0.0f;//0.7f;  //반발력


	tpBody->CreateFixture(&tFixtureDef);






	/*
	//사각형을 만듦( 사각형도 폴리곤에 속하므로 b2PolygonShape로 만듦

	b2PolygonShape tPolygonShape;

	tPolygonShape.SetAsBox(0.5f, 0.5f); //a 4x2 rectangle

	b2FixtureDef tFixtureDef;

	tFixtureDef.shape       = &tPolygonShape;
	tFixtureDef.density     = 1.0f;
	tFixtureDef.friction    = 0.5f;//0.2f;
	tFixtureDef.restitution = 0.0f;//0.7f;


	tpBody->CreateFixture(&tFixtureDef);
	*/




	//질량은 어떻게 결정되는가?
	//원의 경우에 반지름이 1인 경우 3.14,
	//사각형의 경우에는 0.5, 0.5 ( 1x1 ) 의 경우 1
	//Shape의 크기에 기반하는 것으로 보인다.
	float32 tMass = tpBody->GetMass();
	log("tMass: %f", tMass);

	/*
	b2MassData tData;
	tData.mass = 1.0f;
	tpBody->SetMassData(&tData);

	tMass = tpBody->GetMass();
	log("==tMass: %f", tMass);
	*/


	//카메라가 이 Layer를 보도록 설정한다.
	Rect myBoundary = Rect(0, 0, mWinSize.width * 2, mWinSize.height * 2);
	this->runAction(Follow::create(this, myBoundary));
}
void CSceneBox2d_0::DoFire()
{
	//가장 최근의 physical body를 하나 얻어온다.
	mpCurBody = mpb2World->GetBodyList();


	if (NULL == (Sprite *)(mpCurBody->GetUserData()))
	{
		return;
	}


	//방향은 각도 70도, 힘의 크기는 100의 경우를 보이고 있다.
	//이 값은 어떤 것을 기준으로 삼아 결정하면 좋은가?
	double tDirX = cosf(CC_DEGREES_TO_RADIANS(70.0f));
	double tDirY = sinf(CC_DEGREES_TO_RADIANS(70.0f));
	double tFScalar = 100.0f;//500.0f;



							 //닮은 삼각형임을 이용하여 각 축의 힘의 크기를 구하였다.
	double tFX = tFScalar*tDirX;
	double tFY = tFScalar*tDirY;

	//주어진 벡터만큼의 힘을 가하는 코드이다.
	mpCurBody->ApplyLinearImpulse(b2Vec2(tFX, tFY), b2Vec2(0.0f, 0.0f), true);



	//메인카메라가 해당객체를 따라다니게 하는 액션이다.
	Rect myBoundary = Rect(0, 0, mWinSize.width * 2, mWinSize.height * 2);
	this->runAction(Follow::create((Sprite *)(mpCurBody->GetUserData()), myBoundary));
}


void CSceneBox2d_0::CreatePhysicsWorld()
{

	mWinSize = Director::getInstance()->getWinSize();

	//중력값을 설정하고, 중력값을 바탕으로 물리세계를 만든다.
	b2Vec2 tGravity = b2Vec2(0.0f, -30.0f);

	mpb2World = new b2World(tGravity);
	mpb2World->SetAllowSleeping(true);
	mpb2World->SetContinuousPhysics(true);





	//물리세계의 경계를 위해 Physical Body들을 staticBody로 만든다.
	b2BodyDef tGroundBodyDef;
	tGroundBodyDef.position.Set(0, 0);
	tGroundBodyDef.type = b2_staticBody;

	b2Body *tpGroundBody = mpb2World->CreateBody(&tGroundBodyDef);


	b2EdgeShape tGroundEdge;
	b2FixtureDef tBoxShapeDef;
	tBoxShapeDef.shape = &tGroundEdge;


	//left
	tGroundEdge.Set(
		b2Vec2(0, 0),
		b2Vec2(0, mWinSize.height * 2 / PTM_RATIO));
	tpGroundBody->CreateFixture(&tBoxShapeDef);

	//top
	tGroundEdge.Set(
		b2Vec2(0, mWinSize.height * 2 / PTM_RATIO),
		b2Vec2(mWinSize.width * 2 / PTM_RATIO, mWinSize.height * 2 / PTM_RATIO));
	tpGroundBody->CreateFixture(&tBoxShapeDef);

	//right
	tGroundEdge.Set(
		b2Vec2(mWinSize.width * 2 / PTM_RATIO, mWinSize.height * 2 / PTM_RATIO),
		b2Vec2(mWinSize.width * 2 / PTM_RATIO, 0));
	tpGroundBody->CreateFixture(&tBoxShapeDef);

	//bottom
	tGroundEdge.Set(
		b2Vec2(0, 0),
		b2Vec2(mWinSize.width * 2 / PTM_RATIO, 0));
	tpGroundBody->CreateFixture(&tBoxShapeDef);





	//물리세계의 정보들을 갱신하기 위한 루프를 만든다.
	this->schedule(CC_SCHEDULE_SELECTOR(CSceneBox2d_0::UpdatePhysicsWorld));


	//물리세계에서 일어나는 충돌들을 감지하기 위한 리스너를 만든다.
	mpContactListener = new CContactListener();
	mpb2World->SetContactListener((b2ContactListener *)mpContactListener);




	//debug
	// 디버그 드로잉 설정
	// 적색 : 현재 물리 운동을 하는 것
	// 회색 : 현재 물리 운동량이 없는 것
	m_debugDraw = new GLESDebugDraw(PTM_RATIO);
	mpb2World->SetDebugDraw(m_debugDraw);

	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	//flags += b2Draw::e_jointBit;
	//flags += b2Draw::e_aabbBit;
	//flags += b2Draw::e_pairBit;
	//flags += b2Draw::e_centerOfMassBit;
	m_debugDraw->SetFlags(flags);
}

void CSceneBox2d_0::DestroyPhysicsWorld()
{
	//물리 객체들을 삭제한다.
	//물리 객체에 연결된 스프라이트(노드)도 삭제해야 한다.
	for (b2Body *tpBody = mpb2World->GetBodyList(); tpBody; tpBody = tpBody->GetNext())
	{
		if (NULL != tpBody->GetUserData())
		{
			//Destroy Body
			Sprite *tpSprite = (Sprite *)tpBody->GetUserData();
			this->removeChild(tpSprite);


			mpb2World->DestroyBody(tpBody);

		}
	}


	//물리세계를 파괴한다.
	if (NULL != mpb2World)
	{
		delete mpb2World;
		mpb2World = NULL;
	}
}

void CSceneBox2d_0::UpdatePhysicsWorld(float dt)
{
	if (NULL == mpb2World)
	{
		return;
	}


	//http://cafe.naver.com/cocos2dxusers/25620
	// velocityIterations : 바디들을 정상적으로 이동시키기 위해서 필요한 충돌들을 반복적으로 계산
	// positionIterations : 조인트 분리와, 겹침현상을 줄이기 위해서 바디의 위치를 반복적으로 적용
	// 값이 클수록 정확한 연산이 가능하지만 성능이 떨어진다.



	//매뉴얼 추천값
	int tVelocityIterations = 8;
	int tPositionIterations = 3;

	//Step메소드의 역할은 무엇인가? 물리기반 세계를 진행한다.
	mpb2World->Step(dt, tVelocityIterations, tPositionIterations);



	//아래 구문은 무엇을 하는 것인가?
	//물리결과에 기반하여 Sprite의 위치와 회전값을 갱신하는 것이다.
	for (b2Body *tpBody = mpb2World->GetBodyList(); tpBody; tpBody = tpBody->GetNext())
	{
		if (NULL != tpBody->GetUserData())
		{
			Sprite *tpSprite = (Sprite *)tpBody->GetUserData();

			if (NULL != tpSprite)
			{
				//물리기반 세계의 좌표에서 픽셀단위 좌표계로 값을 변환해준다.
				tpSprite->setPosition(Vec2(tpBody->GetPosition().x*PTM_RATIO,
					tpBody->GetPosition().y*PTM_RATIO));

				//각을 라디안에서 도 단위로 변환한다.
				//-1을 곱하는 이유는 무엇인가?
				tpSprite->setRotation(-1 * CC_RADIANS_TO_DEGREES((tpBody->GetAngle())));
			}
		}
	}

	//destroy physical body

	std::vector<b2Body *> tDestroyVec;
	std::vector<SContacts>::iterator tIterator;
	//충돌 감지 리스트에 담긴 Physical Body들을 가져와 삭제대상목록에 넣는다.
	for (tIterator = mpContactListener->mSContacts.begin(); tIterator != mpContactListener->mSContacts.end(); ++tIterator)
	{
		SContacts tSContacts = *tIterator;

		b2Body *tpBodyA = tSContacts.fixtureA->GetBody();
		b2Body *tpBodyB = tSContacts.fixtureB->GetBody();

		if (tpBodyA->GetUserData() != NULL && tpBodyB->GetUserData() != NULL)
		{
			Sprite *tpSpriteA = (Sprite *)tpBodyA->GetUserData();
			Sprite *tpSpriteB = (Sprite *)tpBodyB->GetUserData();

			if (NULL != tpSpriteA && NULL != tpSpriteB)
			{
				if (std::find(tDestroyVec.begin(), tDestroyVec.end(), tpBodyB) == tDestroyVec.end())
				{
					tDestroyVec.push_back(tpBodyB);
				}

				if (std::find(tDestroyVec.begin(), tDestroyVec.end(), tpBodyA) == tDestroyVec.end())
				{
					tDestroyVec.push_back(tpBodyA);
				}
			}

		}

	}


	//삭제대상 목록에 있는 Physical Body 들을 삭제한다.
	std::vector<b2Body *>::iterator tIterator_0;
	for (tIterator_0 = tDestroyVec.begin(); tIterator_0 != tDestroyVec.end(); ++tIterator_0)
	{

		b2Body *tpBody = *tIterator_0;

		if (tpBody->GetUserData() != NULL)
		{
			Sprite *tpSprite = (Sprite *)tpBody->GetUserData();

			this->removeChild(tpSprite, true);

			tpSprite->release();
			tpSprite = NULL;
		}

		mpb2World->DestroyBody(tpBody);
	}
}



//debug
void CSceneBox2d_0::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	Scene::draw(renderer, transform, flags);

	_customCmd.init(_globalZOrder, transform, flags);
	_customCmd.func = CC_CALLBACK_0(CSceneBox2d_0::onDraw, this, transform, flags);
	renderer->addCommand(&_customCmd);
}

void CSceneBox2d_0::onDraw(const Mat4 &transform, uint32_t flags)
{
	Director* director = Director::getInstance();
	CCASSERT(nullptr != director, "Director is null when seting matrix stack");
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);

	//
	mpb2World->DrawDebugData();


	CHECK_GL_ERROR_DEBUG();

	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}




