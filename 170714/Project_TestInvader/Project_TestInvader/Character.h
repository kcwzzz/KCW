#pragma once
#include "Unit.h"

class CCharacter : public CUnit 
{
protected:
	int mCurBulletIndex = 0;

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