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


	//step01 ��������Ʈ(�׳� �̹���) ����� ǥ���ϱ�
	/*
	auto sprite = Sprite::create("grossini_dance_01.png");

	sprite->setPosition(Vec2(400.0f, 240.0f));

	this->addChild(sprite, 0);
	*/

	//step02 ��������Ʈ �ִϸ��̼� �ϱ�( ������ �����ӵ��� �������� ���Ϸ� ���� )
	/*
	auto tSpriteA = Sprite::create("grossini_dance_01.png");
	tSpriteA->setPosition(Vec2(400.0f, 240.0f));
	this->addChild( tSpriteA, 1 );


	auto tAnimation = Animation::create();	//�ִϸ��̼�
	tAnimation->setDelayPerUnit(0.3f); //�����Ӱ� �����ð�

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


	//step03 SPRITE SHEET �ִϸ��̼�:
	/*
	//��������Ʈ �ִϸ��̼� �ϱ�( ��� �����ӵ��� ��� �ϳ��� �̹��� ���Ϸ� ����, ������ �����ӵ��� ��� ���� ũ�� )
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
	tCol = ti%5; // ��� ���� ���ϴ� ��


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

	//step04 ��������Ʈ �ִϸ��̼� �ϱ�( ��� �����ӵ��� ��� �ϳ��� �̹��� ���Ϸ� ����, ������ �����ӵ��� ��� ũ�Ⱑ �ٸ���, �����ӵ��� ������ plist���Ϸ� ���� )
		//plist�� '����'��? ������Ƽ ����Ʈ. �׷��� ���⼭�� '�ִϸ��̼� ���� ����'�� ��� �뵵�� ���̰� �ִ�.
	
	auto tCache = SpriteFrameCache::getInstance();
	tCache->addSpriteFramesWithFile("images/grossini.plist");

	cocos2d::Vector<SpriteFrame *> tSpriteFrameVec;//vector �����迭

	SpriteFrame *tSpriteFrame = NULL;

	char tStr[512];
	memset(tStr, 0, 512); 

	for (ti = 1; ti<15; ti++)
	{
		tSpriteFrame = NULL;

		sprintf(tStr, "grossini_dance_%02d.png", ti);		//%02 �ڸ��� 2�� Ȯ��
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





	//��������Ʈ �ִϸ��̼� �ϱ�( ��Ī ���� )<--������ ���� �־��µ� ������ ���̰� ����.
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

//� ��Ȳ�� ���ؼ� ���ٴ� �ǰ�?<--������ ���� �־��µ� ������ �״� ���̰� ����. ���������� �� ��ġ�� ó���Ѵ�.
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
