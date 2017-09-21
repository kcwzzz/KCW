// lesson_20170627_src_3_gameloop.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	cout << "program begin. " << endl;

	int tInput = 0;

	//게임 루프
	while (1) 
	{
		cin >> tInput;

		//두 값을 비교하는 경우는 상수를 왼쪽에 쓰는 습관을 들인다.
		//코딩 중 실수했을 때 변수가 왼쪽이면, 작동은 되고, 버그는 찾을 수 없다.
		//예시 if (tInput ==9)를 if(tInput =9)로 잘 못 쓰면 찾을 수 없음.

		//게임 루프 종료 조건
		if (9 == tInput)
		{
			break;
		}
		cout << "program is running" << endl;
		
	}

	cout << "Programing ends" << endl;


    return 0;
}

