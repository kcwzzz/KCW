// lesson_170630_func_ptr.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int DoSum(int tA, int tB);

int main()
{
	cout << DoSum(2, 3) << endl;
	
	int (*tpPtr)(int, int) = NULL; 

	// �Լ� ������
	// �Լ������� ���� : ����Ÿ��(�Լ������� �̸�)(�Ű����� Ÿ��)

	tpPtr = DoSum;
	// tpPtr�� �ڵ� ������ �ִ� �Լ��� �ּҸ� �ҷ���.
	// tpPtr�� DoSum�� ���� ������ ���� �����Ƿ�, ���� �ҷ��ͼ� ����� ����.

	cout << DoSum(2, 8) << endl;
	cout << tpPtr(2, 8) << endl;
	//�Լ��� �Լ� �����ʹ� �������̰� ������?

    return 0;
}

int DoSum(int tA, int tB)
{
	int tResult = 0;

	tResult = tA + tB;

	return tResult;
}