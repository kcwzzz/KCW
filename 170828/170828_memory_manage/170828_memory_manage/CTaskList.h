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

	size_t mTaskSize;		//�� ����ũ�� ������ ũ��(����Ʈ ����)
	size_t mTaskCount;		//�ش� �½�ũ�� ����, �Ӹ� ������ ���� �ȵ�. ���� �߰��ؾ�

	CTask* GetTask(size_t i);

public:
	CTaskList(size_t size, size_t count);
	~CTaskList();

	void* New(size_t size);
	void Delete(void* p);

	void DisplayActiveTaskList();
	void DisplayFreeTaskList();




};