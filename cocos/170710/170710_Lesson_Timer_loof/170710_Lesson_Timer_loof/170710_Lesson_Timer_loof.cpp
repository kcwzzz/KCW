// 170710_Lesson_Timer_loof.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

#define DELAY_INTERVAL 1000

unsigned int gTick = 0;

unsigned int GetTick();
void UpdateTick();
void OnTimerDoSomething();


int main()
{
	void(*tpPtr)() = NULL;
	tpPtr = OnTimerDoSomething;

	int tDelay = 0;
	int tTemp = 0;
	int tCount = 0;

	while (true)
	{
		if (0 == tDelay)
		{
			tDelay = GetTick();
		}

		tTemp = GetTick();

		if(tTemp - tDelay >DELAY_INTERVAL)
		{
			tpPtr();

			cout << tCount << endl;
			tCount++;

			tDelay = tTemp;
		}			//UpdateTick();
	}
    return 0;
}

unsigned int GetTick()
{
	//return gTick;
	return GetTickCount(); //1ms마다 카운트하는 함수
}


void UpdateTick()
{
	gTick++;
}

void OnTimerDoSomething()
{
	cout << "Time Alive" << endl;
}