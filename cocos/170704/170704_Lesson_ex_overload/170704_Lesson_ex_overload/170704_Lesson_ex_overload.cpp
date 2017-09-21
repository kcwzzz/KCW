// 170704_Lesson_ex_overload.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



void MYFunc()
{
	cout << "MyFunc(void) called" << endl;
	return;
}

void MYFunc(char c)
{
	cout << "MyFunc(char) called" << endl;
	return;
}

void MYFunc(int a, int b)
{
	cout << "MyFunc(int a, int b) called" << endl;
	return;
}

int main()
{
	//함수 오버로딩
	//C++은 같은 이름의 함수를 선언하는 것을 허용
	//다만 함수의 매개변수내용은 달라야한다.

	MYFunc();
	MYFunc('a');
	MYFunc(10, 14);


    return 0;
}

