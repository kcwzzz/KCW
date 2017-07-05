// 170705_Lesson_inHeritance_virtual_destructor.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CUnit
{
public:
	CUnit();
	//~CUnit();
	virtual ~CUnit();

};

class CActor : public CUnit
{
public:
	CActor();
	~CActor();
	//virtual ~CActor();

};

int main()
{
	CUnit *tpActor = NULL;
	tpActor = new CActor();

	if(NULL !=tpActor)
	{
		delete tpActor;
		tpActor = NULL;
	}
	
    return 0;
}

CUnit::CUnit()
{
	cout << "CUnit :: CUnit" << endl;
}

CUnit::~CUnit()
{
	cout << "CUnit :: ~CUnit" << endl;
}

CActor::CActor	()
{
	cout << "CUnit :: CActor" << endl;
}

CActor::~CActor()
{
	cout << "CUnit :: ~CActor" << endl;
}