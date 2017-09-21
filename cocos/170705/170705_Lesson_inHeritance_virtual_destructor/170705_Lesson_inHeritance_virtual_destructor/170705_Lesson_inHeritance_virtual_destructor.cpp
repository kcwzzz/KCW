// 170705_Lesson_inHeritance_virtual_destructor.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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