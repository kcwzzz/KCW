// 170821_priority_queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

