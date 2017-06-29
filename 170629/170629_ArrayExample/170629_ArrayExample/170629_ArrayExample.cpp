// 170629_ArrayExample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

void DoChangeElementWith(int tArray[], int tIndex, int tValue);
void DoChangeElementWithPtr(int *tpArray, int tIndex, int tValue);

int main()
{
	// 배열의 이름은 '배열의 시작 주소값'이다.
	int tArray[5] = { 0,0,0,0,0 };

	cout << "Before Array Value" << endl;

	cout << "tArray[0] : " << tArray[0] << endl;
	cout << "tArray[1] : " << tArray[1] << endl;
	cout << "tArray[2] : " << tArray[2] << endl;
	cout << "tArray[3] : " << tArray[3] << endl;
	cout << "tArray[4] : " << tArray[4] << endl;

	cout << endl << endl;


	cout << "After Array Value" << endl;

	tArray[0] = 4;
	tArray[1] = 0;
	tArray[2] = 1;
	tArray[3] = 2;
	tArray[4] = 3;

	for (int tA = 0; tA < 5; tA++)
	{
		cout << "tArray[" << tA << "] : " << tArray[tA] << endl;
	}
	cout << endl << endl;


	cout << "After Fuction Change Array Value" << endl;

	DoChangeElementWith(tArray, 0, 777);

	for (int tA = 0; tA < 5; tA++)
	{
		cout << "tArray[" << tA << "] : " << tArray[tA] << endl;
	}
	cout << endl << endl;

	cout << "After Pointer Change Array Value" << endl;

	DoChangeElementWithPtr(tArray, 3, 999);

	for (int tA = 0; tA < 5; tA++)
	{
		cout << "tArray[" << tA << "] : " << tArray[tA] << endl;
	}
	cout << endl << endl;

	/*
	for (int tA = 0; tA < 5; tA++)
	{
		cout << "tArray[" << tA << "] : " << &tArray[tA] << endl;
	}
	cout << endl << endl;
	*/
	return 0;
}

void DoChangeElementWith(int tArray[], int tIndex, int tValue)
{
	tArray[tIndex] = tValue;
	return;
}
void DoChangeElementWithPtr(int *tpArray, int tIndex, int tValue)
{
	*(tpArray + tIndex) = tValue;
	return;
}