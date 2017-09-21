#pragma once
class CUnit
{
protected :
	bool mIsLive = false;

	int mX = 0;
	int mY = 0;

	int mDir = 0;

public:
	CUnit();
	virtual ~CUnit();

	bool IsAlive();
	void SetAlive(bool tIsLive);

	void Display();
};

