// SequentialSearch.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void SequentialSearch1(int a[], int n, int key)
{
	int i = 0;
	cout << endl << key << " 를 검색하라! ->> ";

	while (i<n && a[i] != key)
	{
		i++;
	}

	if (i < n)
	{
		cout << i + 1 << "번째에 검색 성공! " << endl << endl;

	}
	else
	{
		cout << i + 1 << "번째에 검색 실패! " << endl << endl;
	}
}



void SequentialSearch2(int a[], int n, int key)
{
	int i = 0;
	cout << endl << key << " 를 검색하라! ->> ";

	while (a[i] < key)
	{
		i++;
	}

	if (a[i] == key)
	{
		cout << i + 1 << "번째에 검색 성공! " << endl << endl;

	}
	else
	{
		cout << i + 1 << "번째에 검색 실패! " << endl << endl;
	}
}


int main()
{
	int a[] = { 8,30,1,9,11,19,2 };
	int n = 7;

	SequentialSearch1(a, n, 9);
	SequentialSearch1(a, n, 6);


	int b[] = { 1,2,8,9,11,19,29 };
	n = 7;

	SequentialSearch2(b, n, 9);
	SequentialSearch2(b, n, 6);
	
	return 0;
}
