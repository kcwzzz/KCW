// 170707_lesson_subStr.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	string str("1234567890");
	cout << str.substr(5) << endl; //5번째 부터 출력 (컴퓨터는 0부터 시작이기 때문에 실제로 6번째차레부터 출력됨)
	cout << str.substr(5, 3) << endl; //5번째 부터 3개의 숫자 출력
    return 0;
}

