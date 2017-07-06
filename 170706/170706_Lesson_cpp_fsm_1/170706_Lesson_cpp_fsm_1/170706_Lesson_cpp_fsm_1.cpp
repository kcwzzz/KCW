// 170706_Lesson_cpp_fsm_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Unit.h"
#include "Actor.h" // Actor.h�� Unit.h�� �����ϰ� �ִ�.#pragma once��  �ߺ� �����ϵǴ� ���� 1���� �����ϵ��� �ߴ�.

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

