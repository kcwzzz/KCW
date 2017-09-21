#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	/*
	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
	origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	*/

	int ti = 0;
	int tRow = 0;
	int tCol = 0;


	//step01 스프라이트(그냥 이미지) 만들고 표시하기
	/*
	auto sprite = Sprite::create("grossini_dance_01.png");

	sprite->setPosition(Vec2(400.0f, 240.0f));

	this->addChild(sprite, 0);
	*/

	//step02 스프라이트 애니메이션 하기( 각각의 프레임들은 여러개의 파일로 구성 )
	/*
	auto tSpriteA = Sprite::create("grossini_dance_01.png");
	tSpriteA->setPosition(Vec2(400.0f, 240.0f));
	this->addChild( tSpriteA, 1 );


	auto tAnimation = Animation::create();	//애니메이션
	tAnimation->setDelayPerUnit(0.3f); //프레임간 지연시간

	tAnimation->addSpriteFrameWithFile("grossini_dance_01.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_02.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_03.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_04.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_05.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_06.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_07.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_08.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_09.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_10.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_11.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_12.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_13.png");
	tAnimation->addSpriteFrameWithFile("grossini_dance_14.png");

	auto tAnimate = Animate::create(tAnimation);

	auto tRepeatForever = RepeatForever::create( tAnimate );

	tSpriteA->runAction( tRepeatForever );
	*/


	//step03 SPRITE SHEET 애니메이션:
	/*
	//스프라이트 애니메이션 하기( 모든 프레임들을 모아 하나의 이미지 파일로 구성, 각각의 프레임들은 모두 동일 크기 )
	float tWidth    = 0.0f;//85;
	float tHeight   = 0.0f;//121;


	//512:85 = width: ?
	//(85*width)/512 = ?

	//512:121 = height: ?
	//(121*height)/512 = ?



	auto tSpriteSrc = Sprite::create("grossini_dance_atlas.png");
	auto tTexture = tSpriteSrc->getTexture();


	tWidth = ((tSpriteSrc->getContentSize().width)*85)/512;
	tHeight = ((tSpriteSrc->getContentSize().height*121))/512;

	auto tAnimationB = Animation::create();
	tAnimationB->setDelayPerUnit(0.3f);


	for( ti = 0; ti<14; ti++ )
	{
	tRow = ti/5;
	tCol = ti%5; // 행과 열을 구하는 식


	tAnimationB->addSpriteFrameWithTexture(tTexture, Rect(tCol*tWidth, tRow*tHeight, tWidth, tHeight));
	}

	//Size tSize = tTexture->getContentSizeInPixels();
	//cocos2d::log("%d", tSize.width);

	auto tSpriteB = Sprite::create("grossini_dance_atlas.png", Rect(0, 0, tWidth, tHeight));
	tSpriteB->setPosition(Vec2(400.0f, 240.0f));
	this->addChild( tSpriteB, 2 );

	auto tAnimateB = Animate::create( tAnimationB );
	auto tRepeatForeverB = RepeatForever::create( tAnimateB );
	tSpriteB->runAction( tRepeatForeverB );
	*/

	//step04 스프라이트 애니메이션 하기( 모든 프레임들을 모아 하나의 이미지 파일로 구성, 각각의 프레임들을 모두 크기가 다르다, 프레임들의 정보는 plist파일로 관리 )
		//plist의 '원조'는? 프로퍼티 리스트. 그런데 여기서는 '애니메이션 설정 정보'를 담는 용도로 쓰이고 있다.
	
	auto tCache = SpriteFrameCache::getInstance();
	tCache->addSpriteFramesWithFile("images/grossini.plist");

	cocos2d::Vector<SpriteFrame *> tSpriteFrameVec;//vector 가변배열

	SpriteFrame *tSpriteFrame = NULL;

	char tStr[512];
	memset(tStr, 0, 512); 

	for (ti = 1; ti<15; ti++)
	{
		tSpriteFrame = NULL;

		sprintf(tStr, "grossini_dance_%02d.png", ti);		//%02 자리수 2개 확보
		tSpriteFrame = tCache->getSpriteFrameByName(tStr);

		tSpriteFrameVec.pushBack(tSpriteFrame);
	}


	auto tSpriteC = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	tSpriteC->setPosition(Vec2(400.0f, 240.0f));
	this->addChild(tSpriteC, 3);

	auto tAnimationC = Animation::createWithSpriteFrames(tSpriteFrameVec, 0.3f);
	auto tAnimateC = Animate::create(tAnimationC);
	auto tRepeatForeverC = RepeatForever::create(tAnimateC);

	tSpriteC->runAction(tRepeatForeverC);





	//스프라이트 애니메이션 하기( 배칭 적용 )<--예전엔 쓸모가 있었는데 지금은 차이가 없다.
	//Do();
	//DoWithBatch();

	return true;
}

/*
void HelloWorld::Do()
{
float tWidth    = 0.0f;//85;
float tHeight   = 0.0f;//121;


//512:85 = width: ?
//(85*width)/512 = ?

//512:121 = height: ?
//(121*height)/512 = ?



auto tSpriteSrc = Sprite::create("grossini_dance_atlas.png");
auto tTexture = tSpriteSrc->getTexture();


tWidth = ((tSpriteSrc->getContentSize().width)*85)/512;
tHeight = ((tSpriteSrc->getContentSize().height*121))/512;




int ti = 0;
int tRow = 0;
int tCol = 0;


for( ti = 0; ti<100; ti++ )
{
tRow = ti/5;
tCol = ti%5;


auto tSprite = Sprite::createWithTexture(tTexture,
Rect( tCol*tWidth, tRow*tHeight, tWidth, tHeight));



tSprite->setPosition( Vec2(tCol*tWidth, tRow*tHeight));

this->addChild( tSprite );
}


}

//어떤 상황과 비교해서 좋다는 건가?<--예전엔 쓸모가 있었는데 지금은 그닥 차이가 없다. 내부적으로 다 배치로 처리한다.
void HelloWorld::DoWithBatch()
{
float tWidth    = 0.0f;//85;
float tHeight   = 0.0f;//121;






int ti = 0;
int tRow = 0;
int tCol = 0;


auto tSpriteBatchNode = SpriteBatchNode::create("grossini_dance_atlas.png", 50);

tWidth = ((tSpriteBatchNode->getContentSize().width)*85)/512;
tHeight = ((tSpriteBatchNode->getContentSize().height*121))/512;


this->addChild(tSpriteBatchNode, 0, 1);


auto tTexture_0 = tSpriteBatchNode->getTexture();

for( ti = 0; ti<100; ti++ )
{
tRow = ti/5;
tCol = ti%5;


auto tSprite = Sprite::createWithTexture(tTexture_0,
Rect( tCol*tWidth, tRow*tHeight, tWidth, tHeight));

tSprite->setPosition( Vec2(tCol*tWidth, tRow*tHeight));

tSpriteBatchNode->addChild( tSprite );
}
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
