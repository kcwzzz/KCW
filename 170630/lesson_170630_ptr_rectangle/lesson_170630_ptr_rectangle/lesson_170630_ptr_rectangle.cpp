// lesson_170630_ptr_rectangle.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

struct SRectangle
{
	int mLeft = 0;
	int mTop = 0;
	int mRight = 0;
	int mBottom = 0;

	int mArea = 0;
};

// 넓이 구하는 함수
int DoCalulationArea(SRectangle *tpRectangle);

// 포인터를 사용한 스왑 함수
void SwapWithPtr(SRectangle *tpARectangle, SRectangle *tpBRectangle);

int main()
{
	SRectangle tARectangle;
	SRectangle tBRectangle;

	tARectangle.mLeft = 5;
	tARectangle.mTop = 0;
	tARectangle.mRight =0;
	tARectangle.mBottom = 5;

	tBRectangle.mLeft = 0;
	tBRectangle.mTop = 0;
	tBRectangle.mRight = 3;
	tBRectangle.mBottom = 3;

	tARectangle.mArea = DoCalulationArea(&tARectangle);
	tBRectangle.mArea = DoCalulationArea(&tBRectangle);

	cout << "tARectangle Area : " << tARectangle.mArea << endl;
	cout << "tBRectangle Area : " << tBRectangle.mArea << endl;

	SwapWithPtr(&tARectangle, &tBRectangle);
	
	/*
	cout << "tARectangle Right : " << tARectangle.mRight << endl;
	cout << "tBRectangle Right : " << tBRectangle.mRight << endl;

	cout << "tARectangle Left : " << tARectangle.mLeft << endl;
	cout << "tBRectangle Left : " << tBRectangle.mLeft << endl;

	cout << "tARectangle Top : " << tARectangle.mTop << endl;
	cout << "tBRectangle Top : " << tBRectangle.mTop << endl;

	cout << "tARectangle Bottom : " << tARectangle.mBottom << endl;
	cout << "tBRectangle Bottom : " << tBRectangle.mBottom << endl;
	*/

	return 0;
}

int DoCalulationArea(SRectangle *tpRectangle)
{
	int tReturn = 0;
	int tWidth = 0;
	int tHeight = 0;

	tWidth = tpRectangle->mRight - tpRectangle->mLeft;
	tHeight = tpRectangle->mBottom - tpRectangle->mTop;
		
	tReturn = tWidth * tHeight;
	
	if (tReturn < 0)
	{
		tReturn = -tReturn;
	}
	
	return tReturn;
}

void SwapWithPtr(SRectangle *tpARectangle, SRectangle *tpBRectangle)
{
	SRectangle tRectangle;
	tRectangle = *tpARectangle;


}
