// 170713Lesson_Singleton.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include "Cmanager.h"
#include "Unit.h"

using namespace std;

int main()
{
	Cmanager::GetInstance()->Display(); //�����Ҵ�
	Cmanager::GetInstance()->Display(); // main�Լ�������

	CUnit tUnit;
	tUnit.Display(); // �ٸ� Ŭ������


	//int tIsInput = 0;
	//cin >> tIsInput;

    return 0;
}