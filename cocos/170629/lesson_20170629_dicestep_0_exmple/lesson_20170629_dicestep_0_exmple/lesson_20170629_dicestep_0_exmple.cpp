// exam_dice.cpp : Defines the entry point for the console application.
//

//사용자가 정의한 헤더파일은 큰따옴표로 감싼다.

/*
1. 게임 진행 과정
 - 몇 면 주사위인지 선택한다.
 - 플레이 할 것인지를 묻고 계속진행 혹은 게임 종료(루프)
 - 주사위를 굴린다. (난수 생성 함수)
 - 주사위의 중간 값보다 크면 승리, 작으면 패배(승/패 결정 함수)


 2. 필요 변수의 갯수
 - 주사위 면의 갯수(tDiceType)
 - 돌려서 나온 주사위의 수(tDiceNumber)
 - 계속 할지에 대한 스위치 값
*/


//표준헤더파일들은 꺽쇠로 감싼다.
#include "stdafx.h"
#include <iostream>


#include <time.h>
#include <stdlib.h>

//함수선언
int DoRollDice(int tFrom, int tTo);

//void: '타입이 없다' 라는 뜻의 타입
void DecideWinLoseWith(int tDiceNumber,int tDiceType);

int main()
{
	srand((unsigned int)time(NULL));

	int tDiceType = 0;

	int tDiceNumber = 0;
	int tIsContinue = 0;

	std::cout << "Dice Game" << std::endl;
	std::cout << "Please, input your dice type: ";
	std::cin >> tDiceType;


	//game loop
	while (1)
	{
		std::cout << "Do you roll dice?(1/0) " << std::endl;
		std::cin >> tIsContinue;

		if (0 == tIsContinue)
		{
			break;
		}
		tDiceNumber = DoRollDice(1, tDiceType);
		//주사위가 몇의 숫자까지 나오는가

		std::cout << "your dice number: " << tDiceNumber << std::endl;
		//주사위가 몇이 나왔는지 보여준다.

		DecideWinLoseWith(tDiceNumber, tDiceType);
		//이겼나 졌나


		if (0 == tIsContinue)
		{
			break;
		}
	}

	std::cout << "game ends." << std::endl;


	return 0;
}

int DoRollDice(int tFrom, int tTo)
{
	srand((unsigned int)time(NULL));

	int tDiceNumber = 0;

	tDiceNumber = rand()%tTo+1;
	
	return tDiceNumber;

		//rand함수를 사용하여 주사위 구현.
}
void DecideWinLoseWith(int tDiceNumber, int tDiceType)
{
	if (tDiceNumber <= tDiceType/2)
	{
		std::cout << "You Lose" << std::endl;

	}
	else
	{
		std::cout << "You Win" << std::endl;

	}
	return ;
	//use switch
	//3이하 lose, 4이상 win
}