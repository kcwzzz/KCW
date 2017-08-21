// 170821_stack,queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef stack<int> CIntStack;
//typedef CIntStack::iterator CIntStackItor;
//stack, queue는 동작 명세가 정의 되어있으므로, 순차적 조회 동작은 명세되어있지 않음.
//그래서 반복자가 없다. 위의 주석을 풀면 에러남.

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

