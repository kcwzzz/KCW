// 170828_operator_overloading.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
/*

연산자오버로딩: (C++에서 )클래스에 대해 연산자를 중복해서 정의하는 것

사용법: 'operator키워드 뒤에 해당 연산자를 붙이고' 나서 함수의 구현을 하면 된다.

장점:
1) 해당 연산자 표기의 의미가 유지된다.
2) 간략한 표기가 가능하다.

단점:
1) 구현 난이도가 있다.

*/
#include "stdafx.h"
#include <iostream>

using namespace std;

class CAlgebra
{

private:
	int mVal = 0;

public:
	CAlgebra(int tVal)
		: mVal(tVal)
	{
		
	};

	~CAlgebra() {};

	void operator = (const CAlgebra& tAlgebra)
	{	
		mVal = tAlgebra.mVal;
	};

	CAlgebra operator + (CAlgebra tAlgebra)
	{
		return mVal * 10 + tAlgebra.mVal;
	};

	int GetVal()
	{
		return mVal;
	};

};


int main()
{
	cout << "exam_operator_overload" << endl;

	CAlgebra tA			= 1;
	CAlgebra tB			= 2;
	CAlgebra tResult	= 0;

	tResult = tA + tB;

	cout << tResult.GetVal() << endl;


    return 0;
}

