#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CActor.h"
#include "Define.h"

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
    if ( !Scene::init() )
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
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


	auto DirMenu_0 = MenuItemFont::create("UP", CC_CALLBACK_0(HelloWorld::SetmDir_0, this));
	DirMenu_0->setPosition(Vec2(300, 300));

	auto DirMenu_1 = MenuItemFont::create("Down", CC_CALLBACK_0(HelloWorld::SetmDir_1, this));
	DirMenu_1->setPosition(Vec2(300, 250));

	auto DirMenu_2 = MenuItemFont::create("Left", CC_CALLBACK_0(HelloWorld::SetmDir_2, this));
	DirMenu_2->setPosition(Vec2(300, 200));

	auto DirMenu_3 = MenuItemFont::create("Right", CC_CALLBACK_0(HelloWorld::SetmDir_3, this));
	DirMenu_3->setPosition(Vec2(300, 150));


	auto MenuDir = Menu::create(DirMenu_0, DirMenu_1, DirMenu_2, DirMenu_3, NULL);
	MenuDir->setPosition(Vec2::ZERO);
	this->addChild(MenuDir, 1);

	

	//idle 누르면 stop 하게 된다.
	auto FSMMenu_0 = MenuItemFont::create("IDle", CC_CALLBACK_0(HelloWorld::SetFSM_0, this));
	FSMMenu_0->setPosition(Vec2(450, 300));

	//idle 누르면 걷는 animation 하게 된다.
	auto FSMMenu_1 = MenuItemFont::create("Move", CC_CALLBACK_0(HelloWorld::SetFSM_1, this));
	FSMMenu_1->setPosition(Vec2(450, 250));


	auto MenuFSM = Menu::create(FSMMenu_0, FSMMenu_1, NULL);
	MenuFSM->setPosition(Vec2::ZERO);
	this->addChild(MenuFSM, 1);


	/////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
	

	/*
	mpActorAniBox = new CActorAniBox();
	mpActorAniBox->SetScene(this);
	mpActorAniBox->CreateAniBox("Hero_1.png", Vec2(200,100), 64, 64, 0.3f);
	*/
	//mpActor->RunAnimation();

	mpActor = new CActor();
	mpActor->SetSecne(this);
	mpActor->Create();

	this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
	mpActor->FSM_Selector();
	mpActor->Dir_Selector();
}


void HelloWorld::SetmDir_0()
{
	mpActor->SetmDir(Up_Dir);
}

void HelloWorld::SetmDir_1()
{
	mpActor->SetmDir(Down_Dir);
}


void HelloWorld::SetmDir_2()
{
	mpActor->SetmDir(Left_Dir);
}


void HelloWorld::SetmDir_3()
{
	mpActor->SetmDir(Right_Dir);
}

void HelloWorld::SetFSM_0()
{
	mpActor->SetFsm(0);
}

void HelloWorld::SetFSM_1()
{
	mpActor->SetFsm(1);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
}
