#pragma once 
// Actor.h�� Unit.h�� �����ϰ� �ִ�.#pragma once�� �ߺ� �����ϵǴ� ���� 1���� �����ϵ��� �ߴ�.

#include "Unit.h"

class CActor : public CUnit
{
protected:
	virtual void DoIdle();
	virtual void DoAttack();

public:
	CActor();
	virtual ~CActor();
};

