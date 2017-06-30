// Lesson_170630_Delete.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//동적할당에 대해서 배워봅시다. 여러분

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int *tpA = NULL;
//	cout << tpA << endl;
//	cout << &tpA << endl;

	tpA = new int();
	
//	cout << tpA << endl;
//	cout << *tpA << endl;
//	cout << &tpA << endl;


	if (NULL != tpA)
	{
		delete tpA;
		tpA = NULL;
	}
//	cout << tpA << endl;
	

	int *tArray[5] = { NULL, NULL, NULL, NULL, NULL }; 
	// 배열이 스택에 위치함.
	// 동적할당은 힙에 5개가 따로 되어있다.			
	
	int ti = 0;
	for (ti = 0; ti < 5; ti++)
	{
		tArray[ti] = new int();

	}

	for (ti = 0; ti < 5; ti++)
	{
		delete tArray[ti];
		tArray[ti] = NULL;
	}

	//new : 메모리 동적할당, 주소값을 돌려준다.
	// 동적할당을 힙 섹터에 저장된다.
	
	int tCount = 5;

	int *tpB = NULL; 
	tpB = new int[5];
	// 포인터가 스택에 위치함
	// 동적할당된 5개짜리 배열이 힙에 위치함.
	
	cout << tpB << endl;
	cout << *tpB << endl;
	cout << &tpB << endl;


	if (NULL != tpB)
	{
		delete[] tpB;
		tpB = NULL;
	}
	
	return 0;


}

