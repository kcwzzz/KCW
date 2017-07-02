// Project_Warrior_is_dimension.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Character
{
	int SAttackPoint = 0;
	int SHealthPoint = 0;

};

//주사위 관련 함수
int DoRollDice();
void DiceWinLose(int tDiceNumber);

//가위바위보 관련 함수
int DoThinkAlphago(int tFrom, int tTo);
int DoCheckInput();
char IsContinue();
void DoCompareBetween(int tPlayerValue, int tAlphagoValue);

int main()

{
	int tStrartGame = 0; 
	// 게임 시작 스위치
	
	cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[용사는 1차원]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
	cout << endl << endl;

	cout << "게임을 시작 하시겠습니까??? (1 / 0) :" ; // 이것도 y n 으로 시작할 수 있도록 할 거임.
	cin >> tStrartGame;
	//1이면 게임 진행, 그 외를 입력시에는 게임 종료.

	while (tStrartGame == 1)
	{
		cout << "게임을 시작합니다" << endl;
		
		int tMapArray[5] = { 0, 1, 2, 3, 4 };
		//5칸짜리 배열로 맵 선언 및 초기화
		

		int tTemp = 0;
		cout << "테스트할 기능을 입력해주세요.(1. 주사위, 2. 가위바위보)" << endl;
		cin >> tTemp;

		
		/////////////////////주사위를 돌리는 기능////////////////////////////////
		if (tTemp = 1)// 이 부분은 기능 테스트 용으로 게임이 완료되면 삭제할 예정
		{
			
			//
			int tTryRoll = 0;

			cout << "주사위를 굴리시겠습니까??(1/0)";
			cin >> tTryRoll;

			cout << endl;

			int tDiceNumber = 0;

			tDiceNumber = DoRollDice();

			cout << "주사위를 굴렸습니다." << endl;
			cout << "주사위의 값은 " << tDiceNumber << "가 나왔습니다." << endl << endl;

			DiceWinLose(tDiceNumber);

			/////////////////////주사위를 돌리는 부분////////////////////////////////
			break;

		}

		/////////////////////가위바위보 기능////////////////////////////////
		else if (tTemp = 2)
		{
			//srand((unsigned int)time(NULL));

			int tPlayerValue = 0;
			int tAlphagoValue = 0;
			char tIsContinue = 'y';

			while ('y' == tIsContinue)
			{
				tAlphagoValue = DoThinkAlphago(0, 3);
				tPlayerValue = DoCheckInput();

				DoCompareBetween(tPlayerValue, tAlphagoValue);

				tIsContinue = IsContinue();
			}

		}

	}
	cout << "게임을 종료합니다." << endl;

    return 0;
}

/////주사위 관련 함수 목록/////////////////////////////////////////////////
// 주사위를 돌리는 함수
int DoRollDice() 
{
	srand((unsigned int)time(NULL));
	//변수 생성 seed 

	int tDiceNumber = 0;
	tDiceNumber = rand() % 6 + 1;
	//주사위 값을 생성

	return tDiceNumber;
	//주사위 값을 리턴
}

// 주사위 값을 받아서 승리/패배를 정하는 함수
void DiceWinLose(int tDiceNumber)
{
	// 주사위 눈 1 ~ 3 : 몬스터의 승리
	// 주사위 눈 4 ~ 6 : 용사의 승리
	if (tDiceNumber >= 4)
	{
		cout << "승리하였습니다. 용사의 공격~~" << endl;

	}
	else
	{
		cout << "패배하였습니다. 몬스터의 공격~~" << endl;
	}
	return;
}


/////가위바위보 관련 함수 목록/////////////////////////////////////////////
// 보스의 가위바위보 값을 결정하는 함수
int DoThinkAlphago(int tFrom, int tTo)
{
	int tEnermy = 0;
	srand((unsigned int)time(NULL));

	tEnermy = rand() % tTo + tFrom;

	return tEnermy;
}

// 입력한 값이 잘못 되었는지 결정하는 함수
int DoCheckInput()
{
	int tResult = -1;
	while (1)
	{
		cout << "Select Scissors(0) or Rock(1) or Paper(2)!!" << endl;
		cin >> tResult;

		if (tResult >= 0 && tResult < 3)
		{
			break;
		}
		else
		{
			cout << "입력이 잘못되었습니다. 0,1,2 중에서 입력해주세요." << endl << endl;;

		}
	}
	return tResult;

}

// 계속할지 물어보는 함수
char IsContinue()
{
	char tInput = 0;
	while (1)
	{
		cout << "게임을 계속 진행 하시겠습니까?(y/n)" << endl;
		cin >> tInput;

		if ('y' == tInput || 'n' == tInput)
		{
			break;
		}
		cout << "입력이 잘못되었습니다. y 혹은 n츠로 입력해주세요." << endl;

	}

	return tInput;
}

// 가위바위보 값을 비교하는 함수
void DoCompareBetween(int tPlayerValue, int tAlphagoValue)
{
	if (tPlayerValue = 0)
	{
		switch (tAlphagoValue)
		{
		case 0:
		{
			cout << "용사 : 가위" << endl;
			cout << "보스 : 가위" << endl;
			cout << "무승부입니다." << endl;
			break;
		}

		case 1:
		{
			cout << "용사 : 가위" << endl;
			cout << "보스 : 바위" << endl;
			cout << "용사의 패배." << endl;
			break;
		}

		case 2:
		{
			cout << "용사 : 가위" << endl;
			cout << "보스 : 보" << endl;
			cout << "용사의 승리." << endl;
			break;
		}
		}
	}

	else if (tPlayerValue = 1)
	{
		switch (tAlphagoValue)
		{
		case 0:
		{
			cout << "용사 : 바위" << endl;
			cout << "보스 : 가위" << endl;
			cout << "용사의 승리." << endl;
			break;
		}

		case 1:
		{
			cout << "용사 : 바위" << endl;
			cout << "보스 : 바위" << endl;
			cout << "무승부입니다." << endl;
			break;
		}

		case 2:
		{
			cout << "용사 : 바위" << endl;
			cout << "보스 : 보" << endl;
			cout << "용사의 패배." << endl;
			break;
		}
		}

	}

	else
	{
		switch (tAlphagoValue)
		{
		case 0:
		{
			cout << "용사 : 보" << endl;
			cout << "보스 : 가위" << endl;
			cout << "용사의 패배." << endl;
			break;
		}

		case 1:
		{
			cout << "용사 : 보" << endl;
			cout << "보스 : 바위" << endl;
			cout << "용사의 승리." << endl;
			break;
		}

		case 2:
		{
			cout << "용사 : 보" << endl;
			cout << "보스 : 보" << endl;
			cout << "무승부입니다." << endl;
			break;
		}
		}
	}

	return;
}