#include "CSoundManager.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;


CSoundManager *CSoundManager::mpInstance = NULL;


CSoundManager::CSoundManager()
{

}

CSoundManager:: ~CSoundManager()
{

}

CSoundManager *CSoundManager::Getinstance()
{
	if(NULL == mpInstance)
	{
		mpInstance = new CSoundManager();
		return mpInstance;
	}
	return mpInstance;
}

void CSoundManager::Create()
{

	SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);

	mStringBGMArray[0] = "Sounds/background.mp3";
	mStringEffectArray[0] = "Sounds/effect1.wav";

	int ti = 0;
	int tCount = 0;

	tCount = 1;
	for (int ti = 0; ti < tCount; ti++)
	{
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic(mStringBGMArray[ti].c_str());
	}

	tCount = 1;
	for (int ti = 0; ti < tCount; ti++)
	{
		SimpleAudioEngine::getInstance()->preloadEffect(mStringEffectArray[ti].c_str());
	}
}

void CSoundManager::Destroy()
{
	SimpleAudioEngine::getInstance()->unloadEffect(mStringEffectArray[0].c_str());

	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::end();

}

void CSoundManager::PlayEffect(int tIndex)
{
	SimpleAudioEngine::getInstance()->playEffect(mStringEffectArray[tIndex].c_str());
}

void CSoundManager::StopAllEffects()
{
	SimpleAudioEngine::getInstance()->stopAllEffects();
}
