// IndexSequenceSearch.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define INDEX_SIZE 3

struct STable
{
	int index;
	int key;
};

STable indexTable[INDEX_SIZE];

void SequntailSearch(int a[], int begin, int end, int key)
{
	int i = begin;
	cout << endl << key << " �� �˻��϶�. ->>";

	while (i<end && a[i]<key)
	{
		i++;
	}

	if (a[i] == key)
	{
		cout << (i - begin) + 1 << "��°�� �˻� ����!" << endl << endl;
	}
	else
	{
		cout << (i - begin) + 1 << "��°�� �˻� ����" << endl << endl;
	}

}

void makeIndexTable(int a[], int size)
{
	int i, n;
	n = size / INDEX_SIZE;

	if (size % INDEX_SIZE > 0)
	{
		n = n + 1;
	}

	for (i = 1; i < INDEX_SIZE; i++)
	{
		indexTable[i].index = i*n;
		indexTable[i].key = a[i*n];
	}
}

void indexSearch(int a[], int n, int key)
{
	int i = 0;
	int begin = 0;
	int end = 0;

	if (key < a[0] || key > a[n - 1])
	{
		cout << endl << "ã�� Ű�� �����ϴ�. �˻� ���� " << endl;
	}

	for (i = 0; i < INDEX_SIZE; i++)
	{
		if ((indexTable[i].key <= key) && (indexTable[i + 1].key > key))
		{
			begin = indexTable[i].index;
			end = indexTable[i + 1].index;
			break;
		}
	}

	if (i == INDEX_SIZE)
	{
		begin = indexTable[i - 1].index;
		end = n;
	}

	SequntailSearch(a, begin, end, key);


}

int main()
{
	int a[] = { 1,2,8,9,11,19,29 };
	int n = 7;

	cout << endl << "\t << ���� ���� �˻� >> " << endl;

	makeIndexTable(a, n);
	indexSearch(a, n, 9);
	indexSearch(a, n, 6);


    return 0;
}

