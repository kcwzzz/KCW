// Example_proto.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CUnit
{
public :
	CUnit();
	~CUnit();
}

int main()
{
	CUnit *tpUnit;
	cout << tpUnit << endl;
    return 0;
}

CUnit::CUnit() 
{
	cout << "생성자입니다." << endl;
}
CUnit :: ~CUnit()
{
	cout << "소멸자입니다." << endl;
}