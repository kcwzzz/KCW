// 170707_Lesson_String.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string str = "sampleȫ�浿";

	cout << "str(\"sample\", 16) : " << str << " : " << endl;
	cout << "string size :  " << str.size()<< endl;
	cout << "string length :  " << str.length() << endl;
	cout << "string capacity :  " << str.capacity() << endl;
	cout << "string max_size :  " << str.max_size() << endl<< endl;

	str.reserve(32);

	cout << "str.reserve(32) : " << str << endl;
	cout << "string size :  " << str.size() << endl;
	cout << "string length :  " << str.length() << endl;
	cout << "string capacity :  " << str.capacity() << endl;
	cout << "string max_size :  " << str.max_size() << endl << endl;


	str = "�ƾƾƾƾƤ����ƾƤ��Ƥ������Ƥ����ƾƾƾƾƾƾƾƤ�������������";
	cout << "str : " << str << endl;
	cout << "string size :  " << str.size() << endl;
	cout << "string length :  " << str.length() << endl;
	cout << "string capacity :  " << str.capacity() << endl;
	cout << "string max_size :  " << str.max_size() << endl << endl;


    return 0;
}

