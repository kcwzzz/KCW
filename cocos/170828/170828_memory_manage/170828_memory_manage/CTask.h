#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

class CTaskList;
class CTaskIter;

class CTask
{
	friend CTaskList;
	friend CTaskIter;


private:
	CTask *mpPrev = NULL;
	CTask *mpNext = NULL;

public : 
	void* operator new(size_t n)
	{
		cout << "operator new " << endl;

		return NULL;
	}

	void operator delete(void* p)
	{

	}

	CTask(CTaskList* list);
	virtual CTask();


};