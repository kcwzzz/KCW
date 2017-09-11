// 170911_algorithmSort_selection.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int gCompareCount = 0;
int gSwapCount = 0;

void SelectionSort(int a[], int size)
{

	int i = 0, j = 0, t = 0, min = 0;
	int temp = 0;


	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}

		}

		if (min != i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}

		cout << endl << i + 1 << "단계 : ";
		for (t = 0; t < size; t++)
		{
			cout << "   " << a[t];
		}

	}


}


int main()
{
	int tList[8] = { 69,10,30,2,16,8,31,22 };
	int tSize = 8;

	cout << endl << "정렬할 원소 : ";

	int ti = 0;
	for (ti = 0; ti < tSize; ti++)
	{
		cout << tList[ti] << "  ";
	}

	cout << endl << endl << " <<<<<<<<<<<<<<선택 정렬 수행 >>>>>>>>>>>>>" << endl;


	SelectionSort(tList, tSize);

    return 0;
}

