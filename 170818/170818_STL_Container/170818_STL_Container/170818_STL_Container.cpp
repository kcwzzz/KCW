// 170818_STL_Container.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#include <vector>

using namespace std;

typedef vector<int> CIntVec;
typedef CIntVec::iterator CIntVecItor;

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "STL vector\n";


	CIntVec tIntVec;


	tIntVec.reserve(10);


	tIntVec.push_back(3);
	tIntVec.push_back(99);
	tIntVec.push_back(42);


	for (CIntVecItor tItor = tIntVec.begin(); tItor != tIntVec.end(); ++tItor)
	{
		cout << "element value: " << *tItor << endl;
	}


	tIntVec[0] = 50;
	tIntVec[1] = 32;
	tIntVec[2] = 999;

	for (CIntVecItor tItor = tIntVec.begin(); tItor != tIntVec.end(); ++tItor)
	{
		cout << "element value: " << *tItor << endl;
	}


	return 0;
}