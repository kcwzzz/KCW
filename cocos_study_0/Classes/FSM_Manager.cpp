#include "FSM_Manager.h"
#include "Define.h"

using namespace cocos2d;


FSM_Manager *FSM_Manager::mpInstance = NULL;

FSM_Manager *FSM_Manager::Getinstance()
{
	if (NULL == mpInstance)
	{
		mpInstance = new FSM_Manager();
		return mpInstance;
	}

	return mpInstance;
}

int FSM_Manager::GetNowState()
{
	return mActorState;
}

void FSM_Manager::SetNowState(int tNowState)
{
	mActorState = tNowState;
}

int FSM_Manager::GetLevel()
{
	return mActorLevel;
}	

void FSM_Manager::SetLevel(int tLevel)
{
	mActorLevel = tLevel;
}

int FSM_Manager::GetCurSP()
{
	return mCurSP;
}

void FSM_Manager::SetCurSP(int tCurSP)
{
	mCurSP += tCurSP;
}