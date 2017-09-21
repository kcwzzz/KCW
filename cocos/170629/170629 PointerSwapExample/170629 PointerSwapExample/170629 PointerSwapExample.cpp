// 170629 PointerSwapExample.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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