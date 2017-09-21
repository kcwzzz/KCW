// exam_starwars_20160617.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

#define WIDTH 80
#define HEIGHT 24

#define DIR_LEFT  0
#define DIR_RIGHT 1

class CActor
{
protected:
	int mX = 0;
	int mY = 0;

public:
	CActor();
	~CActor();
	
	void Setup();
	void MoveWithInput(char tKey);
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
	int GetX();
};

class CEnemy
{
protected:
	int mX = 0;
	int mY = 0;
	int mDir = 0;

public:
	CEnemy();
	~CEnemy();

	void Setup();
	void Move();
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
	int GetX();
};

class CActorBullet
{
protected:
	int mX = 0;
	int mY = 0;
	bool BulletLife = false;

public:
	CActorBullet();
	~CActorBullet();

	void Setup();
	void MoveWithInput(char tKey, CActor *tpActor);
	void Move();
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
};

class CEnemyBullet
{
protected:
	int mX = 0;
	int mY = 0;
	bool BulletLife = false;

public:
	CEnemyBullet();
	~CEnemyBullet();

	void Setup();
	void MoveWithInput(CEnemy *tpEnemy);
	void Move();
	void Clean(char *tpPixel);
	void Display(char *tpPixel);
};

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
	CActorBullet tActorBullet;
	CEnemyBullet tEnemyBullet;

	int tRow = 0;
	int tCol = 0;

	tActor.Setup();
	tEnemy.Setup();
	tActorBullet.Setup();
	tEnemyBullet.Setup();

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
		tActorBullet.Clean(&tPixel[0][0]);
		tEnemyBullet.Clean(&tPixel[0][0]);

		tEnemy.Move();
		tEnemyBullet.MoveWithInput(&tEnemy);
		tEnemyBullet.Move();

		tKey = 0;

		if (0 != _kbhit())
		{
			tKey = _getch();
			
			tActor.MoveWithInput(tKey);
			tActorBullet.MoveWithInput(tKey, &tActor);
			tIsEnd = GameQuitSwitch(tKey, tIsEnd);
		}

		tActorBullet.Move();

		//Display
		ClearScreen(0, 0);

		tActor.Display(&tPixel[0][0]);
		tEnemy.Display(&tPixel[0][0]);
		tActorBullet.Display(&tPixel[0][0]);
		tEnemyBullet.Display(&tPixel[0][0]);

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

CActor::CActor()
{
	mX = 0;
	mY = 0;
}
CActor::~CActor()
{

}
void CActor::Setup()
{
	mX = WIDTH / 2;
	mY = HEIGHT - 1;
}
void CActor::MoveWithInput(char tKey)
{
	//좌
	switch (tKey)
	{
	case 'Z':
	case 'z':
	{
		if (mX > 0)
		{
			mX = mX - 1;
		}

	}
	break;

	//우
	case 'X':
	case 'x':
	{
		if (mX < WIDTH - 1)
		{
			mX = mX + 1;
		}

	}
	break;
	}
}
void CActor::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void CActor::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 'A';
}
int CActor::GetX()
{
	return mX;
}

CEnemy::CEnemy()
{
	mX = 0;
	mY = 0;
}
CEnemy::~CEnemy()
{

}
void CEnemy::Setup()
{
	mX = WIDTH / 2;
	mY = 0;
	mDir = DIR_RIGHT;
}
void CEnemy::Move()
{
	if (DIR_RIGHT == mDir)
	{
		if (mX < WIDTH - 1)
		{
			mX = mX + 1;
		}
		else
		{
			mDir = DIR_LEFT;
		}
	}


	if (DIR_LEFT == mDir)
	{
		if (mX > 0)
		{
			mX = mX - 1;
		}
		else
		{
			mDir = DIR_RIGHT;
		}
	}
}
void CEnemy::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void CEnemy::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = '#';
}
int CEnemy::GetX()
{
	return mX;
}

CActorBullet::CActorBullet()
{

}
CActorBullet::~CActorBullet() 
{

}
void CActorBullet::Setup()
{
	mX = WIDTH / 2;
	mY = HEIGHT - 1 - 1;
	BulletLife = false;
}
void CActorBullet::MoveWithInput(char tKey, CActor *tpActor)
{
	switch (tKey)
	{
	case 'M':
	case 'm':
	{
		//발사지점
		mX = tpActor->GetX() ;
		mY = HEIGHT - 1 - 1;

		//발사됐는지 여부
		BulletLife = true;
	}
	break;
	}
}
void CActorBullet::Move()
{
	if (true == BulletLife)
	{
		if (mY > 0)
		{
			mY = mY - 1;
		}
	}
}
void CActorBullet::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void CActorBullet::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = '*';
}

CEnemyBullet::CEnemyBullet()
{

}
CEnemyBullet :: ~CEnemyBullet()
{

}
void CEnemyBullet::Setup()
{
	mX = WIDTH / 2;
	mY = 1;
	BulletLife = false;
}
void CEnemyBullet::MoveWithInput(CEnemy *tpEnemy)
{
	int tFire = rand() % 6 + 1;
	if (1 == tFire)
	{
		//발사지점
		mX = tpEnemy->GetX();
		mY = 1;

		//발사됐는지 여부
		BulletLife = true;
	}
}
void CEnemyBullet::Move()
{
	if (true == BulletLife)
	{
		if (mY < HEIGHT - 1)
		{
			mY = mY + 1;
		}
	}
}
void CEnemyBullet::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}
void CEnemyBullet::Display(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = '|';
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
