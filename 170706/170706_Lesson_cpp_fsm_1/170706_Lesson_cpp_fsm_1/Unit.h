#pragma once
class CUnit
{
private:
	int mState = 0;

	typedef void(CUnit :: *CallFuncState)(void);
	//타입을 정의
	//CUnit 클래스 내부에 있는 주소

	CallFuncState mArray[2] = { &CUnit::DoIdle, &CUnit::DoAttack };

protected:
	virtual void DoIdle();
	virtual void DoAttack();

public:
	CUnit();
	virtual ~CUnit();

	void SetState(int tState);
	void Execute();
};

