#pragma once

#include <stdio.h>

#include <vector>
#include "cocos2d.h"

using namespace std;

class CSoundManager
{
private:
	static CSoundManager *mpInstance;
	//ㅇ초기화를 하지 않는 이유 : 물리적으로 저장되는 공간이 다르기 때문에
	
	CSoundManager();
	~CSoundManager();

	string mStringBGMArray[1] = { "" };
	string mStringEffectArray[1] = { "" };

public:

	static CSoundManager *Getinstance();

	void Create();
	void Destroy();

	void PlayBGM(int Tindex, bool tIsLoop = true);
	void StopBGM();

	void PlayEffect(int tIndex);
	void StopAllEffects();

};