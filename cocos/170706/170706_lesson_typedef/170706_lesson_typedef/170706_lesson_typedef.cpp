// 170706_lesson_typedef.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	//�Լ��� �迭�� �����ؼ� �ٷιٷ� ������ �� �ְ� ���
	
	int tState = 0;

	tpFunc tArray[2] = { Doaddictive, DoSubtract };
	//tArray[0] = Doaddictive;
	//tArray[1] = DoSubtrat;

	//typedef ���� tpFunc�� �ҷ����� int 2���� �޾Ƽ� int ���� ����� ���� ��. 


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