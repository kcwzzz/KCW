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

using namespace std;

int gSoundFreqArray[] = { 523,587,659,698,0, 784,880,988,1046 };

#define WIDTH 80
#define HEIGHT 24

#define DIR_LEFT  0
#define DIR_RIGHT 1

void DoSoundGameStart();
void ClearScreen(int tX, int tY);

bool GameQuit(char tKey);

class CActor
{
private:
	int tActorX = 0;
	int tActorY = 0;

public:
	void SetupActor(); //액터의 X,Y 좌표
	void MoveActorWithInput(char tKey); //조정
	void CleanPixelForActor(char *tpPixel); // 그래픽 클리어
	void DisplayPixelForActor(char *tpPixel); // 그래픽 표시

	int GetX();
};

class CEnemy
{
private:
	int tEnemyX = 0;
	int tEnemyY = 0;
	int tEnemyDir = 0;

public:
	void SetupEnemy(); //액터의 X,Y 좌표
	void MoveEnemyWithInput(); //조정
	void CleanPixelForEnemy(char *tpPixel); // 그래픽 클리어
	void DisplayPixelForEnemy(char *tpPixel); // 그래픽 표시
	
	int GetX();
	int GetY();
};

void SetupActorBullet(bool *tKey, int *tpX, int *tpY); //액터의 X,Y 좌표
bool FireActorBullet(char tKey, bool *tIsActorBulletLife, int *tpX, int tActorX, int *tpY); //조정
bool MoveActorBulletWithInput(bool *tIsActorBulletLife, int *tpY); //조정
void CleanPixelForActorBullet(char *tpPixel, int *tpX, int *tpY); // 그래픽 클리어
void DisplayPixelForActorBullet(char *tpPixel, int *tpX, int *tpY); // 그래픽 표시

void SetupEnemyBullet(bool *tKey, int *tpX, int *tpY); //액터의 X,Y 좌표
bool FireEnemyBullet(int tFire, bool *tIsEnemyBulletLife, int *tpX, int *tpY, int tEnemyX, int tEnemyY);
void CleanPixelForEnemyBullet(char *tpPixel, int *tpX, int *tpY); // 그래픽 클리어
void DisplayPixelForEnemyBullet(char *tpPixel, int *tpX, int *tpY); // 그래픽 표시

int main()
{
	//Create

	srand((unsigned int)time(NULL));

	char tPixel[HEIGHT][WIDTH] = { 0, };//화면 을 흉내내는거.

	CActor tActor;
	CEnemy tEnemy;

	int tFire = 0;
	int tEnemyBulletX = 0;
	int tEnemyBulletY = 0;
	bool tIsEnemyBulletLife = false;

	int tActorBulletX = 0;
	int tActorBulletY = 0;
	bool tIsActorBulletLife = false;

	int tRow = 0;
	int tCol = 0;

	//Setup : 초기화

	tActor.SetupActor();
	tEnemy.SetupEnemy();
	SetupActorBullet(&tIsActorBulletLife, &tActorBulletX, &tActorBulletY);
	SetupEnemyBullet(&tIsEnemyBulletLife, &tEnemyBulletX, &tEnemyBulletY);

	//Display Title
	cout << "스타워즈" << endl;
	Sleep(1000);

	//게임루프
	bool tIsEnd = false;
	char tKey = 0;

	while (true)
	{
		//Clean
		tActor.CleanPixelForActor(&tPixel[0][0]);
		tEnemy.CleanPixelForEnemy(&tPixel[0][0]);
		CleanPixelForActorBullet(&tPixel[0][0], &tActorBulletX, &tActorBulletY);
		CleanPixelForEnemyBullet(&tPixel[0][0], &tEnemyBulletX, &tEnemyBulletY);

		tEnemy.MoveEnemyWithInput();
		FireEnemyBullet(tFire, &tIsEnemyBulletLife, &tEnemyBulletX, &tEnemyBulletY, tEnemy.GetX(), tEnemy.GetY());

		//조작 부분
		if (0 != _kbhit())
		{
			tKey = _getch();

			tActor.MoveActorWithInput(tKey);
			tIsActorBulletLife = FireActorBullet(tKey, &tIsActorBulletLife, &tActorBulletX, tActor.GetX(), &tActorBulletY);
			tIsEnd = GameQuit(tKey);
		}

		tIsActorBulletLife = MoveActorBulletWithInput(&tIsActorBulletLife, &tActorBulletY);

		//Display
		ClearScreen(0, 0);

		tActor.DisplayPixelForActor(&tPixel[0][0]);
		tEnemy.DisplayPixelForEnemy(&tPixel[0][0]);
		DisplayPixelForActorBullet(&tPixel[0][0], &tActorBulletX, &tActorBulletY);
		DisplayPixelForEnemyBullet(&tPixel[0][0], &tEnemyBulletX, &tEnemyBulletY);

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

void CActor::SetupActor()
{
	tActorX = WIDTH / 2;
	tActorY = HEIGHT - 1;
}
void CActor::MoveActorWithInput(char tKey)
{
	switch (tKey)
	{
	case 'Z':
	case 'z':
	{
		if (tActorX > 0)
		{
			tActorX = tActorX - 1;
		}
		else
		{
			tActorX = tActorX;
		}
		break;
	}


	//우
	case 'C':
	case 'c':
	{
		if (tActorX < WIDTH - 1)
		{
			tActorX = tActorX + 1;
		}
		else
		{
			tActorX = tActorX;
		}
		break;
	}


	case 'S':
	case 's':
	{
		if (tActorY < HEIGHT - 1)
		{
			tActorY = tActorY + 1;
		}
		else
		{
			tActorY = tActorY;
		}
		break;
	}
	case 'X':
	case 'x':
	{
		if (tActorY < HEIGHT - 1)
		{
			tActorY = tActorY + 1;
		}
		else
		{
			tActorY = tActorY;
		}
		break;
	}
	}
}
void CActor::CleanPixelForActor(char *tpPixel)
{
	*(tpPixel + tActorY*WIDTH + tActorX) = 0;
}
void CActor::DisplayPixelForActor(char *tpPixel)
{
	*(tpPixel + tActorY*WIDTH + tActorX) = 'A';
}
int CActor::GetX()
{
	return tActorX;
}

void CEnemy::SetupEnemy() //액터의 X,Y 좌표
{
	tEnemyDir = DIR_LEFT;
	tEnemyX = WIDTH / 2;
	tEnemyY = 0;
}
void CEnemy::MoveEnemyWithInput() //조정
{

	if (DIR_RIGHT == tEnemyDir)
	{
		if (tEnemyX< WIDTH - 1)
		{
			tEnemyX = tEnemyX + 15;
		}
		else
		{
			tEnemyDir = DIR_LEFT;
		}
	}

	if (DIR_LEFT == tEnemyDir)
	{
		if (tEnemyX > 1)
		{
			tEnemyX = tEnemyX - 15;
		}
		else
		{
			tEnemyDir = DIR_RIGHT;
		}
	}
}
void CEnemy::CleanPixelForEnemy(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + tEnemyY*WIDTH + tEnemyX) = 0;
}
void CEnemy::DisplayPixelForEnemy(char *tpPixel) // 그래픽 표시
{
	*(tpPixel + tEnemyY*WIDTH + tEnemyX) = '#';
}
int CEnemy::GetX()
{
	return tEnemyX;
}
int CEnemy::GetY()
{
	return tEnemyY;
}

void SetupActorBullet(bool *tKey, int *tpX, int *tpY) //액터의 X,Y 좌표
{
	(*tKey) = false;
	(*tpX) = WIDTH / 2;
	(*tpY) = HEIGHT - 1 - 1;

}
bool FireActorBullet(char tKey, bool *tIsActorBulletLife, int *tpX, int tActorX, int *tpY) //조정
{
	switch (tKey)
	{
	case 'M':
	case 'm':
	{
		//발사지점
		(*tpX) = tActorX;
		(*tpY) = HEIGHT - 1 - 1;

		//발사됐는지 여부

		*tIsActorBulletLife = true;
		break;
	}
	}
	return tIsActorBulletLife;
}
bool MoveActorBulletWithInput(bool *tIsActorBulletLife, int *tpY) //조정
{
	if (true == *tIsActorBulletLife)
	{
		if ((*tpY) > 0)
		{
			(*tpY) = (*tpY) - 1;
		}
		else
		{
			(*tpY) = (*tpY);
			*tIsActorBulletLife = false;
		}
	}
	return tIsActorBulletLife;
}
void CleanPixelForActorBullet(char *tpPixel, int *tpX, int *tpY) // 그래픽 클리어
{
	*(tpPixel + (*tpY)*WIDTH + (*tpX)) = 0;
}
void DisplayPixelForActorBullet(char *tpPixel, int *tpX, int *tpY) // 그래픽 표시
{
	*(tpPixel + (*tpY)*WIDTH + (*tpX)) = '*';
}

void SetupEnemyBullet(bool *tKey, int *tpX, int *tpY) //액터의 X,Y 좌표
{
	(*tKey) = false;
	(*tpX) = WIDTH / 2;
	(*tpY) = 1;
}
bool FireEnemyBullet(int tFire, bool *tIsEnemyBulletLife, int *tpX, int *tpY, int tEnemyX, int tEnemyY)
{
	if (false == (*tIsEnemyBulletLife))
	{
		tFire = rand() % 6 + 1;
		if (1 == tFire)
		{
			//발사지점
			(*tpX) = tEnemyX;
			(*tpY) = tEnemyY;

			//발사됐는지 여부
			(*tIsEnemyBulletLife) = true;
		}
	}

	else if (true == (*tIsEnemyBulletLife))
	{
		if ((*tpY) < HEIGHT - 1)
		{
			(*tpY) = (*tpY) + 1;
		}
		else
		{
			(*tpY) = (*tpY);
			(*tIsEnemyBulletLife) = false;
		}
	}

	return tIsEnemyBulletLife;
}
void CleanPixelForEnemyBullet(char *tpPixel, int *tpX, int *tpY) // 그래픽 클리어
{
	*(tpPixel + (*tpY)*WIDTH + (*tpX)) = 0;
}
void DisplayPixelForEnemyBullet(char *tpPixel, int *tpX, int *tpY) // 그래픽 표시
{
	*(tpPixel + (*tpY)*WIDTH + (*tpX)) = '|';
}