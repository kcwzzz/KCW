// 170707_Lesson_vector.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//1. int pointer ���� �޴� �迭�� ����(���ͷ�)
//2. ������� 5�� �Ѵ�.
//3. ���� �Ҵ� 
//4. �����ͷ�
//5. ���

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int *> CIntVec; // int point Ÿ���� �޴� �迭

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

	tIntVec.clear();//vector��� ��ü�� �����ִµ� �� �ȿ� �ִ� ������ �ʱ�ȭ ��. ����������, �޸� �Ҵ��̶���� 

	return 0;
}

