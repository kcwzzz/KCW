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
	tIntVec.clear();//vector��� ��ü�� �����ִµ� �� �ȿ� �ִ� ������ �ʱ�ȭ ��. ����������, �޸� �Ҵ��̶���� 

    return 0;
}

