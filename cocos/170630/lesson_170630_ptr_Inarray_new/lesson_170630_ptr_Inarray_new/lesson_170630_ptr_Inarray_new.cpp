// lesson_170630_ptr_Inarray_new.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//�����Ҵ��� �����غ���, �����غ��� 

#include "stdafx.h"
#include <iostream>
using namespace std;

struct SRectangle
{
	int mLeft = 0;
	int mTop = 0;
	int mRight = 0;
	int mBottom = 0;

	int mArea = 0;
};

void SwapWithPtr(SRectangle *tpARectangle[]);


int main()
{
	//���� �ҷ����� ���̱� ������ ���� ���� �����ڷ� �ּҸ� �ҷ��´�.

	SRectangle *tArray[2] = { NULL, NULL };
	//SRectangle ������ 2�� ¥�� �迭 ����
	
	SRectangle *tpA = NULL;
	SRectangle *tpB = NULL;

	tpA = new SRectangle();
	tpB = new SRectangle();
	//tpA, tpB�� �����Ҵ�

	tpA->mLeft = 0; // �����Ϳ� ����
	tpA->mTop = 0;
	tpA->mRight = 5;
	tpA->mBottom = 5;

	tpB->mLeft = 0;
	tpB->mTop = 0;
	tpB->mRight = 3;
	tpB->mBottom = 3;
	//�Ҵ�� tpA, tpB�� ���� �Է�
	
	//cout << tArray[0] << endl;
	//cout << tArray[1] << endl;
	
	tArray[0] = tpA;
	tArray[1] = tpB;
	// ������ tArray ���� tpA, tpB�� �Է�

	///// �������� ������ �ǽ�
	
	SwapWithPtr(tArray);

	// �������� �Ҵ�� ������ ����
	//tArray�� �Ҵ�� ���� �������� �ʰ� �����߱� ������ �޸𸮿� �����ְ� �Ҿ����ϰ� �Ǿ���. 
	// �����Ҵ��Ͽ����� �� �����ϵ��� �մϴ�.
	if (tpB != NULL)
	{
		delete tpB;
		tpB = NULL;
	}

	if (tpA != NULL)
	{
		delete tpA;
		tpA = NULL;
	}

		return 0;
}

void SwapWithPtr(SRectangle *tpARectangle[])
{
	SRectangle tRectangle;
	
	tRectangle = *tpARectangle[0];
	*tpARectangle[0] = *tpARectangle[1];
	*tpARectangle[1] = tRectangle;

	return;
}