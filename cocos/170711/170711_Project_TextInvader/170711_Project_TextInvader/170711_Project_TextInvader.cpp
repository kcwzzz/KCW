// exam_starwars_20160617.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

#include "Define.h"

#include "Actor.h"
#include "Enemy.h"

using namespace std;

void ClearScreen(int tX, int tY);
bool GameQuitSwitch(char tKey, bool tIsEnd);

//드랍박스에 오늘 작업한 거 마무리 정리해서 올려주세요.
int main()
{
	//Create
	srand((unsigned int)time(NULL));

	char tPixel[HEIGHT][WIDTH] = { 0, };//화면 을 흉내내는거.
										//아군기는 A로 표시하자.
										//유저의 키입력을 받아 좌우 이동을 구현하자
	CActor tActor;
	CEnemy tEnemy;

	int tRow = 0;
	int tCol = 0;

	tActor.Setup();
	tEnemy.Setup();
	//Display Title
	cout << "스타워즈" << endl;
	Sleep(5000);

	//게임루프
	bool tIsEnd = false;
	char tKey = 0;
	while (true)
	{
		//Clean
		tActor.Clean(&tPixel[0][0]);
		tEnemy.Clean(&tPixel[0][0]);

		tEnemy.Move();
		tEnemy.Update();
		//tEnemy.MoveWithInput(&tEnemy);

		tKey = 0;

		if (0 != _kbhit())
		{
			tKey = _getch();

			tActor.MoveWithInput(tKey);
			tIsEnd = GameQuitSwitch(tKey, tIsEnd);
		}
		
		tActor.Move();

		//Display
		ClearScreen(0, 0);

		tActor.Display(&tPixel[0][0]);
		tEnemy.Display(&tPixel[0][0]);
		
		for (tRow = 0; tRow < HEIGHT; tRow++)
		{
			for (tCol = 0; tCol < WIDTH; tCol++)
			{
				cout << tPixel[tRow][tCol];
			}
		}
		//충돌 체크 collision 
		//if (tEnemyBulletX == tActorX && tEnemyBulletY == tActorY)
		//{
		//	cout << "충돌: 아군기 사망" << endl;
		//}

		if (true == tIsEnd)
		{
			break;
		}
	}
	//Destroy
	return 0;
}
bool GameQuitSwitch(char tKey, bool tIsEnd)
{
	switch (tKey)
	{
	case 'Q':
	case 'q':
	{
		tIsEnd = true;
	}
	break;
	}
	return tIsEnd;
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