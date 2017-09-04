// SequentialSearch.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void SequentialSearch1(int a[], int n, int key)
{
	int i = 0;
	cout << endl << key << " �� �˻��϶�! ->> ";

	while (i<n && a[i] != key)
	{
		i++;
	}

	if (i < n)
	{
		cout << i + 1 << "��°�� �˻� ����! " << endl << endl;

	}
	else
	{
		cout << i + 1 << "��°�� �˻� ����! " << endl << endl;
	}
}



void SequentialSearch2(int a[], int n, int key)
{
	int i = 0;
	cout << endl << key << " �� �˻��϶�! ->> ";

	while (a[i] < key)
	{
		i++;
	}

	if (a[i] == key)
	{
		cout << i + 1 << "��°�� �˻� ����! " << endl << endl;

	}
	else
	{
		cout << i + 1 << "��°�� �˻� ����! " << endl << endl;
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
