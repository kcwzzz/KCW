// Example_DiceGame.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	cout << "�ֻ����� �����ðڽ��ϱ�??(1/0)";
	cin >> tTryRoll;

	cout << endl;

	int tDiceNumber = 0;
	
	tDiceNumber = DoRollDice();

	cout << "�ֻ����� ���Ƚ��ϴ�." << endl;
	cout << "�ֻ����� ���� " << tDiceNumber << "�� ���Խ��ϴ�." << endl << endl;
	
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
		cout << "�¸��Ͽ����ϴ�. ����� ����~~" << endl;

	}
	else
	{
		cout << "�й��Ͽ����ϴ�. ������ ����~~" << endl;
	}
	return ;
}