// lesson_20170626_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()

{
	//입력 값부터 소수 값이어야 결과도 소수로 나온다.
	double num1 = 0;
	double num2 = 0;
	int num_sum = 0;
	int num_sub = 0;
	int num_cross = 0;
	double num_div = 0;
	char oper_num = 0;

	cout << "숫자 1 : ";
	cin >> num1;

	cout << "숫자 2 : ";
	cin >> num2;

	cout << "연산자를 입력해주세요 (+,-,*,/)" :
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

