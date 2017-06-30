// lesson_170630_ptr_Inarray_new.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//동적할당을 선언해보고, 스왑해보고 

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

void SwapWithPtr(SRectangle *tpARectangle[]);


int main()
{
	//값을 불러오는 것이기 때문에 간접 참조 연산자로 주소를 불러온다.

	SRectangle *tArray[2] = { NULL, NULL };
	//SRectangle 구조의 2개 짜리 배열 선언
	
	SRectangle *tpA = NULL;
	SRectangle *tpB = NULL;

	tpA = new SRectangle();
	tpB = new SRectangle();
	//tpA, tpB를 동적할당

	tpA->mLeft = 0; // 포인터에 접근
	tpA->mTop = 0;
	tpA->mRight = 5;
	tpA->mBottom = 5;

	tpB->mLeft = 0;
	tpB->mTop = 0;
	tpB->mRight = 3;
	tpB->mBottom = 3;
	//할당된 tpA, tpB에 값을 입력
	
	//cout << tArray[0] << endl;
	//cout << tArray[1] << endl;
	
	tArray[0] = tpA;
	tArray[1] = tpB;
	// 선언한 tArray 값에 tpA, tpB를 입력

	///// 이제부터 스왑을 실시
	
	SwapWithPtr(tArray);

	// 힙영역에 할당된 내용을 삭제
	//tArray에 할당된 값은 삭제하지 않고 종료했기 때문에 메모리에 남아있고 불안정하게 되었다. 
	// 동적할당하였으면 꼭 삭제하도록 합니다.
	if (tpB != NULL)
	{
		delete tpB;
		tpB = NULL;
	}

	if (tpA != NULL)
	{
		delete tpA;
		tpA = NULL;
	}

		return 0;
}

void SwapWithPtr(SRectangle *tpARectangle[])
{
	SRectangle tRectangle;
	
	tRectangle = *tpARectangle[0];
	*tpARectangle[0] = *tpARectangle[1];
	*tpARectangle[1] = tRectangle;

	return;
}