// 170706_Lesson_FSM.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
1. 함수 포인터와 배열을 이용한 FSM
2. 함수 포인터가 클래스 내부에 들어있는 경우 어떻게 해야하는지이다.
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

enum STATE { IDLE = 0, ATTACK = 1 }; // 이렇게 표기한 이유는 클래스 쓰듯이 하고 싶어서 그런듯

class CUnit
{
private:
	STATE mState = STATE::IDLE;
	//STATE mState = IDLE; 도 가능하지만 소속을 명확하게 밝혀주는게 좋당

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