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










	//���� ���� ���� ����.
	CreatePhysicsWorld();







	mpListener = EventListenerTouchOneByOne::create();

	//������ ��ü�� ��ġ �̺�Ʈ�� ������ ��ġ �̺�Ʈ�� �����.
	mpListener->setSwallowTouches(true);

	mpListener->onTouchBegan = CC_CALLBACK_2(CSceneBox2d_0::onTouchBegan, this);
	mpListener->onTouchMoved = CC_CALLBACK_2(CSceneBox2d_0::onTouchMoved, this);
	mpListener->onTouchEnded = CC_CALLBACK_2(CSceneBox2d_0::onTouchEnded, this);

	//�̺�Ʈ�����ʸ� �߰��Ѵ�.
	//�� �׷��� ���� �켱������ ���� ��ġ �̺�Ʈ�� �޴´�.
	//( �̸��׸�, ���� �ִ� ��������Ʈ�� ���� ��ġ �̺�Ʈ�� �޴´�. )
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

	//�ش� �簢������ ��ġ�� �̷������ �߻��Ѵ�.
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

	//��������Ʈ�� �ϳ� �����, ���������� ���� BodyDef�� �����Ų��.
	//BodyDef�� �����ٵ��� ���¸� �����ϴ� ���̴�.( Ÿ��, ��ġ, ����� ��������Ʈ )
	//�� ���Ǹ� �������� �����ٵ� �ϳ� ����� �ǰ�
	//�� �����ٵ� ������� �Ͽ� Fixture�� �����.
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

	//���� ����.
	b2CircleShape tCircle;
	tCircle.m_radius = 1.0f;//0.55f;

	b2FixtureDef tFixtureDef;
	tFixtureDef.shape = &tCircle;     //���
	tFixtureDef.density = 1.0f;         //�е�
	tFixtureDef.friction = 0.5f;//0.2f;  //������
	tFixtureDef.restitution = 0.0f;//0.7f;  //�ݹ߷�


	tpBody->CreateFixture(&tFixtureDef);






	/*
	//�簢���� ����( �簢���� �����￡ ���ϹǷ� b2PolygonShape�� ����

	b2PolygonShape tPolygonShape;

	tPolygonShape.SetAsBox(0.5f, 0.5f); //a 4x2 rectangle

	b2FixtureDef tFixtureDef;

	tFixtureDef.shape       = &tPolygonShape;
	tFixtureDef.density     = 1.0f;
	tFixtureDef.friction    = 0.5f;//0.2f;
	tFixtureDef.restitution = 0.0f;//0.7f;


	tpBody->CreateFixture(&tFixtureDef);
	*/




	//������ ��� �����Ǵ°�?
	//���� ��쿡 �������� 1�� ��� 3.14,
	//�簢���� ��쿡�� 0.5, 0.5 ( 1x1 ) �� ��� 1
	//Shape�� ũ�⿡ ����ϴ� ������ ���δ�.
	float32 tMass = tpBody->GetMass();
	log("tMass: %f", tMass);

	/*
	b2MassData tData;
	tData.mass = 1.0f;
	tpBody->SetMassData(&tData);

	tMass = tpBody->GetMass();
	log("==tMass: %f", tMass);
	*/


	//ī�޶� �� Layer�� ������ �����Ѵ�.
	Rect myBoundary = Rect(0, 0, mWinSize.width * 2, mWinSize.height * 2);
	this->runAction(Follow::create(this, myBoundary));
}
void CSceneBox2d_0::DoFire()
{
	//���� �ֱ��� physical body�� �ϳ� ���´�.
	mpCurBody = mpb2World->GetBodyList();


	if (NULL == (Sprite *)(mpCurBody->GetUserData()))
	{
		return;
	}


	//������ ���� 70��, ���� ũ��� 100�� ��츦 ���̰� �ִ�.
	//�� ���� � ���� �������� ��� �����ϸ� ������?
	double tDirX = cosf(CC_DEGREES_TO_RADIANS(70.0f));
	double tDirY = sinf(CC_DEGREES_TO_RADIANS(70.0f));
	double tFScalar = 100.0f;//500.0f;



							 //���� �ﰢ������ �̿��Ͽ� �� ���� ���� ũ�⸦ ���Ͽ���.
	double tFX = tFScalar*tDirX;
	double tFY = tFScalar*tDirY;

	//�־��� ���͸�ŭ�� ���� ���ϴ� �ڵ��̴�.
	mpCurBody->ApplyLinearImpulse(b2Vec2(tFX, tFY), b2Vec2(0.0f, 0.0f), true);



	//����ī�޶� �ش簴ü�� ����ٴϰ� �ϴ� �׼��̴�.
	Rect myBoundary = Rect(0, 0, mWinSize.width * 2, mWinSize.height * 2);
	this->runAction(Follow::create((Sprite *)(mpCurBody->GetUserData()), myBoundary));
}


void CSceneBox2d_0::CreatePhysicsWorld()
{

	mWinSize = Director::getInstance()->getWinSize();

	//�߷°��� �����ϰ�, �߷°��� �������� �������踦 �����.
	b2Vec2 tGravity = b2Vec2(0.0f, -30.0f);

	mpb2World = new b2World(tGravity);
	mpb2World->SetAllowSleeping(true);
	mpb2World->SetContinuousPhysics(true);





	//���������� ��踦 ���� Physical Body���� staticBody�� �����.
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





	//���������� �������� �����ϱ� ���� ������ �����.
	this->schedule(CC_SCHEDULE_SELECTOR(CSceneBox2d_0::UpdatePhysicsWorld));


	//�������迡�� �Ͼ�� �浹���� �����ϱ� ���� �����ʸ� �����.
	mpContactListener = new CContactListener();
	mpb2World->SetContactListener((b2ContactListener *)mpContactListener);




	//debug
	// ����� ����� ����
	// ���� : ���� ���� ��� �ϴ� ��
	// ȸ�� : ���� ���� ����� ���� ��
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
	//���� ��ü���� �����Ѵ�.
	//���� ��ü�� ����� ��������Ʈ(���)�� �����ؾ� �Ѵ�.
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


	//�������踦 �ı��Ѵ�.
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
	// velocityIterations : �ٵ���� ���������� �̵���Ű�� ���ؼ� �ʿ��� �浹���� �ݺ������� ���
	// positionIterations : ����Ʈ �и���, ��ħ������ ���̱� ���ؼ� �ٵ��� ��ġ�� �ݺ������� ����
	// ���� Ŭ���� ��Ȯ�� ������ ���������� ������ ��������.



	//�Ŵ��� ��õ��
	int tVelocityIterations = 8;
	int tPositionIterations = 3;

	//Step�޼ҵ��� ������ �����ΰ�? ������� ���踦 �����Ѵ�.
	mpb2World->Step(dt, tVelocityIterations, tPositionIterations);



	//�Ʒ� ������ ������ �ϴ� ���ΰ�?
	//��������� ����Ͽ� Sprite�� ��ġ�� ȸ������ �����ϴ� ���̴�.
	for (b2Body *tpBody = mpb2World->GetBodyList(); tpBody; tpBody = tpBody->GetNext())
	{
		if (NULL != tpBody->GetUserData())
		{
			Sprite *tpSprite = (Sprite *)tpBody->GetUserData();

			if (NULL != tpSprite)
			{
				//������� ������ ��ǥ���� �ȼ����� ��ǥ��� ���� ��ȯ���ش�.
				tpSprite->setPosition(Vec2(tpBody->GetPosition().x*PTM_RATIO,
					tpBody->GetPosition().y*PTM_RATIO));

				//���� ���ȿ��� �� ������ ��ȯ�Ѵ�.
				//-1�� ���ϴ� ������ �����ΰ�?
				tpSprite->setRotation(-1 * CC_RADIANS_TO_DEGREES((tpBody->GetAngle())));
			}
		}
	}

	//destroy physical body

	std::vector<b2Body *> tDestroyVec;
	std::vector<SContacts>::iterator tIterator;
	//�浹 ���� ����Ʈ�� ��� Physical Body���� ������ ��������Ͽ� �ִ´�.
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


	//������� ��Ͽ� �ִ� Physical Body ���� �����Ѵ�.
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




