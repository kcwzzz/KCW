// lesson_20170627_src_2_for.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//


//��� ������ " "(����� Ȥ�� ������ �����)�� < >(MS�� �����)�� �ٸ�����
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int ti = 0;
	int tj = 0;
	int tResult = 0;


	// for���� �۵� ����
	// 1. ti=1 : �ʱ�ȭ�� ���� ����
	// 2. ti <= 9 : ������ �����ϴ��� üũ��
	// 3. �Ʒ��� for���� ������.
	// 4, ti++ : ti���� �����ش�.

	/*
	for (ti = 1; ti <= 9; ti++)
	{
		for (tj = 1; tj <= 9; tj++)
		{
			tResult = ti*tj;

			cout << ti << " * " << tj << " = " << tResult << endl;
			
		}
		cout << endl;
	}
	*/

	/*
	for (ti = 1; ti < 10; ti++)
	{
		tResult = 0;
		
		for (tj = 1; tj < 10; tj++)
		{
			tResult = tResult + ti;
			cout << ti << " * " << tj << " = " <<tResult<< endl;
		}
		
		cout << endl;

	}
	*/


	//�̷� ������ 3���� ������ ���� �� 27�������� �������� ������ ���� �ִ�.
	for (ti = 1; ti < 8; ti = ti + 3)
	{

		for (tj = 1; tj < 10; tj++)
		{
			cout << ti << " * " << tj << " = " << ti*tj << "\t" << ti + 1 << " * " << tj << " = " << (ti + 1)*tj << "\t" << ti + 2 << " * " << tj << " = " << (ti + 2)*tj << endl;
		}
		cout << endl;
	}

    return 0;
}

