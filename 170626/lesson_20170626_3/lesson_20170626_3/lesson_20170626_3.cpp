// lesson_20170626_2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()

{
	//�Է� ������ �Ҽ� ���̾�� ����� �Ҽ��� ���´�.
	double num1 = 0;
	double num2 = 0;
	int num_sum = 0;
	int num_sub = 0;
	int num_cross = 0;
	double num_div = 0;
	char oper_num = 0;

	cout << "���� 1 : ";
	cin >> num1;

	cout << "���� 2 : ";
	cin >> num2;

	cout << "�����ڸ� �Է����ּ��� (+,-,*,/)" :
	cin >> oper_num;

	num_sum = num1 + num2;
	num_sub = num1 - num2;
	num_cross = num1 * num2;
	num_div = num1 / num2;

	if (oper_num == "+")
	{
		cout << num1 << "+" << num2 << "=" << num_sum << endl;
	}

	/*
	cout << num1 << "+" << num2 << "=" << num_sum << endl;
	cout << num1 << "-" << num2 << "=" << num_sub << endl;
	cout << num1 << "*" << num2 << "=" << num_cross << endl;
	cout << num1 << "/" << num2 << "=" << num_div << endl;
	*/
	int stay = 0;
	cin >> stay;

	return 0;
}

