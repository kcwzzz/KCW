#include "stdafx.h"
#include "Unit.h"
#include "Define.h"

void CUnit ::  Setup()
{

}
void CUnit::Clean(char *tpPixel) // �׷��� Ŭ����
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = 0;
}
void CUnit::Display(char *tpPixel) // �׷��� ǥ��
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = 'A';
}


CUnit ::CUnit()
{

}

CUnit :: ~CUnit()
{

}