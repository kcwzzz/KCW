#pragma once 
// Actor.h는 Unit.h를 포함하고 있다.#pragma once가 중복 컴파일되는 것을 1번만 실행하도록 했다.

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

