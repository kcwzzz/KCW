#pragma once

#include <stdio.h>

#include <vector>
#include "cocos2d.h"

using namespace std;

class CSound
{
private:

	static CSound *mpInstance;
	string mStringBGMArray[3] = { "" };
	string mStringEffectArray[1] = { "" };


protected:

public:
	static CSound *Getinstance();

	void Create();
	void Destroy();

	void PlayBGM(int Tindex, bool tIsLoop = true);
	void StopBGM();

	void PlayEffect(int tIndex);
	void StopAllEffects();



};