// 170707_Lesson_String.cpp : 嬬車 誓遂 覗稽益轡拭 企廃 遭脊繊聖 舛税杯艦陥.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string str = "sample畠掩疑";

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


	str = "焼焼焼焼焼たた焼焼た焼たたた焼たた焼焼焼焼焼焼焼焼たたた戚舛亀檎";
	cout << "str : " << str << endl;
	cout << "string size :  " << str.size() << endl;
	cout << "string length :  " << str.length() << endl;
	cout << "string capacity :  " << str.capacity() << endl;
	cout << "string max_size :  " << str.max_size() << endl << endl;


    return 0;
}

