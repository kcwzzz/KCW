// 170707_lesson_subStr.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	string str("1234567890");
	cout << str.substr(5) << endl; //5��° ���� ��� (��ǻ�ʹ� 0���� �����̱� ������ ������ 6��°�������� ��µ�)
	cout << str.substr(5, 3) << endl; //5��° ���� 3���� ���� ���
    return 0;
}

