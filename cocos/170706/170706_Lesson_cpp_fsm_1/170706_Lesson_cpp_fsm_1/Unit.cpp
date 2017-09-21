#include "stdafx.h"
#include "Unit.h"

#include <iostream>

//������ cpp ������ obj
using namespace std;

CUnit::CUnit()
{
}


CUnit::~CUnit()
{
}

void CUnit::DoIdle()
{
	cout << "DoIdle" << endl;
}

void CUnit::DoAttack()
{
	cout << "Do ATTACK" << endl;

}

void CUnit::SetState(int tState)
{
	mState = tState;
}

void CUnit::Execute()
{
	(this->*mArray[mState])();
}