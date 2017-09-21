#include "CAniBox.h"
#include "cocos2d.h"
#include "GameScene.h"

USING_NS_CC;

CAniBox::CAniBox()
{
}


CAniBox::~CAniBox()
{
}


void CAniBox::Create()
{
	mpActor = Sprite::create("Hero.png");
	mpTexture = mpActor->getTexture();

	mpAnimation = Animation::create();
	mpAnimation->setDelayPerUnit(0.3f);

	/*
	for (int i = 0; i < 12;i++)
	{
		int column = i % 3;
		int row = i / 3;
		animation->addSpriteFrameWithTexture(
			texture,
			Rect(column * 32, row * 32, 32, 32));
	}

	//auto pMan = Sprite::create("Hero.png");
	sprite->setPosition(Vec2(512, 512));
	//this->addChild(sprite);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	sprite->runAction(rep);
	*/
}




void CAniBox::AniMoveDown()
{
	for (int i = 0; i < 3;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::AniMoveLeft()
{
	for (int i = 3; i < 6;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::AniMoveRight()
{
	for (int i = 7; i < 9;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::AniMoveUp()
{
	for (int i = 9; i < 12;i++)
	{
		int column = i % 3;
		int row = i / 3;
		mpAnimation->addSpriteFrameWithTexture(
			mpTexture,
			Rect(column * 32, row * 32, 32, 32));
	}
}

void CAniBox::SetScene(GameScene *tpScene)
{
	mpScene = tpScene;
}

void CAniBox::Build()
{
	mpScene->addChild(mpActor,10);
}

void CAniBox::RunAnimation()
{
	mpAnimate = Animate::create(mpAnimation);
	mpActor->runAction(mpAnimate);
}

void CAniBox::setPosition(Vec2 tVec)
{
	mVec.x = tVec.x;
	mVec.y = tVec.y;
	mpActor->setPosition(mVec);
}

/*
void CAniBox::Create(string tAniName, int tTotalFrameCount, float tDelayTime)
{
	mAniName = tAniName;

	mTotalFrameCount = tTotalFrameCount;

	mDelayTime = tDelayTime;




	int ti = 0;

	auto tCache = SpriteFrameCache::getInstance();
	// ���ֻ���ϴ� ���� �Ź� �ҷ����� �����Ÿ���. 
	// Cache�޸𸮿� �����ߴٰ� �ٷιٷ� �ҷ��´�.    

	//string tAniName = "idle";
	string tFileName = mAniName + ".plist";

	//tCache->addSpriteFramesWithFile(tFileName);

	//Cache�޸𸮿� �����ߴ� �ҷ������� �ϴ� �ڵ�.
	//getSpriteFrameByName�� ��������� tFileName�� �̹����� ĳ���� ä��ϴ�.

	//ĳ���� �־��� ������ ������� �ϸ� if���� ������ 1ȸ�� �ɸ���, �� ���Ŀ��� �̹����� �ε������ʰ� �ѱ��. 
	if (NULL == tCache->getSpriteFrameByName(mAniName + "_dance_01.png"))
	{
		tCache->addSpriteFramesWithFile(tFileName);
	}


	SpriteFrame *tSpriteFrame = NULL;
	char tStr[512];
	memset(tStr, 0, 512);

	string tFrameName = "";

	for (ti = 0; ti < mTotalFrameCount; ti++)
	{
		tSpriteFrame = NULL;
		//sprintf(tStr, "_%02d.png", ti);
		sprintf(tStr, "_dance_%02d.png", ti + 1);


		tFrameName = "";
		tFrameName = mAniName + tStr;


		tSpriteFrame = tCache->getSpriteFrameByName(tFrameName);
		tSpriteFrameVec.pushBack(tSpriteFrame);
	}

	//������ �ִϸ��̼�
	//tSpriteC = Sprite::createWithSpriteFrameName(mAniName + "_00.png");
	tSpriteC = Sprite::createWithSpriteFrameName(mAniName + "_dance_01.png");
	tSpriteC->retain();




	auto tAnimationC = Animation::createWithSpriteFrames(tSpriteFrameVec, mDelayTime);
	auto tAnimateC = Animate::create(tAnimationC);
	tRepeatForeverC = RepeatForever::create(tAnimateC);
	tRepeatForeverC->retain();	//retain�� ���� ������ �����ܿ��� ������ �޸𸮿��� ����������.
}								//cocos2d������ �޸� ������ �ִ��� �������Ѵ�.
								//ȭ�鿡 ǥ���� ������ �� ���������� �ʴ´�.
void CAniBox::Destroy()
{
	if (NULL != tRepeatForeverC)
	{
		tRepeatForeverC->release();
		tRepeatForeverC = NULL;
	}

	if (NULL != tSpriteC)
	{
		tSpriteC->release();
		tSpriteC = NULL;
	}
}

void CAniBox::Build()
{
	mpScene->addChild(tSpriteC, 3);
}
void CAniBox::UnBuild()
{
	mpScene->removeChild(tSpriteC);
}

void CAniBox::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}


void CAniBox::SetPosition(Vec2 tVec)
{
	tSpriteC->setPosition(tVec);
}

void CAniBox::RunAni()
{

	tSpriteC->runAction(tRepeatForeverC);
}
void CAniBox::StopAni()
{
	tSpriteC->stopAction(tRepeatForeverC);
}

void CAniBox::Show()
{
	tSpriteC->setVisible(true);
}
void CAniBox::Hide()
{
	tSpriteC->setVisible(false);
}

bool CAniBox::IsShow()
{
	bool tResult = false;

	tResult = tSpriteC->isVisible();

	return tResult;
}

*/