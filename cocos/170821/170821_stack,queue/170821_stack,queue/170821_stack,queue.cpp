// 170821_stack,queue.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef stack<int> CIntStack;
//typedef CIntStack::iterator CIntStackItor;
//stack, queue�� ���� ���� ���� �Ǿ������Ƿ�, ������ ��ȸ ������ ���Ǿ����� ����.
//�׷��� �ݺ��ڰ� ����. ���� �ּ��� Ǯ�� ������.

typedef queue<int> CIntQueue;


int main()
{

	cout << "STL stack, queue " << endl;

	CIntStack tStack;


	tStack.push(3);
	tStack.push(2);
	tStack.push(1);
	tStack.push(888);

	while (!tStack.empty())
	{
		cout << tStack.top() << endl;
		tStack.pop();
	}

	cout << " ==========================" << endl;

	CIntQueue tQueue;

	tQueue.push(3);
	tQueue.push(2);
	tQueue.push(1);
	tQueue.push(555);
	/*
	while (!tQueue.empty())
	{
		cout << tQueue.front() << endl;

		//		cout << tQueue.pop() << endl;

		tQueue.pop();
	}
	*/
	
	int tVec[4] = {0, 0, 0, 0};

	for (int i = 0; i < 4; i++)
	{
		tVec[i] = tQueue.front();
		cout << tVec[i] << endl;
		tQueue.pop();
	}
	

    return 0;
}

