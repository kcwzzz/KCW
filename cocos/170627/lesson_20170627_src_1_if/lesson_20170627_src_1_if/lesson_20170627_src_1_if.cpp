// lesson_20170627_src_1_if.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
// if���� ������ ���� ���� �����Դϴ�.
#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int tNumber = 5;
	int tInputNumber = 0;

	cout << "��ȣ�� �Է��ϼ��� :";
	cin >> tInputNumber;

	//�ּ� : ����ÿ� �ּ��� �ڵ�� �ν����� ����.
	/*
	//if�� �ᵵ �ǰ� if else�� �ᵵ �ȴ�.
	if (tInputNumber == tNumber)
	{
		cout << "tInputNumber is same Number tNumber" << endl;
	}
	else
	{
		cout << "tInputNumber is not same Number tNumber" << endl;
	}
	*/

	/*
	if (tInputNumber > tNumber)
	{
		cout << "tInputNumber is greater than tNumber" << endl;

	}

	if (tInputNumber == tNumber)
	{
		cout << "tInputNumber is same as tNumber" << endl;

	}

	if (tInputNumber < tNumber)
	{
		cout << "tInputNumber is lesser than tNumber" << endl;

	}
	*/

	//if else if���� ó��if�������� ������ Ȯ���ϰ�, ������� ������ Ȯ������ �ʰ�, �´� �������� �ٷ� �Ѿ��.(�Ƹ���)
	if (tInputNumber > tNumber)
	{
		cout << "tInputNumber is greater than tNumber" << endl;

	}

	else if (tInputNumber == tNumber)
	{
		cout << "tInputNumber is same as tNumber" << endl;

	}

	else if (tInputNumber < tNumber)
	{
		cout << "tInputNumber is lesser than tNumber" << endl;

	}
	else
	{

	}


    return 0;
}

