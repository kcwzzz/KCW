// 170818_container_list.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include	<iostream>
#include <list>

using namespace std;

class CUnit
{
private:
	int mVal = 0;

public:
	CUnit(int tVal)
	{
		mVal = tVal;
	};
	~CUnit() {};

	void SetVal(int tVal)
	{
		mVal = tVal;
	}

	int GetVal()
	{
		return mVal;
	}
};

typedef list<CUnit *> CUnitList;
typedef CUnitList::iterator CUnitListItor;
typedef CUnitList::reverse_iterator CUnitListRitor;

int main()
{
	cout << "STL list" << endl;

	CUnitList tUnitList;
	CUnitListItor tItor;
	CUnitListRitor tRItor;

	CUnit *tpUnit = NULL;

	tpUnit = NULL;
	tpUnit = new CUnit(1);

	tUnitList.push_back(tpUnit);

	tpUnit = NULL;
	tpUnit = new CUnit(2);

	tUnitList.push_back(tpUnit);

	tpUnit = NULL;
	tpUnit = new CUnit(3);

	tUnitList.push_back(tpUnit);


	for (tItor = tUnitList.begin(); tItor != tUnitList.end(); ++tItor)
	{
		cout << "element value : " << (*tItor)->GetVal() << endl<<endl;
	}

	cout << " ==================SetVal" << endl;

	for (tItor = tUnitList.begin(); tItor != tUnitList.end(); ++tItor)
	{

		if (3 == (*tItor)->GetVal())
		{
			(*tItor)->SetVal(777);

			break;
		}
	}

	cout << "====================" << endl;
	for (tItor = tUnitList.begin(); tItor != tUnitList.end(); ++tItor)
	{
		cout << "element value : " << (*tItor)->GetVal() << endl << endl;
	}

	cout << "=============reverse" << endl;

	for (tRItor = tUnitList.rbegin(); tRItor != tUnitList.rend(); ++tRItor)
	{
		cout << "element value : " << (*tRItor)->GetVal() << endl << endl;
	}

	cout << "====delete Elemet" << endl;

	for (tItor = tUnitList.begin(); tItor != tUnitList.end(); )
	{
		if (2 == (*tItor)->GetVal())
		{
			delete (*tItor);

			tItor = tUnitList.erase(tItor);
		}
		else
		{
			++tItor;
		}

	}

	for (tItor = tUnitList.begin(); tItor != tUnitList.end(); ++tItor)
	{
		cout << "element value: " << (*tItor)->GetVal() << endl;
	}

	for (tItor = tUnitList.begin(); tItor != tUnitList.end(); ++tItor)
	{
	
		if (NULL != (*tItor))
		{
			delete (*tItor);
			(*tItor) = NULL;
		}

	}

	tUnitList.clear();

	return 0;
}
