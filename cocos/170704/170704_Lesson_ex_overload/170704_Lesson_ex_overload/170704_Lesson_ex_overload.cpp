// 170704_Lesson_ex_overload.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	//�Լ� �����ε�
	//C++�� ���� �̸��� �Լ��� �����ϴ� ���� ���
	//�ٸ� �Լ��� �Ű����������� �޶���Ѵ�.

	MYFunc();
	MYFunc('a');
	MYFunc(10, 14);


    return 0;
}

