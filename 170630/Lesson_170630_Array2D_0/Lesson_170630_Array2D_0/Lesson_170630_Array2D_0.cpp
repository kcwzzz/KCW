// Lesson_170630_Array2D_0.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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


	//one for, pointer increase ���� �ϳ� ������ ��������
	cout << "===" << endl;

	int *tpPtr = NULL;
	int ti = 0;
	int tCount = 2 * 3;

	tpPtr = &tArray[0][0];
	//tpPTr �� Array�� �ּҰ��� ���� �ִ�.

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
			// ������ ���� ���� �߿� �� ��
		}
	}


    return 0;
}

