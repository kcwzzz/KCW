// lesson_20170626_2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()

{
	//�Է� ������ �Ҽ� ���̾�� ����� �Ҽ��� ���´�.
	int num1 = 0;
	int num2 = 0;
	
	
	int num_sum = 0;
	int num_sub = 0;
	int num_cross = 0;
	double num_div = 0;
	

	cout << "���� 1 : ";
	cin >> num1;
	cout << "���� 2 : ";
	cin >> num2;

	num_sum = num1+num2;
	num_sub = num1 - num2;
	num_cross = num1 * num2;
	num_div = double(num1)/ double(num2);
	/*
	cout << num1 << "+" << num2 << "=" << num1+num2 << endl;
	cout << num1 << "-" << num2 << "=" << num1-num2 << endl;
	cout << num1 << "*" << num2 << "=" << num1*num2 << endl;
	cout << num1 << "/" << num2 << "=" << num1/num2 << endl;
	//cout << num1 << "/" << num2 << "=" << (float)num1 / (float)num2 << endl;
	//Ÿ���� �ٲٴ� ���� ����� ����ȯ(type cast)�� �Ѵ�.
	*/

	cout << num1 << "+" << num2 << "=" << num_sum << endl;
	cout << num1 << "-" << num2 << "=" << num_sub << endl;
	cout << num1 << "*" << num2 << "=" << num_cross << endl;
	cout << num1 << "/" << num2 << "=" << num_div << endl;
	

	cout << "sizeof(num1) = " << sizeof(num1) << endl;
	cout << "sizeof(num2) = " << sizeof(num2) << endl;
	cout << "sizeof(num_sum) = " << sizeof(num_sum) << endl;
	cout << "sizeof(num_sub) = " << sizeof(num_sub) << endl;
	cout << "sizeof(num_cross) = " << sizeof(num_cross) << endl;
	cout << "sizeof(num_div) = " << sizeof(num_div) << endl;
	int stay = 0;
	cin >> stay;

    return 0;
}

