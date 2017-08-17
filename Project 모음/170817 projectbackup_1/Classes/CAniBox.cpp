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
	// 자주사용하는 것은 매번 불러오면 오래거린다. 
	// Cache메모리에 저장했다가 바로바로 불러온다.    

	//string tAniName = "idle";
	string tFileName = mAniName + ".plist";

	//tCache->addSpriteFramesWithFile(tFileName);

	//Cache메모리에 저장했다 불러오도록 하는 코드.
	//getSpriteFrameByName이 비어있으면 tFileName인 이미지를 캐쉬에 채웁니다.

	//캐쉬에 넣었기 때문에 디버깅을 하면 if안의 내용은 1회만 걸리고, 그 이후에는 이미지를 로딩하지않고 넘긴다. 
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

	//실제로 애니메이션
	//tSpriteC = Sprite::createWithSpriteFrameName(mAniName + "_00.png");
	tSpriteC = Sprite::createWithSpriteFrameName(mAniName + "_dance_01.png");
	tSpriteC->retain();




	auto tAnimationC = Animation::createWithSpriteFrames(tSpriteFrameVec, mDelayTime);
	auto tAnimateC = Animate::create(tAnimationC);
	tRepeatForeverC = RepeatForever::create(tAnimateC);
	tRepeatForeverC->retain();	//retain을 하지 않으면 엔진단에서 변수를 메모리에서 날려버린다.
}								//cocos2d에서의 메모리 관리는 최대한 개인이한다.
								//화면에 표시한 변수는 잘 날려먹지는 않는다.
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