

#include "stdafx.h"
#include <iostream>

//#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define TABLE_SIZE 10

struct SNode
{
	int key;

	SNode *mpNext = NULL;

};

//키를 해쉬로 변환
int hash_func(int key)
{
	int h = -1;

	h = key % TABLE_SIZE;

	return h;
}
//해쉬를 참고하여 해시테이블의 해당 버킷(으로 가서 슬롯들을 순차검색하여 원하는 원소)으로 찾아감. 해당 버킷은 링크드리스트로 충돌을 처리하도록 만들어짐.
SNode *hsc_search(int key, SNode a[], int *np)
{
	SNode *t = NULL;


	t = a[hash_func(key)].mpNext;

	while (t != NULL && t->key != key)
	{
		t = t->mpNext;
	}


	return t;
}
//해쉬를 참고하여 해시테이블의 해당 버킷으로 가서 링크드리스트의 선두에 해당 원소를 추가함.
SNode *hsc_insert(int key, SNode a[], int *tpTotalElementCount)
{
	int tHashIndex = -1;

	SNode *t = NULL;

	t = new SNode();

	tHashIndex = hash_func(key);

	t->mpNext = a[tHashIndex].mpNext;
	t->key = key;
	a[tHashIndex].mpNext = t;

	(*tpTotalElementCount)++;

	return t;
}

SNode *hsc_delete(int key, SNode a[], int *tpTotalElementCount)
{
	SNode *p = NULL;
	SNode *t = NULL;

	if (*tpTotalElementCount > 0)
	{
		p = &a[hash_func(key)];


		t = p->mpNext;

		while (t != NULL && t->key != key)
		{
			p = t;
			t = t->mpNext;
		}
		if (t == NULL)
		{
			return NULL;
		}

		p->mpNext = t->mpNext;

		delete t;

		(*tpTotalElementCount)--;

		return p;
	}
	return NULL;
}

int hsc_init(SNode a[], int *tpTotalElementCount, int N)
{
	int i = 0;

	for (i = 0; i < N; i++)
	{
		a[i].mpNext = NULL;
	}

	*tpTotalElementCount = 0;

	return 1;
}

int hsc_deleteall(SNode a[], int *tpTotalElementCount, int N)
{
	SNode *t = NULL, *p = NULL;

	int i = 0;

	for (i = 0; i < N; i++)
	{
		t = a[i].mpNext;

		while (t != NULL)
		{
			p = t;
			t = t->mpNext;

			delete p;
		}
	}

	(*tpTotalElementCount) = 0;

	return 1;
}

int hsc_create(SNode **a, int *tpTotalElementCount, int N)
{
	*a = new SNode[N];

	hsc_init(*a, tpTotalElementCount, N);

	return 1;
}

int hsc_list(SNode a[], int N)
{
	int i = 0;

	SNode *t = NULL;

	for (i = 0; i < N; i++)
	{
		cout << endl << i << "Bucket :";

		t = a[i].mpNext;

		while (t != NULL)
		{
			cout << " -> " << t->key;
			t = t->mpNext;
		}
	}

	cout << endl;

	return 1;
}

void interpret(SNode a[], int *tpTotalElementCount, int N)
{
	char command[2];
	char key[2];

	while (command[0] != 'q')
	{

		cout << endl << "Input command ->";

		cin >> command;


		switch (command[0])
		{
		case 'i':
		case 'I':
		{

			cin >> key;

			hsc_insert(key[0], a, tpTotalElementCount);
			printf("\n   Successful insert.");
		}
		break;
		case 'd':
		case 'D':
		{

			cin >> key;

			if (hsc_delete(key[0], a, tpTotalElementCount) == NULL)
			{
				printf("\n   Error : Table Empty or Can't find");
			}
			else
			{
				printf("\n   Successful delete.");
			}
		}
		break;
		case 's':
		case 'S':
		{

			cin >> key;

			SNode *tpTemp = NULL;
			tpTemp = hsc_search(key[0], a, tpTotalElementCount);

			if (tpTemp == NULL)
			{
				printf("\n   Error : Can'f find that key");
			}
			else
			{
				printf("\n   Ok! find in %d th position", tpTemp->key);
			}
		}
		break;
		case 'l':
		case 'L':
		{
			hsc_list(a, N);
		}
		break;
		}


		cout << "  n = " << *tpTotalElementCount;
	}
}

int main(int argc, const char * argv[])
{
	SNode *tpTable = NULL;

	int tTotalElementCount = 0;


	hsc_create(&tpTable, &tTotalElementCount, TABLE_SIZE);

	interpret(tpTable, &tTotalElementCount, TABLE_SIZE);

	hsc_deleteall(tpTable, &tTotalElementCount, TABLE_SIZE);



	delete tpTable;

	return 0;
}

