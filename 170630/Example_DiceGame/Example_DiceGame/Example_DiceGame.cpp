// Example_DiceGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#include <stdlib.h>
#include <time.h>

using namespace std;

int DoRollDice();
void DiceWinLose(int tDiceNumber);


int main()
{
//	srand((unsigned int)time(NULL));
	int tTryRoll = 0;

	cout << "주사위를 굴리시겠습니까??(1/0)";
	cin >> tTryRoll;

	cout << endl;

	int tDiceNumber = 0;
	
	tDiceNumber = DoRollDice();

	cout << "주사위를 굴렸습니다." << endl;
	cout << "주사위의 값은 " << tDiceNumber << "가 나왔습니다." << endl << endl;
	
	DiceWinLose(tDiceNumber);


    return 0;
}

int DoRollDice()
{
	srand((unsigned int)time(NULL));

	int tDiceNumber = 0;
	tDiceNumber = rand() % 6 + 1;
	
	return tDiceNumber;
}

void DiceWinLose(int tDiceNumber)
{

	if (tDiceNumber >= 4)
	{
		cout << "승리하였습니다. 용사의 공격~~" << endl;

	}
	else
	{
		cout << "패배하였습니다. 몬스터의 공격~~" << endl;
	}
	return ;
}