// Project_Warrior_is_dimension.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	// ���� ���� ����ġ
	
	cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[���� 1����]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
	cout << endl << endl;

	cout << "������ ���� �Ͻðڽ��ϱ�??? (1 / 0) :" ;
	cin >> tStrartGame;
	//1�̸� ���� ����, �� �ܸ� �Է½ÿ��� ���� ����.

	while (tStrartGame == 1)
	{
		cout << "������ �����մϴ�" << endl;
		
		int ti = 0;
		
		int tMapArray[5] = { 0, 1, 2, 3, 4 };
		//5ĭ¥�� �迭�� �� ���� �� �ʱ�ȭ
		

		/////////////////////�ֻ����� ������ �κ�////////////////////////////////

		//
		int tTryRoll = 0;

		cout << "�ֻ����� �����ðڽ��ϱ�??(1/0)";
		cin >> tTryRoll;

		cout << endl;

		int tDiceNumber = 0;

		tDiceNumber = DoRollDice();

		cout << "�ֻ����� ���Ƚ��ϴ�." << endl;
		cout << "�ֻ����� ���� " << tDiceNumber << "�� ���Խ��ϴ�." << endl << endl;

		DiceWinLose(tDiceNumber);

		/////////////////////�ֻ����� ������ �κ�////////////////////////////////

		
		/*
		for (ti = 0; ti < 5; ti++)
		{
			cout << "tMapArray[" << ti<<"] :"<< tMapArray[ti] << endl;
		}
		*/
		break;

	}
	cout << "������ �����մϴ�." << endl;

    return 0;
}

// �ֻ����� ������ �Լ�
int DoRollDice() 
{
	srand((unsigned int)time(NULL));
	//���� ���� seed 

	int tDiceNumber = 0;
	tDiceNumber = rand() % 6 + 1;
	//�ֻ��� ���� ����

	return tDiceNumber;
	//�ֻ��� ���� ����
}

// �ֻ��� ���� �޾Ƽ� �¸�/�й踦 ���ϴ� �Լ�

void DiceWinLose(int tDiceNumber)
{
	// �ֻ��� �� 1 ~ 3 : ������ �¸�
	// �ֻ��� �� 4 ~ 6 : ����� �¸�
	if (tDiceNumber >= 4)
	{
		cout << "�¸��Ͽ����ϴ�. ����� ����~~" << endl;

	}
	else
	{
		cout << "�й��Ͽ����ϴ�. ������ ����~~" << endl;
	}
	return;
}