// 170706_Lesson_FSM.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

/*

*/
#include "stdafx.h"
#include <iostream>

using namespace std;
/*
class name : CUnit
int mState
pointer function name : CallFuncState
Array name : mArray[2]

*/
class CUnit
{
private :
	int mState = 0;
	typedef void(CUnit :: *CallFuncState)(void);

	CallFuncState mArray[2] = { &CUnit::DoIdle, &CUnit::DoAttack };

protected:
	void DoIdle();
	void DoAttack();

public : 
	void SetState(int tState);
	void Execute();

};

/*
1. �Լ� �����Ϳ� �迭�� �̿��� FSM
2. �Լ� �����Ͱ� Ŭ���� ���ο� ����ִ� ��� ��� �ؾ��ϴ����̴�.
*/
int main()
{
	CUnit *tpUnit = NULL;
	tpUnit = new CUnit;

	tpUnit->SetState(0);
	tpUnit->Execute();
	
	tpUnit->SetState(1);
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
	cout << "Do ATTACK" << endl;

}

void CUnit::SetState(int tState)
{
	mState = tState;
}

void CUnit::Execute()
{	
	(this->*mArray[mState])();
}


/*

#include "stdafx.h"
#include <iostream>

using namespace std;

enum STATE { IDLE = 0, ATTACK = 1 }; // �̷��� ǥ���� ������ Ŭ���� ������ �ϰ� �; �׷���

class CUnit
{
private:
	STATE mState = STATE::IDLE;
	//STATE mState = IDLE; �� ���������� �Ҽ��� ��Ȯ�ϰ� �����ִ°� ����

protected:
	void DoIdle();
	void DoAttack();

public:
	void SetState(STATE tState);
	void Execute();
};

int main()
{
	CUnit *tpUnit = NULL;
	tpUnit = new CUnit;

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
	cout << "Do ATTACK" << endl;

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
	}
	break;

	case STATE::ATTACK:
	{
		DoAttack();
	}
	break;
	}

}
*/