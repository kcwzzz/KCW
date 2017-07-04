// 170704_Lesson_Swap_Refrence.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <iostream>

void Swap(int &tA, int &tB);


using namespace std;

int main()
{
	int tAA = 777;
	int &tBB = tAA; //tAA��� ������ tBB��� �̸��� ���� �ٿ���.
	
	cout << "tAA [" << &tAA << "] : " << tAA << endl;
	cout << "tBB [" << &tBB << "] : " << tBB << endl;
	

	int tA = 3;
	int tB = 2;

	Swap(tA, tB);

	cout << "tA : " << tA << endl;
	cout << "tB : " << tB << endl;

    return 0;
}

void Swap(int &tA, int &tB)
{
	int tTemp = tA;
	tA = tB;
	tB = tTemp;
	return;
}