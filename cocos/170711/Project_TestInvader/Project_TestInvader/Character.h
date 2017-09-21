#pragma once
#include "Unit.h"

class CCharacter : public CUnit 
{
protected:
	int mCurBulletIndex = 0;
	/*
	int mX = 0;
	int mY = 0;

	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;
	*/

public:
	CCharacter();
	~CCharacter();

	virtual void Setup(); //������ X,Y ��ǥ
	virtual void MoveWithInput(); //����
	virtual void Clean(char *tpPixel); // �׷��� Ŭ����
	virtual void Display(char *tpPixel); // �׷��� ǥ��
	
	int GetX();
	int GetY();
};