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