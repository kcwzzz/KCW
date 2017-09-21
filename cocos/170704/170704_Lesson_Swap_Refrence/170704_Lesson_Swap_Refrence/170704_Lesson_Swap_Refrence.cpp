// 170704_Lesson_Swap_Refrence.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

void Swap(int &tA, int &tB);


using namespace std;

int main()
{
	int tAA = 777;
	int &tBB = tAA; //tAA라는 변수에 tBB라는 이름을 새로 붙였다.
	
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