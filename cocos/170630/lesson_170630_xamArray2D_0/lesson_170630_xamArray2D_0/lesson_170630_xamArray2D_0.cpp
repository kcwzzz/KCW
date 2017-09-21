// lesson_170630_xamArray2D_0.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


//구조체, 함수는 코드 영역에 저장이 되어서 실행
//힙, 스택은 실행중에 사용하는 것이고, 코드는 실행파일에 박혀있는 것이다.

struct SRectangle
{
	int mLeft = 0;
	int mTop = 0;
	int mRight = 0;
	int mBottom = 0;

	int mArea = 0;
};

int main()
{
	int *tpA = NULL;
	tpA = new int();

	SRectangle *tpRectangle = NULL;
	tpRectangle = new SRectangle();

	if (NULL != tpRectangle)
	{
		delete tpRectangle;
		tpRectangle = NULL;
	}

	if (NULL != tpA)
	{
		delete tpA;
		tpA = NULL;
	}

    return 0;
}

