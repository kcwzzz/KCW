// 170828_operator_overloading.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
/*

�����ڿ����ε�: (C++���� )Ŭ������ ���� �����ڸ� �ߺ��ؼ� �����ϴ� ��

����: 'operatorŰ���� �ڿ� �ش� �����ڸ� ���̰�' ���� �Լ��� ������ �ϸ� �ȴ�.

����:
1) �ش� ������ ǥ���� �ǹ̰� �����ȴ�.
2) ������ ǥ�Ⱑ �����ϴ�.

����:
1) ���� ���̵��� �ִ�.

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

