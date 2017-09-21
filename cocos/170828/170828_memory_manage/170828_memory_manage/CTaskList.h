#pragma once

#include <stdio.h>

class CTask;
class CTaskIter;

class CTaskList
{
	friend CTask;
	friend CTaskIter;

private:
	char* mpBuffer				= NULL;

	CTask *mpActiveTask			= NULL;
	CTask *mpFreeTask			= NULL;

	size_t mTaskSize;		//한 고정크기 영역의 크기(바이트 단위)
	size_t mTaskCount;		//해당 태스크의 갯수, 머리 꼬리는 포함 안됨. 따로 추가해야

	CTask* GetTask(size_t i);

public:
	CTaskList(size_t size, size_t count);
	~CTaskList();

	void* New(size_t size);
	void Delete(void* p);

	void DisplayActiveTaskList();
	void DisplayFreeTaskList();




};