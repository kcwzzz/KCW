// 170912_sort_ratix.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	//1�� �ڸ����� ����
	int factor = 1;

	// ������ �ڷ��� ���, �� RADIX�� ���� 10���� ��Ŷ�� ����,
	//������ ��Ŷ�� ü�̴����� ������. (��ũ�帮��Ʈ�� ������ ť�� ����)
	LQueueType *Q[RADIX];  // ��Ŷ ť�� ��� �����͸� ������ �迭�� ����

	for (bucket = 0; bucket<RADIX; bucket++)
	{
		Q[bucket] = createLinkedQueue();
	}

	// Ű���� �ڸ�����ŭ, �� �� �� ��� ������ �ݺ� ����
	for (d = 0; d<DIGIT; d++)
	{
		//���� �ڷ� ��ü�� ��ȸ�ϸ� �ؽ����̺� �ִ´�.
		for (i = 0; i<n; i++)
		{
			int tHashResult = (a[i] / factor) % 10;

			enQueue(Q[tHashResult], a[i]);
		}

		//�ؽ����̺�(ü�̴����� ����� ��� ���)�� ��� ���� ���� �ڷᱸ���� �ִ´�.
		for (bucket = 0, i = 0; bucket<RADIX; bucket++)
		{
			while (!isEmpty(Q[bucket]))
			{
				a[i++] = deQueue(Q[bucket]);
			}
		}

		//�ڸ��� �ٲ�
		factor = factor * 10;





		cout << endl << endl << d + 1 << " �ܰ� : ";
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

	cout << endl << " <<<<< ��� ���� ���� >>>>>>";



	radixSort(tList, size);

	return 0;
}

