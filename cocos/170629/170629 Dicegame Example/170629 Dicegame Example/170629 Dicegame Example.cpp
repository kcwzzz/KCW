// 170629 Dicegame Example.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	int tDiceType = 0; //"�ֻ��� Ÿ��"
	int tContinueGame = 1; //"


	cout << "-------------------Welcome to the DiceGame--------------------------------"<<endl;

	cout << "Select Your DiceType :" ;
	cin >> tDiceType;

	while (tContinueGame)
	{
		cout << "Are you continue Dicegame(1/0)" ;
		cin >> tContinueGame;

		if (tContinueGame=0)
		{
			cout << "End Game" << endl;
			break;
		}

	}

    return 0;
}

