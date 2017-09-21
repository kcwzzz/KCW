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

typedef vector<int *> CIntVec; // int point 타입을 받는 배열

typedef CIntVec::iterator CIntVecItor;

int main()
{
	int ti = 0;

	CIntVec tIntVec;
	tIntVec.reserve(5);

	int *tpInt = NULL;

	for (ti = 0; ti < 5; ti++)
	{
		tpInt = NULL;
		tpInt = new int();

		tIntVec.push_back(tpInt);
	}

	int tVal = 0;
	for (CIntVecItor tItor = tIntVec.begin(); tItor != tIntVec.end(); ++tItor)
	{
		(*(*tItor)) = tVal;
		tVal++;

		cout << (*(*tItor)) << endl;

	/*
	for (CIntVecItor tItor = tIntVec.begin(); tItor != tIntVec.end(); ++tItor)
	{
		cout << (*(*tItor)) << endl;
	}

	for (CIntVecItor tItor = tIntVec.begin(); tItor != tIntVec.end(); ++tItor)
	{
		if (NULL != (*tItor))
		{
			delete (*tItor);
			(*tItor) = NULL;
		}
	}

	*/

	tIntVec.clear();//vector라는 객체는 남아있는데 그 안에 있는 값들이 초기화 됨. 사이즈라던지, 메모리 할당이라던지 

	return 0;
}

