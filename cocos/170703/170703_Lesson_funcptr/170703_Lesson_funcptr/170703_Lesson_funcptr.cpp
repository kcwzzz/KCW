// 170703_Lesson_funcptr.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

float DoAddictive(int tA, int tB);
float DoSubtract(int tA, int tB);
float DoMultiply(int tA, int tB);
float DoDivide(int tA, int tB);

int main()
{

	std::cout << "program begins." << std::endl;

	int tA = 3;
	int tB = 2;

	float(*tpCalculate)(int, int) = NULL;

	int tCalcuType = 0;
	int tIsContinue = 0;
	float tResult = 0;

	while (1)
	{
		std::cout << "Select Type of Calculate(1. 덧셈, 2. 뺄셈, 3. 곱셈, 4. 나눗셈) : ";
		std::cin >> tCalcuType;

		//use 'switch' and call funtion-ptr, display 'tResult'
		
		switch (tCalcuType)
		{
			{
		case 1:
			tpCalculate = DoAddictive;
			break;
			}
		case 2:
		{
			tpCalculate = DoSubtract;
			break;
		}
		case 3:
		{
			tpCalculate = DoMultiply;
			break;
		}
		case 4:
		{
			tpCalculate = DoDivide;
			break;

		}
		}

		//tpCalulate는 함수 형식 맞춰서 넣어줘야한다.
		cout << tpCalculate(tA, tB) << endl;
		



		std::cout << "Quit?(9) ";
		std::cin >> tIsContinue;
		if (9 == tIsContinue)
		{
			break;
		}
	}


	std::cout << "program ends." << std::endl;

	return 0;
}

float DoAddictive(int tA, int tB)
{
	return tA + tB;
}
float DoSubtract(int tA, int tB)
{
	return tA - tB;
}

float DoMultiply(int tA, int tB)
{
	return tA*tB;
}
float DoDivide(int tA, int tB)
{
	return (float)tA / (float)tB;
}
