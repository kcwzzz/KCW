#pragma once

#include <stdio.h>

#include <vector>
#include "cocos2d.h"

using namespace std;

class CSoundManager
{
private:
	static CSoundManager *mpInstance;
	//���ʱ�ȭ�� ���� �ʴ� ���� : ���������� ����Ǵ� ������ �ٸ��� ������
	
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