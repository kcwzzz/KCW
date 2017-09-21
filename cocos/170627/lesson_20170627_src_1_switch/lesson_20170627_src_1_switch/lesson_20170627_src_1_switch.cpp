// lesson_20170627_src_1_switch.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	float tA = 3;
	float tB = 2;
	float tResult = 0;
	int tSelectOperator = 1;

	cout << "input tA : ";
	cin >> tA;

	cout << "input tB : ";
	cin >> tB;


	cout << endl<<  "연산자를 입력해주세요. 더하기(1), 빼기(2), 곱하기(3), 나누기(4)";
	cin >> tSelectOperator;

	//Break를 입력하지 않으면, Break를 만날 때까지 쭉 진행하니다.
	//만약 switch 구문내에 break를 넣지 않으면, 끝까지 모두 출력합니다.
	//시작점과 끝점은 작성자가 설정을 해줘야하고, 프로그램은 스스로 판단하지 않음.
	switch (tSelectOperator)
	{
	case 1:
	{
		tResult = tA + tB;
		cout << "Addictaive : " << tResult << endl;
	}
	break;

	case 2:
	{
		tResult = tA - tB;
		cout << "Subtract : " << tResult << endl;

	}
	break;

	case 3:
	{
		tResult = tA*tB;
		cout << "Multiply : " << tResult << endl;

	}
	break;

	case 4:
	{
		tResult = tA / tB;
		cout << "Divide : " << tResult << endl;
	}
	break;

	default:
	{
		cout << "잘못된 연산자를 입력하였습니다." << endl;
	}
	break;
	}

    return 0;
}

