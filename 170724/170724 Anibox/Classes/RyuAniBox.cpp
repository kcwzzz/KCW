#include "RyuAniBox.h"


#include "cocos2d.h"

#include "HelloWorldScene.h"

USING_NS_CC;

CRyuAniBox::CRyuAniBox()
{
}


CRyuAniBox::~CRyuAniBox()
{
}


void CRyuAniBox::Create(string tAniName, int tTotalFrameCount, float tDelayTime)
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
void CRyuAniBox::Destroy()
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

void CRyuAniBox::Build()
{
	mpScene->addChild(tSpriteC, 3);
}
void CRyuAniBox::UnBuild()
{
	mpScene->removeChild(tSpriteC);
}

void CRyuAniBox::SetScene(Node *tpScene)
{
	mpScene = tpScene;
}


void CRyuAniBox::SetPosition(Vec2 tVec)
{
	tSpriteC->setPosition(tVec);
}

void CRyuAniBox::RunAni()
{

	tSpriteC->runAction(tRepeatForeverC);
}
void CRyuAniBox::StopAni()
{
	tSpriteC->stopAction(tRepeatForeverC);
}

void CRyuAniBox::Show()
{
	tSpriteC->setVisible(true);
}
void CRyuAniBox::Hide()
{
	tSpriteC->setVisible(false);
}

bool CRyuAniBox::IsShow()
{
	bool tResult = false;

	tResult = tSpriteC->isVisible();

	return tResult;
}
