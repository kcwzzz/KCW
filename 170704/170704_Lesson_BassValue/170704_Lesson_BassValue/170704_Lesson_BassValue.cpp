// 170704_Lesson_BassValue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//매개변수의 기본값을 지정해줄수 있음
// 대신 기본값은 우측값부터 채워야 한다. 아니면 에러 터짐
//int BoxVolume(int length, int width =1, int height); <<-- 는 height가 빈값이라 안됨.

int BoxVolume(int length=3, int width=1, int height=1);


int main()
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	cout << "[D, D, D] : " << BoxVolume() << endl;

    return 0;
}


int BoxVolume(int length, int width, int height)
{
	return length*width*height;
}