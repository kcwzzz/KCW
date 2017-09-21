// lesson_170630_Array2D.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
// #include 종류는 전처리 구문

using namespace std;

#define WIDTH 3
//WIDTH는 3으로 바꿔치기한다라는 전처리 구문

int main()
{

	int tArray_2D[ 2 ][ 3 ] = 
	{
		{9, 5, 4},
		{1, 3, 8}
	};

	cout << "tArray_2D : \t\t" << tArray_2D << endl << endl;

	cout << "tArray_2D[0] : \t\t" << tArray_2D[0] << endl;
	cout << "&tArray_2D[0] : \t" << &tArray_2D[0] << endl;
	cout << "&tArray_2D[0][0] : \t" << &tArray_2D[0][0] << endl << endl;
	

	cout << "tArray_2D[1] : \t\t" << tArray_2D[1] << endl;
	cout << "&tArray_2D[1] : \t" << &tArray_2D[1] << endl;
	cout << "&tArray_2D[1][0] : \t" << &tArray_2D[1][0] << endl << endl;

	cout << "tArray_2D[1][0] : " << tArray_2D[1][0] << endl;

	
	// 배열 값을 for 문으로 출력
	int ti = 0;
	int tj = 0;

	int tMaxRow = 0;
	int tMaxCol = 0;
	int tResult = 0;

	tMaxRow = 2;
	tMaxCol = 3;
	for (ti = 0; ti < tMaxRow; ti++)
	{
		for (tj = 0; tj < tMaxCol; tj++)
		{
			tResult = tArray_2D[ti][tj];

			cout <<"tArray_2D["<<ti<< "][" << tj << "] : " << tResult << endl;
		}
	}

	cout << endl;

	// 배열의 길이
	cout << "sizeof(tArray_2D) : \t" << sizeof(tArray_2D) << endl;
	cout << endl;
	
	cout << "sizeof(tArray_2D[0]) : \t" << sizeof(tArray_2D[0]) << endl;
	cout << "sizeof(tArray_2D[0][0]) : " << sizeof(tArray_2D[0][0]) << endl;
	cout << endl;

	cout << "sizeof(tArray_2D[1]) : \t" << sizeof(tArray_2D[1]) << endl;
	cout << "sizeof(tArray_2D[1][0]) : " << sizeof(tArray_2D[1][0]) << endl;
	cout << endl;



    return 0;
}

