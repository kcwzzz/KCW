// 170629 ArrayExample_2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int *tArray[5] = {NULL, NULL, NULL, NULL, NULL };

	int tA = 0;
	int tB = 0;
	int tC = 0;
	int tD = 0;
	int tE = 0;

	tA = 1;
	tB = 2;
	tC = 3;
	tD = 4;
	tE = 5;

	tArray[0] = &tA;
	tArray[1] = &tB;
	tArray[2] = &tC;
	tArray[3] = &tD;
	tArray[4] = &tE;

	cout << "&tA : " << &tA << endl;
	cout << "&tB : " << &tB << endl;
	cout << "&tC : " << &tC << endl;
	cout << "&tD : " << &tD << endl;
	cout << "&tE : " << &tE << endl;
	cout << endl;
	
	cout << "tArray[0] : " << tArray[0] << endl;
	cout << "tArray[1] : " << tArray[1] << endl;
	cout << "tArray[2] : " << tArray[2] << endl;
	cout << "tArray[3] : " << tArray[3] << endl;
	cout << "tArray[4] : " << tArray[4] << endl;
	cout << endl;
	
	cout << "*tArray[0] : " << *tArray[0] << endl;
	cout << "*tArray[1] : " << *tArray[1] << endl;
	cout << "*tArray[2] : " << *tArray[2] << endl;
	cout << "*tArray[3] : " << *tArray[3] << endl;
	cout << "*tArray[4] : " << *tArray[4] << endl;
	cout << endl;

	//modify elements of array and display 포인터로 접근해서 값을 바꿔봐라.
	*tArray[0] = 21;
	*tArray[3] = 12;

	cout << "*tArray[0] : " << *tArray[0] << endl;
	cout << "*tArray[1] : " << *tArray[1] << endl;
	cout << "*tArray[2] : " << *tArray[2] << endl;
	cout << "*tArray[3] : " << *tArray[3] << endl;
	cout << "*tArray[4] : " << *tArray[4] << endl;
	cout << endl;
    return 0;
}

