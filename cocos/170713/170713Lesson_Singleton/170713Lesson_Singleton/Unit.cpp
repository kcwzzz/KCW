#include "stdafx.h"
#include "Unit.h"

#include "Cmanager.h"

CUnit::CUnit()
{
	mIsLive = false;

	mX = 0;
	mY = 0;

	mDir = 0;
}


CUnit::~CUnit()
{
}


bool CUnit :: IsAlive()
{
	return mIsLive;
}
void CUnit::SetAlive(bool tIsLive)
{
	mIsLive = tIsLive;
}

void CUnit::Display()
{
	Cmanager::GetInstance()->Display();
}