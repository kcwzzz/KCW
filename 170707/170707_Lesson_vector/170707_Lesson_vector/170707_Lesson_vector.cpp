// 170707_Lesson_vector.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//1. int pointer 값을 받는 배열을 선언(벡터로)
//2. 사이즈는 5로 한다.
//3. 동적 할당 
//4. 포인터로
//5. 출력

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int *> CIntVec;
typedef CIntVec::iterator CIntVecItor;

int main()
{
	int ti = 0;

	//vector<int *> tIntVec;
	CIntVec  tIntVec;
	tIntVec.resize(5);
	
	for (ti = 0; ti < 5; ti++)
	{
		tIntVec[ti] = new int();
	}

	for (ti = 0; ti < 5; ti++)
	{
		(*tIntVec[ti]) = ti;
	}
	
	for (ti = 0; ti < 5; ti++)
	{

		cout << (tIntVec[ti]) << endl;
		cout << (*tIntVec[ti]) << endl;

		cout << (&tIntVec[ti]) << endl;
	}

	for (ti = 0; ti < 5; ti++)
	{
		if (NULL != tIntVec[ti])
		{
			delete tIntVec[ti];
			tIntVec[ti] = NULL;
		}
	
	}
	tIntVec.clear();//vector라는 객체는 남아있는데 그 안에 있는 값들이 초기화 됨. 사이즈라던지, 메모리 할당이라던지 

    return 0;
}

