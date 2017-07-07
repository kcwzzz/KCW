// 170707_Lesson_String_Append.cpp : 能贾 览侩 橇肺弊伐俊 措茄 柳涝痢阑 沥狼钦聪促.
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

	//皋葛府 傍埃抗距
	tString.reserve(32);

	cout << tString << endl;
	cout << tString.size() << endl;
	cout << tString.length() << endl;
	cout << tString.capacity() << endl;
	cout << tString.max_size() << endl;

	tString.append("堆逢风风风风风逢风ぬぬぬ风风风风风风风风风风ぬ风风风风风风风风风风逢");
	tString.insert(2, "YYY");


	cout << tString << endl;
	cout << tString.size() << endl;
	cout << tString.length() << endl;
	cout << tString.capacity() << endl;
	cout << tString.max_size() << endl;


    return 0;
}

