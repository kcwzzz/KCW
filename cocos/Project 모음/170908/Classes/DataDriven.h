#pragma once

#include <stdio.h>
#include <vector>

class CActorInfoList;

using namespace std;

typedef vector<CActorInfoList *>  CActorInfoListVec;

class DataDriven
{

private:
	static DataDriven *mpInstance;
	
	unsigned int mCurActorIndex = 0;

	CActorInfoListVec mActorInfoListVec;

public:

	void CreateActor();
	CActorInfoList *GetCurActorInfo();
	static DataDriven *GetInstance();

	void SetCurActorInfo(unsigned int tActorInfo);
};