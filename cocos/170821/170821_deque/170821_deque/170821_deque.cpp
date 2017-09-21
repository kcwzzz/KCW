// 170821_deque.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#include <deque>

using namespace std;

typedef deque<int> CIntDeque;
typedef CIntDeque::iterator CIntDequeItor;

typedef CIntDeque::reverse_iterator CIntDequeRItor;



int main()
{

	cout << "STL deque" << endl;

	CIntDeque tIntDeque;
	CIntDequeItor tItor;
	CIntDequeRItor tRItor;

	tIntDeque.push_front(3);
	tIntDeque.push_front(2);
	tIntDeque.push_front(1);

	tIntDeque.push_back(33);
	tIntDeque.push_back(22);
	tIntDeque.push_back(11);

	for (tItor = tIntDeque.begin(); tItor != tIntDeque.end(); tItor++)
	{
		cout << "element value : " << *tItor << endl;

	}

	cout << endl << endl;

	for (tRItor = tIntDeque.rbegin(); tRItor != tIntDeque.rend(); tRItor++)
	{
		cout << "element value : " << *tRItor << endl;

	}

	cout << endl << endl;
	//임의 접근이 가능, vector보다는 느림. STL에서 임의 접근 가능하도록 편의추가를 한 듯
	cout << tIntDeque[3] << endl;

	tIntDeque.push_back(888);
	tIntDeque.push_front(777);

	for (tItor = tIntDeque.begin(); tItor != tIntDeque.end(); tItor++)
	{
		cout << "element value : " << *tItor << endl;

	}
	cout << endl << endl;

	tIntDeque.pop_front();
	tIntDeque.pop_back();

	for (tItor = tIntDeque.begin(); tItor != tIntDeque.end(); tItor++)
	{
		cout << "element value : " << *tItor << endl;

	}

	if (!tIntDeque.empty())
	{
		cout << tIntDeque.front() << endl;
		cout << tIntDeque.back() << endl;

	}

	tIntDeque.clear();

	for (tItor = tIntDeque.begin(); tItor != tIntDeque.end(); tItor++)
	{
		cout << "element value : " << *tItor << endl;

	}

    return 0;
}

