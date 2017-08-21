// 170821_custom_priorityQ.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

class CRect
{
private:
	int mWidth = 0;
	int mHeight = 0;

public:
	CRect(int tWidth, int tHeight)
		: mWidth(tWidth), mHeight(tHeight) {};
	//�Ű������� �޴� ������

	//const ��� : ���� �ٲ� �� ����.

	bool operator< (const CRect &tRect) const
	{
		return mWidth*mHeight < tRect.mWidth*tRect.mHeight;
	}	

	void Display()
	{
		cout << "CRect : " << mWidth << " * " << mHeight << " = " << mWidth * mHeight << endl;
	}

};

typedef priority_queue < CRect, vector<CRect>, less<CRect>> CPriorityQ;

int main()
{
	cout << "STL priority_queue_0" << endl;

	CPriorityQ tPriorityQ;

	CRect tRect_0(1, 5);
	CRect tRect_1(7, 6);
	CRect tRect_2(1, 2);
	CRect tRect_3(8, 2);

	tPriorityQ.push(tRect_0);
	tPriorityQ.push(tRect_1);
	tPriorityQ.push(tRect_2);
	tPriorityQ.push(tRect_3);

	while (!tPriorityQ.empty())
	{
		CRect tRect = tPriorityQ.top();
		tPriorityQ.pop();

		tRect.Display();
	}

    return 0;
}

