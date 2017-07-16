#include "stdafx.h"
#include "Unit.h"
#include "Define.h"

CUnit::CUnit()
{
}

CUnit::~CUnit()
{
}

void CUnit::Setup()
{

}

void CUnit::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}

void CUnit::Display(char *tpPixel)
{

}
int CUnit::GetmState()
{
	return mState;
}

int CUnit::GetX()
{
	return mX;
}
int CUnit::GetY()
{
	return mY;
}