// 170707_Lesson_String_Append.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>>

using namespace std;


int main()
{
	cout << "Hell world" << endl;

	string tString = "abcdefg";


	cout << tString << endl;
	cout << tString.size() << endl;
	cout << tString.length() << endl;
	cout << tString.capacity() << endl;
	cout << tString.max_size() << endl;

	//�޸� ��������
	tString.reserve(32);

	cout << tString << endl;
	cout << tString.size() << endl;
	cout << tString.length() << endl;
	cout << tString.capacity() << endl;
	cout << tString.max_size() << endl;

	tString.append("�ѷ��������̷̤̤����������̷�����������");
	tString.insert(2, "YYY");


	cout << tString << endl;
	cout << tString.size() << endl;
	cout << tString.length() << endl;
	cout << tString.capacity() << endl;
	cout << tString.max_size() << endl;


    return 0;
}

