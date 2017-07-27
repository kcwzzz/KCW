#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

/*
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE		"Sounds/Effect2.ogg"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
#define EFFECT_FILE		"Sounds/Effect1.raw"
#else
#define EFFECT_FILE		"Sounds/Effect1.wav"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE		"Sounds/music.mid"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#define MUSIC_FILE		"Sounds/background.ogg"
#else
#define MUSIC_FILE		"Sounds/background.mp3"
#endif
*/

// android effect only support ogg

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE        "Sounds/effect2.ogg"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
#define EFFECT_FILE        "Sounds/effect1.raw"
#else
#define EFFECT_FILE        "Sounds/effect1.wav"
#endif // CC_PLATFORM_ANDROID

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE        "Sounds/Tiger.mp3"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#define MUSIC_FILE        "Sounds/background.ogg"
#else
#define MUSIC_FILE        "Sounds/background.mp3"
#endif // CC_PLATFORM_WIN32

std::string menuItems[] = {
	"play background music",
	"pause background music",
	"resume background music",
	"stop background music",
	"play effect",
	"play effect repeatly",
	"pause effect",
	"resume effect",
	"stop effect",
};

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	srand((unsigned)time(NULL));

	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);


	auto tpMenu = Menu::create();

	int tCount = 9;
	for (int ti = 0; ti < tCount; ti++)
	{
		auto tLabel = Label::createWithTTF(menuItems[ti].c_str(), "fonts/arial.ttf", 24);
		tLabel->setColor(Color3B(255, 255, 255));
		auto tpMenuItem = MenuItemLabel::create(
			tLabel,
			CC_CALLBACK_1(HelloWorld :: doSoundAction, this) );

			tpMenu->addChild(tpMenuItem, ti + 10000);
	}

	tpMenu->alignItemsVertically();
	this->addChild(tpMenu);

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MUSIC_FILE);
	SimpleAudioEngine::getInstance()->preloadEffect(EFFECT_FILE);

	SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);

	return true;
}

void HelloWorld::onExit()
{
	SimpleAudioEngine::getInstance()->unloadEffect(EFFECT_FILE);
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);

	SimpleAudioEngine::end();

	Scene::onExit();

}
void HelloWorld::doSoundAction(Ref* pSender)
{
	auto tpMenuItem = (MenuItem *)(pSender);
	int tIndex = tpMenuItem->getLocalZOrder() - 10000;

	switch (tIndex)
	{
	case 0:
		SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSIC_FILE, true);
		break;

	case 1:
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		break;

	case 2:
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		break;

	case 3:
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		break;

	case 4:
		mSoundId = SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE);
		break;

	case 5:
		mSoundId = SimpleAudioEngine::getInstance()->playEffect(EFFECT_FILE,true);
		break;

	case 6:
		SimpleAudioEngine::getInstance()->pauseEffect(mSoundId);
		break;

	case 7:
		SimpleAudioEngine::getInstance()->resumeEffect(mSoundId);
		break;

	case 8:
		SimpleAudioEngine::getInstance()->stopEffect(mSoundId);
		break;


	}

}

void HelloWorld::menuCloseCallback(Ref* pSender)
{


	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif


}
