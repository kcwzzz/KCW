// 170710_Lesson_Timer_loof.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	return GetTickCount(); //1ms���� ī��Ʈ�ϴ� �Լ�
}


void UpdateTick()
{
	gTick++;
}

void OnTimerDoSomething()
{
	cout << "Time Alive" << endl;
}