// 170629_ArrayExample_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int tArray[10] = { 10,1,2,3,4,5,6,7,8,9 };
	int *tpPtr = NULL;//포인터 변수는 주소값을 불러온다. 주소값을 NULL처리

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

