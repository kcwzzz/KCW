#pragma once

#include <stdio.h>
#include <vector>

using namespace std;

class CActorStatus;

typedef vector<CActorStatus *> CActorStatusVec;

class CActorInfoList
{

public :

	CActorStatusVec mActorStatusVec;

	unsigned int mId = 0;

	string mImageFileName;

};