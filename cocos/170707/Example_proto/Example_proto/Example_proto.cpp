// Example_proto.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	cout << "�������Դϴ�." << endl;
}
CUnit :: ~CUnit()
{
	cout << "�Ҹ����Դϴ�." << endl;
}