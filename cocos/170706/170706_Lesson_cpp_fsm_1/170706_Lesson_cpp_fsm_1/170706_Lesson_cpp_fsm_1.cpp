// 170706_Lesson_cpp_fsm_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Unit.h"
#include "Actor.h" // Actor.h는 Unit.h를 포함하고 있다.#pragma once가  중복 컴파일되는 것을 1번만 실행하도록 했다.

int main()
{
	int ti = 0;
	int tCount = 0;

	CUnit *tArray[2] = { NULL, NULL };

	tArray[0] = new CUnit();
	tArray[1] = new CActor();

	tCount = 2;

	for (ti = 0; ti < tCount; ti++)
	{
		tArray[ti]->SetState(0);
		tArray[ti]->Execute();
	}

	for (ti = 0; ti < tCount; ti++)
	{
		tArray[ti]->SetState(1);
		tArray[ti]->Execute();
	}
		
	for (int ti = 0; ti < tCount; ti++)
	{
		if (NULL != tArray[ti])
		{
			delete tArray[ti];
			tArray[ti] = NULL;
		}
	}


	return 0;
}

