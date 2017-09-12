#include "stdafx.h"
#include <iostream>
//#include <stdio.h>

using namespace std;

int gSize = 0;

//int size, i = 0;
int gStep = 0;


int gCompareCount = 0;
int gSwapCount = 0;



// �־��� �κ����� �ȿ��� �Ǻ��� ��ġ�� Ȯ���Ͽ� ���� ��ġ�� ���ϴ� ����
int partition(int a[], int begin, int end)
{
	int  pivot, L, R, t;
	int temp;

	L = begin;
	R = end;

	pivot = (int)((begin + end) / 2);	// �߰��� ��ġ�� ���Ҹ� �Ǻ� ���ҷ� ����
										//pivot = (int)begin;   //�־��� �Ǻ� ������ ���.


	cout << endl << " pivot=" << a[pivot] << "[" << ++gStep << "�ܰ� result ] " << endl;
	while (L<R)
	{
		//L�� ����Ű�� ������ �����Ͱ� R�� ����Ű�� ������ �����ͺ��� ũ�ų� ���������� and L�� R�� ����������
		while ((a[L]<a[pivot]) && (L<R))
		{
			L++;

			gCompareCount++;
			cout << "compare count: " << gCompareCount << endl;
		}

		//R�� ����Ű�� ������ �����Ͱ� L�� ����Ű�� ������ �����ͺ��� ���������� and L�� R�� ����������
		while ((a[R] >= a[pivot]) && (L<R))
		{
			R--;

			gCompareCount++;
			cout << "compare count: " << gCompareCount << endl;
		}

		if (L<R)
		{					// L�� R ������ �ڸ� ��ȯ
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;


			if (L == pivot)			// L�� �Ǻ��� ���,
			{
				pivot = R;			// ����� �Ǻ��� ��ġ(R)�� ����!
			}





			gSwapCount++;
			cout << endl << endl << "swap count: " << gSwapCount << endl;

		} // if(L<R)
	} // while(L<R)

	  // (L=R)�� �� ���,
	  // �� �̻� ������ �� �����Ƿ� R ���ҿ� �Ǻ� ������ �ڸ��� ��ȯ�Ͽ� ������
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;

	gSwapCount++;
	cout << endl << endl << "swap count: " << gSwapCount << endl;





	for (t = 0; t<gSize; t++)
	{
		cout << " " << a[t];
	}

	cout << endl;




	return R;	// ���ĵǾ� Ȯ���� �Ǻ��� ��ġ ��ȯ
}

void quickSort(int a[], int begin, int end)
{
	int p;

	if (begin<end)
	{
		p = partition(a, begin, end);	// �Ǻ��� ��ġ�� ���� ���� ��ġ ����

		quickSort(a, begin, p - 1);		// �Ǻ��� ���� �κ����տ� ���� �� ������ ���ȣ��
		quickSort(a, p + 1, end);		// �Ǻ��� ������ �κ����տ� ���� �� ������ ���ȣ��
	}
}

int main(int argc, const char * argv[])
{
	int tList[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	//int tList[8] = { 2, 8, 10, 16, 22, 30, 31, 69 };
	//int tList[8] = { 69, 31, 30, 22, 16, 10, 8, 2 };
	int size = 8;	// list �迭�� ���� ����
	gSize = size;


	cout << endl << " [ �ʱ� ���� ] " << endl;

	for (int i = 0; i <= size - 1; i++)
	{
		cout << " " << tList[i];
	}

	cout << endl;



	quickSort(tList, 0, size - 1);

	return 0;
}
