// lesson_20170626_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()

{
	//입력 값부터 소수 값이어야 결과도 소수로 나온다.
	int num1 = 0;
	int num2 = 0;
	
	
	int num_sum = 0;
	int num_sub = 0;
	int num_cross = 0;
	double num_div = 0;
	

	cout << "숫자 1 : ";
	cin >> num1;
	cout << "숫자 2 : ";
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
	//타입을 바꾸는 것을 명시적 형변환(type cast)라 한다.
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

