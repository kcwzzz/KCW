// 170828_friend.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CTestB; 
//class CTestA가 현 시점에서 CTestB 클래스를 모르기때문에 전방선언 해줘야한다.

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
	//CTestB는 CTestA를 friend 선언하지 않았기때문에 private멤버에 접근이 안됨.
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
		//CTestA는 CTestB를 friend 선언해주었기 때문에 private에 접근 가능.
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

