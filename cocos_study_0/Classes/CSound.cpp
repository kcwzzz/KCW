#include "CSound.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;


CSound *CSound::mpInstance = NULL;

CSound *CSound::Getinstance()
{
	if (NULL == mpInstance)
	{
		mpInstance = new CSound();
		return mpInstance;
	}

	return mpInstance;
}

void CSound::Create()
{
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
	SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);

	mStringBGMArray[0] = "Sounds/hearthstone.mp3";
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

void CSound::Destroy()
{
	SimpleAudioEngine::getInstance()->unloadEffect(mStringEffectArray[0].c_str());
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::end();
}

void CSound::PlayBGM(int tIndex, bool tIsLoop)
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic(mStringBGMArray[tIndex].c_str());
}

void CSound::StopBGM()
{
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void CSound::PlayEffect(int tIndex)
{
	SimpleAudioEngine::getInstance()->playEffect(mStringEffectArray[tIndex].c_str());
}

void CSound::StopAllEffects()
{
	SimpleAudioEngine::getInstance()->stopAllEffects();
}