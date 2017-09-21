// Lesson_170630_Array2D_0.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define WIDTH 3

int main()
{
	int tArray[2][3] = 
	{
		{ 9, 5, 4 },
		{ 1, 3, 8 }
	};

	int tRow = 0;
	int tCol = 0;
	for (tRow = 0; tRow < 2; tRow++)
	{
		for (tCol = 0; tCol < 3; tCol++)
		{
			cout << "tArray[ " << tRow<< " ] [ " << tCol<< " ] : " << tArray[tRow][tCol] << endl;

		}
	}


	//one for, pointer increase 포문 하나 포인터 증감연산
	cout << "===" << endl;

	int *tpPtr = NULL;
	int ti = 0;
	int tCount = 2 * 3;

	tpPtr = &tArray[0][0];
	//tpPTr 은 Array의 주소값을 갖고 있다.

	for (ti = 0; ti < tCount; ti++)
	{
		cout << *(tpPtr+ti) << endl;
		//cout << tcount] << endl;
	}


	cout << "===" << endl;
	
	//two for, pointer increase
	int tj = 0;

	for (ti = 0; ti < 2; ti++)
	{
		for (tj = 0; tj < 3; tj++)
		{
			cout << *(tpPtr + ti*WIDTH + tj) << endl;
			// 굉장히 많이 쓰는 중요 한 것
		}
	}


    return 0;
}

