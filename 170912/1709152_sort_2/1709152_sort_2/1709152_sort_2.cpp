#include "stdafx.h"
#include <iostream>
//#include <stdio.h>

using namespace std;

int gSize = 0;

//int size, i = 0;
int gStep = 0;


int gCompareCount = 0;
int gSwapCount = 0;



// 주어진 부분집합 안에서 피봇의 위치를 확정하여 분할 위치를 정하는 연산
int partition(int a[], int begin, int end)
{
	int  pivot, L, R, t;
	int temp;

	L = begin;
	R = end;

	pivot = (int)((begin + end) / 2);	// 중간에 위치한 원소를 피봇 원소로 선택
										//pivot = (int)begin;   //최악의 피봇 선택인 경우.


	cout << endl << " pivot=" << a[pivot] << "[" << ++gStep << "단계 result ] " << endl;
	while (L<R)
	{
		//L이 가리키는 원소의 데이터가 R이 가리키는 원소의 데이터보다 크거나 같을때까지 and L과 R이 만날때까지
		while ((a[L]<a[pivot]) && (L<R))
		{
			L++;

			gCompareCount++;
			cout << "compare count: " << gCompareCount << endl;
		}

		//R이 가리키는 원소의 데이터가 L이 가리키는 원소의 데이터보다 작을때까지 and L과 R이 만날때까지
		while ((a[R] >= a[pivot]) && (L<R))
		{
			R--;

			gCompareCount++;
			cout << "compare count: " << gCompareCount << endl;
		}

		if (L<R)
		{					// L과 R 원소의 자리 교환
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;


			if (L == pivot)			// L이 피봇인 경우,
			{
				pivot = R;			// 변경된 피봇의 위치(R)를 저장!
			}





			gSwapCount++;
			cout << endl << endl << "swap count: " << gSwapCount << endl;

		} // if(L<R)
	} // while(L<R)

	  // (L=R)이 된 경우,
	  // 더 이상 진행할 수 없으므로 R 원소와 피봇 원소의 자리를 교환하여 마무리
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




	return R;	// 정렬되어 확정된 피봇의 위치 반환
}

void quickSort(int a[], int begin, int end)
{
	int p;

	if (begin<end)
	{
		p = partition(a, begin, end);	// 피봇의 위치에 의해 분할 위치 결정

		quickSort(a, begin, p - 1);		// 피봇의 왼쪽 부분집합에 대해 퀵 정렬을 재귀호출
		quickSort(a, p + 1, end);		// 피봇의 오른쪽 부분집합에 대해 퀵 정렬을 재귀호출
	}
}

int main(int argc, const char * argv[])
{
	int tList[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	//int tList[8] = { 2, 8, 10, 16, 22, 30, 31, 69 };
	//int tList[8] = { 69, 31, 30, 22, 16, 10, 8, 2 };
	int size = 8;	// list 배열의 원소 개수
	gSize = size;


	cout << endl << " [ 초기 상태 ] " << endl;

	for (int i = 0; i <= size - 1; i++)
	{
		cout << " " << tList[i];
	}

	cout << endl;



	quickSort(tList, 0, size - 1);

	return 0;
}
