// Example_FSM_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

enum STATE
{
	IDLE = 0, ATTACK = 1
};

class CUnit
{
private:
	STATE mState = STATE::IDLE;

protected:
	void DoIdle();
	void DoAttack();

public:
	void SetState(STATE tState);
	void Execute();

};



void CUnit::CStatus(float mHP)
{
	if (mHP >= 50)
	{
		mState = STATE::ALIVE;
	}
	else if (mHP > 0)
	{
		mState = STATE::WEAK;
	}
	else
	{
		mState = STATE::DEAD;
	}
}
void CUnit::SetState(STATE mState)
{
	switch (mState)
	{
	case ALIVE:
	{
		tAlive();
		break;
	}

	case WEAK:
	{
		tWeak();
		break;
	}
	case DEAD:
	{
		tDead();
		break;
	}
	}
}




int main()
{
	CUnit *tpUnit = NULL;
	tpUnit = new CUnit();

	tpUnit->SetState(STATE::IDLE);
	tpUnit->Execute();

	tpUnit->SetState(STATE::ATTACK);
	tpUnit->Execute();

	if (NULL != tpUnit)
	{
		delete tpUnit;
		tpUnit = NULL;
	}

	return 0;
}

void CUnit::DoIdle()
{
	cout << "DoIdle" << endl;

}

void CUnit::DoAttack()
{
	cout << "DoAttack" << endl;

}

void CUnit::SetState(STATE tState)
{
	mState = tState;
}
void CUnit::Execute()
{
	switch (mState)
	{
	case STATE::IDLE:
	{
		DoIdle();
		break;
	}
	case STATE::ATTACK:
	{
		DoAttack();
		break;
	}
	}

}