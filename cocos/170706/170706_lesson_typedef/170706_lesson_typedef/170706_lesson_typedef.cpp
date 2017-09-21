// 170706_lesson_typedef.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

typedef int(*tpFunc)(int, int);

int Doaddictive(int tA, int tB);
int DoSubtract(int tA, int tB);


int main()
{
	//함수를 배열에 대응해서 바로바로 접근할 수 있게 사용
	
	int tState = 0;

	tpFunc tArray[2] = { Doaddictive, DoSubtract };
	//tArray[0] = Doaddictive;
	//tArray[1] = DoSubtrat;

	//typedef 으로 tpFunc를 불러오면 int 2개를 받아서 int 형의 결과를 내는 것. 


	tState = 0;
	tArray[tState](3, 2);

	tState = 1;
	tArray[tState](3, 2);
	
	/*
	int(*tState)(int, int) = NULL;

	tState = Doaddictive;

	tState(3, 2);
    */
	return 0;
}

int Doaddictive(int tA, int tB)
{
	int tResult = 0;
	tResult = tA + tB;
	cout << "DoAddictive " << tResult << endl;
	return tResult;
}

int DoSubtract(int tA, int tB)
{
	int tResult = 0;

	tResult = tA - tB;
	cout << "DoSubtract " << tResult << endl;
	return tResult;
}