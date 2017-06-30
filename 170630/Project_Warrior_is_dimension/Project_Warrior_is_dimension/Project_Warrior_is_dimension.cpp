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

int DoRollDice();
void DiceWinLose(int tDiceNumber);



void DoDice(int tHero, int tMonster);
//void DoRSP(

int main()

{
	int tStrartGame = 0; 
	// 게임 시작 스위치
	
	cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[용사는 1차원]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
	cout << endl << endl;

	cout << "게임을 시작 하시겠습니까??? (1 / 0) :" ;
	cin >> tStrartGame;
	//1이면 게임 진행, 그 외를 입력시에는 게임 종료.

	while (tStrartGame == 1)
	{
		cout << "게임을 시작합니다" << endl;
		
		int ti = 0;
		
		int tMapArray[5] = { 0, 1, 2, 3, 4 };
		//5칸짜리 배열로 맵 선언 및 초기화
		

		/////////////////////주사위를 돌리는 부분////////////////////////////////

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

		
		/*
		for (ti = 0; ti < 5; ti++)
		{
			cout << "tMapArray[" << ti<<"] :"<< tMapArray[ti] << endl;
		}
		*/
		break;

	}
	cout << "게임을 종료합니다." << endl;

    return 0;
}

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