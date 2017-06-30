// lesson_170630_Array2D.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
// #include ������ ��ó�� ����

using namespace std;

#define WIDTH 3
//WIDTH�� 3���� �ٲ�ġ���Ѵٶ�� ��ó�� ����

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

	
	// �迭 ���� for ������ ���
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

	// �迭�� ����
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

