// 170629_ArrayExample_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int tArray[10] = { 10,1,2,3,4,5,6,7,8,9 };
	int *tpPtr = NULL;//������ ������ �ּҰ��� �ҷ��´�. �ּҰ��� NULLó��

	int ti = 0;
	
	tpPtr = tArray;

	cout << tArray << endl;
	cout << &tArray[0] << endl;
	cout << &tArray << endl;
	cout << tpPtr << endl << endl;

	for (ti = 0;ti < 10; ti++)
	{
		cout << "&tArray[" << ti << "] : " << &tArray[ti] << endl;
		cout << "p + " << ti << ": " << tpPtr + ti << endl;
	}



    return 0;
}

