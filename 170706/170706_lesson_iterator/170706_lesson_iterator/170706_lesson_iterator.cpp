// 170706_lesson_iterator.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <vector>>

using namespace std;

class AppleBox
{
private :
	int total;

public : 
	AppleBox();
	void Add(int n);
	void Empty();
	int GetTotal();
};

int main()
{
	AppleBox a1;
	AppleBox a2;
	AppleBox a3;

	a1.Add(10);
	a2.Add(20);
	a3.Add(30);

	vector<AppleBox> v2;

	v2.push_back(a1);
	v2.push_back(a2);
	v2.push_back(a3);

	vector<AppleBox> ::iterator itr_first, itr_last, i_cur;

	itr_first = v2.begin();
	itr_last = v2.end();

	for (i_cur = itr_first; i_cur != itr_last; i_cur++)
	{
//		cout << i_cur->GetTotal() << endl;
		cout << (*i_cur).GetTotal() << endl;
	}

    return 0;
}

AppleBox::AppleBox()
{

}

void AppleBox :: Add(int n)
{
	total = total + n;
}

void AppleBox :: Empty()
{
	total = 0;
}

int AppleBox :: GetTotal()
{
	return total;
}