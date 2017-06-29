// lesson_20170627_src_2_for.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//


//헤더 파일이 " "(사용자 혹은 누군가 만든거)랑 < >(MS가 만든거)로 다른이유
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int ti = 0;
	int tj = 0;
	int tResult = 0;


	// for문의 작동 순서
	// 1. ti=1 : 초기화를 먼저 진행
	// 2. ti <= 9 : 조건을 만족하는지 체크함
	// 3. 아래의 for문을 돌린다.
	// 4, ti++ : ti값을 더해준다.

	/*
	for (ti = 1; ti <= 9; ti++)
	{
		for (tj = 1; tj <= 9; tj++)
		{
			tResult = ti*tj;

			cout << ti << " * " << tj << " = " << tResult << endl;
			
		}
		cout << endl;
	}
	*/

	/*
	for (ti = 1; ti < 10; ti++)
	{
		tResult = 0;
		
		for (tj = 1; tj < 10; tj++)
		{
			tResult = tResult + ti;
			cout << ti << " * " << tj << " = " <<tResult<< endl;
		}
		
		cout << endl;

	}
	*/


	//이런 식으로 3번만 루프를 돌려 총 27번정도로 구구단을 정리할 수도 있다.
	for (ti = 1; ti < 8; ti = ti + 3)
	{

		for (tj = 1; tj < 10; tj++)
		{
			cout << ti << " * " << tj << " = " << ti*tj << "\t" << ti + 1 << " * " << tj << " = " << (ti + 1)*tj << "\t" << ti + 2 << " * " << tj << " = " << (ti + 2)*tj << endl;
		}
		cout << endl;
	}

    return 0;
}

