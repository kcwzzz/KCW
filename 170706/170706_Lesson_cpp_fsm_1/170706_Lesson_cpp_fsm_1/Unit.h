#pragma once
class CUnit
{
private:
	int mState = 0;

	typedef void(CUnit :: *CallFuncState)(void);
	//Ÿ���� ����
	//CUnit Ŭ���� ���ο� �ִ� �ּ�

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

