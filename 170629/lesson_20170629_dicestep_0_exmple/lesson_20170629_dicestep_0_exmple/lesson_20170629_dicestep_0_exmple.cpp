// exam_dice.cpp : Defines the entry point for the console application.
//

//����ڰ� ������ ��������� ū����ǥ�� ���Ѵ�.

/*
1. ���� ���� ����
 - �� �� �ֻ������� �����Ѵ�.
 - �÷��� �� �������� ���� ������� Ȥ�� ���� ����(����)
 - �ֻ����� ������. (���� ���� �Լ�)
 - �ֻ����� �߰� ������ ũ�� �¸�, ������ �й�(��/�� ���� �Լ�)


 2. �ʿ� ������ ����
 - �ֻ��� ���� ����(tDiceType)
 - ������ ���� �ֻ����� ��(tDiceNumber)
 - ��� ������ ���� ����ġ ��
*/


//ǥ��������ϵ��� ����� ���Ѵ�.
#include "stdafx.h"
#include <iostream>


#include <time.h>
#include <stdlib.h>

//�Լ�����
int DoRollDice(int tFrom, int tTo);

//void: 'Ÿ���� ����' ��� ���� Ÿ��
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
		//�ֻ����� ���� ���ڱ��� �����°�

		std::cout << "your dice number: " << tDiceNumber << std::endl;
		//�ֻ����� ���� ���Դ��� �����ش�.

		DecideWinLoseWith(tDiceNumber, tDiceType);
		//�̰峪 ����


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

		//rand�Լ��� ����Ͽ� �ֻ��� ����.
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
	//3���� lose, 4�̻� win
}