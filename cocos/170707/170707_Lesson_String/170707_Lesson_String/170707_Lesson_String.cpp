// 170707_Lesson_String.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string str = "sample홍길동";

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


	str = "아아아아아ㅏㅏ아아ㅏ아ㅏㅏㅏ아ㅏㅏ아아아아아아아아ㅏㅏㅏ이정도면";
	cout << "str : " << str << endl;
	cout << "string size :  " << str.size() << endl;
	cout << "string length :  " << str.length() << endl;
	cout << "string capacity :  " << str.capacity() << endl;
	cout << "string max_size :  " << str.max_size() << endl << endl;


    return 0;
}

