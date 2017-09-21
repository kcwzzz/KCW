// 170821_priority_queue.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int> CPriorityQ;


int main()
{
	cout << "STL priority_queue"<< endl;

	CPriorityQ tPriorityQ;

	tPriorityQ.push(8);
	tPriorityQ.push(1);
	tPriorityQ.push(6);
	tPriorityQ.push(2);

	while (!tPriorityQ.empty())
	{
		cout << tPriorityQ.top() << endl;
		tPriorityQ.pop();
	}


    return 0;
}

