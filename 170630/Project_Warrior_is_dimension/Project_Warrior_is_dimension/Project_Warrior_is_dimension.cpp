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

//�ֻ��� ���� �Լ�
int DoRollDice();
void DiceWinLose(int tDiceNumber);

//���������� ���� �Լ�
int DoThinkAlphago(int tFrom, int tTo);
int DoCheckInput();
char IsContinue();
void DoCompareBetween(int tPlayerValue, int tAlphagoValue);

int main()

{
	int tStrartGame = 0; 
	// ���� ���� ����ġ
	
	cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[���� 1����]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
	cout << endl << endl;

	cout << "������ ���� �Ͻðڽ��ϱ�??? (1 / 0) :" ; // �̰͵� y n ���� ������ �� �ֵ��� �� ����.
	cin >> tStrartGame;
	//1�̸� ���� ����, �� �ܸ� �Է½ÿ��� ���� ����.

	while (tStrartGame == 1)
	{
		cout << "������ �����մϴ�" << endl;
		
		int tMapArray[5] = { 0, 1, 2, 3, 4 };
		//5ĭ¥�� �迭�� �� ���� �� �ʱ�ȭ
		

		int tTemp = 0;
		cout << "�׽�Ʈ�� ����� �Է����ּ���.(1. �ֻ���, 2. ����������)" << endl;
		cin >> tTemp;

		
		/////////////////////�ֻ����� ������ ���////////////////////////////////
		if (tTemp = 1)// �� �κ��� ��� �׽�Ʈ ������ ������ �Ϸ�Ǹ� ������ ����
		{
			
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
			break;

		}

		/////////////////////���������� ���////////////////////////////////
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
	cout << "������ �����մϴ�." << endl;

    return 0;
}

/////�ֻ��� ���� �Լ� ���/////////////////////////////////////////////////
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


/////���������� ���� �Լ� ���/////////////////////////////////////////////
// ������ ���������� ���� �����ϴ� �Լ�
int DoThinkAlphago(int tFrom, int tTo)
{
	int tEnermy = 0;
	srand((unsigned int)time(NULL));

	tEnermy = rand() % tTo + tFrom;

	return tEnermy;
}

// �Է��� ���� �߸� �Ǿ����� �����ϴ� �Լ�
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
			cout << "�Է��� �߸��Ǿ����ϴ�. 0,1,2 �߿��� �Է����ּ���." << endl << endl;;

		}
	}
	return tResult;

}

// ������� ����� �Լ�
char IsContinue()
{
	char tInput = 0;
	while (1)
	{
		cout << "������ ��� ���� �Ͻðڽ��ϱ�?(y/n)" << endl;
		cin >> tInput;

		if ('y' == tInput || 'n' == tInput)
		{
			break;
		}
		cout << "�Է��� �߸��Ǿ����ϴ�. y Ȥ�� n���� �Է����ּ���." << endl;

	}

	return tInput;
}

// ���������� ���� ���ϴ� �Լ�
void DoCompareBetween(int tPlayerValue, int tAlphagoValue)
{
	if (tPlayerValue = 0)
	{
		switch (tAlphagoValue)
		{
		case 0:
		{
			cout << "��� : ����" << endl;
			cout << "���� : ����" << endl;
			cout << "���º��Դϴ�." << endl;
			break;
		}

		case 1:
		{
			cout << "��� : ����" << endl;
			cout << "���� : ����" << endl;
			cout << "����� �й�." << endl;
			break;
		}

		case 2:
		{
			cout << "��� : ����" << endl;
			cout << "���� : ��" << endl;
			cout << "����� �¸�." << endl;
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
			cout << "��� : ����" << endl;
			cout << "���� : ����" << endl;
			cout << "����� �¸�." << endl;
			break;
		}

		case 1:
		{
			cout << "��� : ����" << endl;
			cout << "���� : ����" << endl;
			cout << "���º��Դϴ�." << endl;
			break;
		}

		case 2:
		{
			cout << "��� : ����" << endl;
			cout << "���� : ��" << endl;
			cout << "����� �й�." << endl;
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
			cout << "��� : ��" << endl;
			cout << "���� : ����" << endl;
			cout << "����� �й�." << endl;
			break;
		}

		case 1:
		{
			cout << "��� : ��" << endl;
			cout << "���� : ����" << endl;
			cout << "����� �¸�." << endl;
			break;
		}

		case 2:
		{
			cout << "��� : ��" << endl;
			cout << "���� : ��" << endl;
			cout << "���º��Դϴ�." << endl;
			break;
		}
		}
	}

	return;
}