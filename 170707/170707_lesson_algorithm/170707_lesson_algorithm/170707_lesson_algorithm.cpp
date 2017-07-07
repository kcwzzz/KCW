// 170707_lesson_algorithm.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

