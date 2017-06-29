// 170629 PointerSwapExample.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void Swap(int tA, int tB);
void SwapWithPtr(int *tpA, int *tpB);

int main()
{
	int tA = 3;
	int tB = 2;

	Swap(tA, tB);

	cout << "original" << endl;
	cout << "tA: " << tA << endl;
	cout << "tB: " << tB << endl <<endl;



	SwapWithPtr(&tA, &tB);

	cout << "after SwapWithPtr" << endl;
	cout << "tA: " << tA << endl;
	cout << "tB: " << tB << endl << endl;

	return 0;
}

void Swap(int tA, int tB)
{
	int tTemp = 0;

	tTemp = tA;
	tA = tB;
	tB = tTemp;

	cout << "In function Swap " << endl;
	cout << "tA: " << tA << endl;
	cout << "tB: " << tB << endl << endl;

	return;

}

void SwapWithPtr(int *tpA, int *tpB)
{
	int tTemp = 0;

	tTemp = *tpA;
	*tpA = *tpB;
	*tpB = tTemp;

	cout << "In function Swap " << endl;
	cout << "tA: " << *tpA << endl;
	cout << "tB: " << *tpB << endl << endl;
	return;
}