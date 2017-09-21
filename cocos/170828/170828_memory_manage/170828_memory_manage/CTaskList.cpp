#include "CTaskList.h"
#include "CTask.h"




CTaskList:: CTaskList(size_t size, size_t count)
	:mTaskSize(size), mTaskCount(count)
{
	mpBuffer = new char[mTaskSize*(mTaskCount + 2)]; 
	//linked list의  head tail을 포함해서 mTaskCount는 +2 한다.
	
	mpActiveTask = GetTask(0);
	mpActiveTask->mpPrev = mpActiveTask->mpNext = mpActiveTask;

	mpFreeTask = GetTask(1);
	for (size_t ti = 1; ti < mTaskCount + 1; ti++)
	{
		GetTask(ti)->mpPrev = NULL;
		GetTask(ti)->mpNext = NULL;
	}
	GetTask(mTaskCount + 1)->mpNext = mpFreeTask;

}

CTaskList ::~CTaskList()
{
	delete [] mpBuffer;
	
}

CTask* CTaskList::GetTask(size_t i)
{
	return (CTask*)(mpBuffer + mTaskSize*i);
}

void* CTaskList:: New(size_t size)
{
	if (mpFreeTask->mpNext == mpFreeTask)
	{
		return NULL;
	}

	CTask* task = mpFreeTask->mpNext;
	mpFreeTask->mpNext = task->mpNext;
	return task;
}


void Delete(void* p);

void DisplayActiveTaskList();
void DisplayFreeTaskList();
