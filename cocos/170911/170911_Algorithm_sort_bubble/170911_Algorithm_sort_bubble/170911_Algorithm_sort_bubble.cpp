// 170911_Algorithm_sort_bubble.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int gCompareCount = 0;
int gSwapCount = 0;

void bubbleSort(int a[], int size)
{
	int i = 0, j = 0, t = 0;
	int temp = 0;

	for (i = size - 1; i > 0; i--)
	{
		cout << endl << size - i << " �ܰ� >> ";
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j+1] = temp;

			}

			cout << endl << "\t";

			for (t = 0; t < size; t++)
			{
				cout << a[t] << "   ";
			}

		}


	}

}


int main()
{
	int tList[8] = { 69,10,30,2,16,8,31,22 };

	int tSize = 8;

	cout << endl << " ������ ���� : "; 
	int ti = 0;
	for (ti = 0; ti << tSize; ti++)
	{
		cout << tList[ti] << "  ";
	}

	cout << endl << "<<<<<<<<<< ���� ���� ���� >>>>>>>>>>>>";

	bubbleSort(tList, tSize);


    return 0;
}

