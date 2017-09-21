// 170710_Lesson_Shutting.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
#include "Enemy_2.h"
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
	char tPixel[HEIGHT][WIDTH] = { 0, };//ȭ�� �� �䳻���°�.

	int tEnemyCount = 10;
	int tEnemyCount_2 = 3;

	//	int tEnemyCount = 10;
	//	int tEnemyCount_2 = 3;


	CActor tActor;
	CEnemy tEnemy[10];
	CEnemy_2 tEnemy_2[3];

	int tRow = 0;
	int tCol = 0;

	/////Setup : �ʱ�ȭ
	tActor.Setup();

	for (int tj = 0; tj < tEnemyCount; tj++)
	{
		tEnemy[tj].Setup(WIDTH / 10 * tj);
	}
	for (int ti = 0; ti < tEnemyCount_2; ti++)
	{
		tEnemy_2[ti].Setup(WIDTH / 4 * ti);
	}

	//Setup : �ʱ�ȭ





	//Display Title
	cout << "��Ÿ����" << endl;
	Sleep(1000);


	//���ӷ���
	bool tIsEnd = false;
	char tKey = 0;

	while (true)
	{

		//Clean
		tActor.Clean(&tPixel[0][0]);

		for (int tj = 0; tj < tEnemyCount; tj++)
		{
			tEnemy[tj].Clean(&tPixel[0][0]);
		}
		for (int ti = 0; ti < tEnemyCount_2; ti++)
		{
			tEnemy_2[ti].Clean(&tPixel[0][0]);
		}
		//Clean



		//�� ����
		for (int tj = 0; tj < tEnemyCount; tj++)
		{
			tEnemy[tj].MoveWithInput();
			tEnemy[tj].Fire();
			tEnemy[tj].Update();
		}

		for (int ti = 0; ti < tEnemyCount_2; ti++)
		{
			tEnemy_2[ti].MoveWithInput();
			tEnemy_2[ti].Fire();
			tEnemy_2[ti].Update();
		}
		//�� ����

		//���� �κ�
		if (0 != _kbhit())
		{
			tKey = _getch();
			tActor.MoveWithInput(tKey);
			tIsEnd = GameQuit(tKey);
		}

		tActor.Move(&tActor);

		if (1 == tActor.GetmState())
		{
			GameQuit('q');
		}

		//Display
		ClearScreen(0, 0);

		//��º�//////////////
		tActor.Display(&tPixel[0][0]);


		for (int tj = 0; tj < tEnemyCount; tj++)
		{
			tEnemy[tj].Display(&tPixel[0][0]);
		}

		for (int ti = 0; ti < tEnemyCount_2; ti++)
		{
			tEnemy_2[ti].Display(&tPixel[0][0]);
		}

		//��º�//////////////
		
		//�浹 ó��/////////////////
		for (int tj = 0; tj < tEnemyCount; tj++)
		{
			for (int ti = 0; ti < 10; ti++)
			{
				if (tActor.ActorBulletX(ti) == tEnemy[tj].GetX() && tActor.ActorBulletY(ti) == tEnemy[tj].GetY())
				{
					tEnemy[tj].SetmState(STATE_DEAD);
				}
			}
		}
		for (int tj = 0; tj < tEnemyCount_2; tj++)
		{
			for (int ti = 0; ti < 10; ti++)
			{
				if (tActor.ActorBulletX(ti) == tEnemy_2[tj].GetX() && tActor.ActorBulletY(ti) == tEnemy_2[tj].GetY())
				{
					tEnemy_2[tj].SetmState(STATE_DEAD);
				}
			}
		}
		for (int tj = 0; tj < tEnemyCount; tj++)
		{
			for (int ti = 0; ti < 10; ti++)
			{
				if (tEnemy[tj].EnemyBulletX(ti) == tActor.GetX() && tEnemy[tj].EnemyBulletY(ti) == tActor.GetY())
				{
					tIsEnd = true;
				}
			}
		}
		for (int tj = 0; tj < tEnemyCount_2; tj++)
		{
			for (int ti = 0; ti < 10; ti++)
			{
				if (tEnemy_2[tj].EnemyBulletX(ti) == tActor.GetX() && tEnemy_2[tj].EnemyBulletY(ti) == tActor.GetY())

				{
					tIsEnd = true;
				}
			}

		}
		//�浹 ó��/////////////////

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
	for (tRow = 0; tRow < HEIGHT; tRow++)
	{
		for (tCol = 0; tCol < WIDTH; tCol++)
		{
			tPixel[tRow][tCol] = 0;
			cout << tPixel[tRow][tCol];
		}
	}
	cout << "Game Over" << endl;

	int buff = 0;
	cin >> buff;

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
