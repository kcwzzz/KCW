// Lesson_170630_Delete.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//�����Ҵ翡 ���ؼ� ������ô�. ������

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int *tpA = NULL;
//	cout << tpA << endl;
//	cout << &tpA << endl;

	tpA = new int();
	
//	cout << tpA << endl;
//	cout << *tpA << endl;
//	cout << &tpA << endl;


	if (NULL != tpA)
	{
		delete tpA;
		tpA = NULL;
	}
//	cout << tpA << endl;
	

	int *tArray[5] = { NULL, NULL, NULL, NULL, NULL }; 
	// �迭�� ���ÿ� ��ġ��.
	// �����Ҵ��� ���� 5���� ���� �Ǿ��ִ�.			
	
	int ti = 0;
	for (ti = 0; ti < 5; ti++)
	{
		tArray[ti] = new int();

	}

	for (ti = 0; ti < 5; ti++)
	{
		delete tArray[ti];
		tArray[ti] = NULL;
	}

	//new : �޸� �����Ҵ�, �ּҰ��� �����ش�.
	// �����Ҵ��� �� ���Ϳ� ����ȴ�.
	
	int tCount = 5;

	int *tpB = NULL; 
	tpB = new int[5];
	// �����Ͱ� ���ÿ� ��ġ��
	// �����Ҵ�� 5��¥�� �迭�� ���� ��ġ��.
	
	cout << tpB << endl;
	cout << *tpB << endl;
	cout << &tpB << endl;


	if (NULL != tpB)
	{
		delete[] tpB;
		tpB = NULL;
	}
	
	return 0;


}

