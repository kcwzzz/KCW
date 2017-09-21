// lesson_20170627_src_1_if.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
// if문의 구동을 보기 위한 예제입니다.
#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int tNumber = 5;
	int tInputNumber = 0;

	cout << "번호를 입력하세요 :";
	cin >> tInputNumber;

	//주석 : 빌드시에 주석은 코드로 인식하지 않음.
	/*
	//if만 써도 되고 if else로 써도 된다.
	if (tInputNumber == tNumber)
	{
		cout << "tInputNumber is same Number tNumber" << endl;
	}
	else
	{
		cout << "tInputNumber is not same Number tNumber" << endl;
	}
	*/

	/*
	if (tInputNumber > tNumber)
	{
		cout << "tInputNumber is greater than tNumber" << endl;

	}

	if (tInputNumber == tNumber)
	{
		cout << "tInputNumber is same as tNumber" << endl;

	}

	if (tInputNumber < tNumber)
	{
		cout << "tInputNumber is lesser than tNumber" << endl;

	}
	*/

	//if else if문은 처음if문에서만 조건을 확인하고, 순서대로 조건을 확인하지 않고, 맞는 조건으로 바로 넘어간다.(아마도)
	if (tInputNumber > tNumber)
	{
		cout << "tInputNumber is greater than tNumber" << endl;

	}

	else if (tInputNumber == tNumber)
	{
		cout << "tInputNumber is same as tNumber" << endl;

	}

	else if (tInputNumber < tNumber)
	{
		cout << "tInputNumber is lesser than tNumber" << endl;

	}
	else
	{

	}


    return 0;
}

