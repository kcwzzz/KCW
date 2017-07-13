// 170713Lesson_Singleton.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include "Cmanager.h"
#include "Unit.h"

using namespace std;

int main()
{
	Cmanager::GetInstance()->Display(); //동적할당
	Cmanager::GetInstance()->Display(); // main함수에서도

	CUnit tUnit;
	tUnit.Display(); // 다른 클래스나


	//int tIsInput = 0;
	//cin >> tIsInput;

    return 0;
}