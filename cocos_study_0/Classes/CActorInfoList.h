#pragma once

#include <stdio.h>
#include <vector>

using namespace std;

class CActorStatus;
class CActorImage;
class CAttackImage;


typedef vector<CActorStatus *> CActorStatusVec;
typedef vector<CActorImage *> CActorImageVec;
typedef vector<CAttackImage *> CAttackImageVec;

class CActorInfoList
{

public :
	unsigned int mId = 0;

	CActorStatusVec mActorStatusVec;
	CActorImageVec mActorImageVec;
	CAttackImageVec mAttackImageVec;

};