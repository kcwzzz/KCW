// 170707_lesson_algorithm.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string astring;
//	cout << astring << endl;

	getline(cin, astring);

//	cout << astring << endl;

	remove(astring.begin(), astring.end(), 't');

	cout << astring << endl;
    return 0;
}

