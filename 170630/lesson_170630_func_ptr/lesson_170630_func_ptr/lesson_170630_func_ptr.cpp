// lesson_170630_func_ptr.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int DoSum(int tA, int tB);

int main()
{
	cout << DoSum(2, 3) << endl;
	
	int (*tpPtr)(int, int) = NULL; 

	// 함수 포인터
	// 함수포인터 구조 : 리턴타입(함수포인터 이름)(매개변수 타입)

	tpPtr = DoSum;
	// tpPtr은 코드 영역에 있는 함수의 주소를 불러옴.
	// tpPtr은 DoSum과 같은 구조를 갖고 있으므로, 값을 불러와서 사용이 가능.

	cout << DoSum(2, 8) << endl;
	cout << tpPtr(2, 8) << endl;
	//함수와 함수 포인터는 무슨차이가 있을까?

    return 0;
}

int DoSum(int tA, int tB)
{
	int tResult = 0;

	tResult = tA + tB;

	return tResult;
}