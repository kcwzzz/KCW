// 170912_sort_ratix.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

#define RADIX 10
#define DIGIT 2

using namespace std;

struct QNode
{
	int data;
	QNode *link = NULL;
};

struct LQueueType
{
	QNode *front = NULL;
	QNode *rear = NULL;
};

LQueueType *createLinkedQueue()
{
	LQueueType *LQ = NULL;
	LQ = new LQueueType();

	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}

int isEmpty(LQueueType *LQ)
{
	if (LQ->front == NULL)
	{
		return 1;	
	}
	else
	{
		return 0;
	}
}

void enQueue(LQueueType *LQ, int item)
{
	QNode *newNode = new QNode();

	newNode->data = item;
	newNode->link = NULL;

	if (LQ->front == NULL)
	{
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else
	{
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}

}

int deQueue(LQueueType *LQ)
{
	QNode *old = LQ->front;

	int item;

	if (isEmpty(LQ))
	{
		return 0;
	}

	else
	{
		item = old->data;
		LQ->front = LQ->front->link;

		if (LQ->front == NULL)
		{
			LQ->rear = NULL;
		}

		delete old;
		return item;
	}
}

void radixSort(int a[], int n)
{
	int i;
	int bucket;
	int d;

	//1의 자리부터 시작
	int factor = 1;

	// 정렬할 자료의 기수, 즉 RADIX에 따라 10개의 버킷을 생성,
	//각각의 버킷은 체이닝으로 구성함. (링크드리스트로 구현된 큐를 생성)
	LQueueType *Q[RADIX];  // 버킷 큐의 헤드 포인터를 포인터 배열로 선언

	for (bucket = 0; bucket<RADIX; bucket++)
	{
		Q[bucket] = createLinkedQueue();
	}

	// 키값의 자릿수만큼, 즉 두 번 기수 정렬을 반복 수행
	for (d = 0; d<DIGIT; d++)
	{
		//원래 자료 전체를 순회하며 해시테이블에 넣는다.
		for (i = 0; i<n; i++)
		{
			int tHashResult = (a[i] / factor) % 10;

			enQueue(Q[tHashResult], a[i]);
		}

		//해시테이블(체이닝으로 연결된 모든 노드)을 모두 뒤져 원래 자료구조에 넣는다.
		for (bucket = 0, i = 0; bucket<RADIX; bucket++)
		{
			while (!isEmpty(Q[bucket]))
			{
				a[i++] = deQueue(Q[bucket]);
			}
		}

		//자릿수 바꿈
		factor = factor * 10;





		cout << endl << endl << d + 1 << " 단계 : ";
		for (i = 0; i<n; i++)
		{
			cout << " " << a[i];
		}

	}
}


int main()
{
	int tList[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	//int tList[8] = { 2, 8, 10, 16, 22, 30, 31, 69 };
	//int tList[8] = { 69, 31, 30, 22, 16, 10, 8, 2 };
	int size = 8;

	cout << endl << " <<<<< 기수 정렬 수행 >>>>>>";



	radixSort(tList, size);

	return 0;
}

