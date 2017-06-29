// lesson_20170626_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//헤더파일 : 함수의 이름이 명시되어있음.
#include <iostream>
using namespace std;

int main()
{
	//지역변수 : 선언할 때 생성되고 해당 변수가 속한 scope(여기에선 main함수)가 끝날 때 사라짐
	//int : 정수. 해당 메모리를 정수형 변수로 다루겠다 선언
	int tA = 0;
	int tB = 0;
	int tResult = 0;
	
	tA = 2;
	tB = 3;
	
	tResult = tA + tB;

	cout << tResult << endl;

	//포준 출력(모니터)
	
	//키보드(입력장치)에서 값을 받아서 tInput에 넣음.
	int tInput = 0;

	//표준 입력(키보드)
	cin >> tInput;
		
    return 0;
}

