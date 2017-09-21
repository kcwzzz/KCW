#include "stdafx.h"
#include "Unit.h"
#include "Define.h"

void CUnit :: Setup()
{
}
void CUnit:: Clean(char *tpPixel) // 그래픽 클리어
{
	*(tpPixel + (int)mY*WIDTH + (int)mX) = 0;		
}
void CUnit::Display(char *tpPixel) // 그래픽 표시
{
}

CUnit ::CUnit()
{

}

CUnit :: ~CUnit()
{

}