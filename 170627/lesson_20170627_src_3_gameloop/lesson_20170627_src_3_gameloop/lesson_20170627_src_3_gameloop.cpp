// lesson_20170627_src_3_gameloop.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	cout << "program begin. " << endl;

	int tInput = 0;

	//���� ����
	while (1) 
	{
		cin >> tInput;

		//�� ���� ���ϴ� ���� ����� ���ʿ� ���� ������ ���δ�.
		//�ڵ� �� �Ǽ����� �� ������ �����̸�, �۵��� �ǰ�, ���״� ã�� �� ����.
		//���� if (tInput ==9)�� if(tInput =9)�� �� �� ���� ã�� �� ����.

		//���� ���� ���� ����
		if (9 == tInput)
		{
			break;
		}
		cout << "program is running" << endl;
		
	}

	cout << "Programing ends" << endl;


    return 0;
}

