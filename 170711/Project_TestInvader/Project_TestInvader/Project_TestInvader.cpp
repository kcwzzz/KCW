// 170710_Lesson_Shutting.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

// exam_starwars_20160617.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#include "Define.h"
#include "Actor.h"
#include "Enemy.h"
#include "EnemyBoss.h"
#include "ActorBullet.h"
#include "EnemyBullet.h"

using namespace std;

int gSoundFreqArray[] = { 523,587,659,698,0, 784,880,988,1046 };

void DoSoundGameStart();
void ClearScreen(int tX, int tY);
bool GameQuit(char tKey);

int main()
{
	//Create
	char tPixel[HEIGHT][WIDTH] = { 0, };//화면 을 흉내내는거.

	CActor tActor;
	CEnemy tEnemy;
	CEnemyBoss tEnemyBoss;

	int tRow = 0;
	int tCol = 0;

	//Setup : 초기화
	tActor.Setup();
	tEnemy.Setup();
	tEnemyBoss.Setup();
	//Display Title
	cout << "스타워즈" << endl;
	Sleep(1000);

	//게임루프
	bool tIsEnd = false;
	char tKey = 0;

	while (true)
	{
		//Clean
		tActor.Clean(&tPixel[0][0]);
		tEnemy.Clean(&tPixel[0][0]);
		tEnemyBoss.Clean(&tPixel[0][0]);

		tEnemy.MoveWithInput();
		tEnemy.Fire();
		tEnemy.Update();

		tEnemyBoss.MoveWithInput();
		tEnemyBoss.Fire();
		tEnemyBoss.Update();

		//조작 부분
		if (0 != _kbhit())
		{
			tKey = _getch();

			tActor.MoveWithInput(tKey);
			tIsEnd = GameQuit(tKey);
		}

		tActor.Move();
	
		//Display
		ClearScreen(0, 0);

		tActor.Display(&tPixel[0][0]);
		tEnemy.Display(&tPixel[0][0]);
		tEnemyBoss.Display(&tPixel[0][0]);

		for (tRow = 0; tRow < HEIGHT; tRow++)
		{
			for (tCol = 0; tCol < WIDTH; tCol++)
			{
				cout << tPixel[tRow][tCol];
			}
		}

		if (true == tIsEnd)
		{
			break;
		}
	}
	//Destroy
	return 0;
}

void ClearScreen(int tX, int tY)
{
	CONSOLE_CURSOR_INFO cci;
	CONSOLE_CURSOR_INFO cci_old;

	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleCursorInfo(hOutput, &cci_old);

	cci.bVisible = FALSE;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);

	COORD cd;
	cd.X = tX;
	cd.Y = tY;
	SetConsoleCursorPosition(hOutput, cd);

	SetConsoleCursorInfo(hOutput, &cci_old);
}
void DoSoundGameStart()
{

	int tRow = 0;

	for (tRow = 0; tRow < 7; tRow++)
	{
		Beep(gSoundFreqArray[5], 100 * tRow);
		Sleep(5);
	}
}
bool GameQuit(char tKey)
{
	bool tIsEnd = 0;

	switch (tKey)
	{
	case 'Q':
	case 'q':
	{
		tIsEnd = true;
		break;
	}
	}
	return tIsEnd;
}
