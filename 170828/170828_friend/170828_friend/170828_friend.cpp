// 170828_friend.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CTestB; 
//class CTestA�� �� �������� CTestB Ŭ������ �𸣱⶧���� ���漱�� ������Ѵ�.

class CTestA
{
	friend CTestB;

private:
	int mA_X = 777;

public:
	void Display(CTestB *tTestB)
	{
		cout << "CTestA :: Display" << endl;
		//cout << "tTestB->mB_XS : " << tTestB->mB_X << endl;
	//CTestB�� CTestA�� friend �������� �ʾұ⶧���� private����� ������ �ȵ�.
	};
};

class CTestB
{
private:
	int mB_X = 111;

public:
	void Display(CTestA *tTestA)
	{
		cout << "CTestB :: Display ";
		cout << "tTestA->mA_X : " << tTestA->mA_X << endl;
		//CTestA�� CTestB�� friend �������־��� ������ private�� ���� ����.
	};
};

int main()
{
	cout << "exam_friend" << endl;

	CTestA tTestA;
	CTestB tTestB;

	tTestA.Display(&tTestB);
	tTestB.Display(&tTestA);


    return 0;
}

