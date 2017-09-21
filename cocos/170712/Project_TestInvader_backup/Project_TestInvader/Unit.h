#pragma once

class CUnit
{
protected:
	float mX = 0;
	float mY = 0;
	float mDirX = 0;
	float mDirY = 0;
	float mSpeedPower = 0;
	
public:
	virtual void Setup(); //���� ���� �Լ�
	virtual void Display(char *tpPixel); // �׷��� ǥ��
	virtual void Clean(char *tpPixel); // �׷��� Ŭ����

	CUnit();
	virtual ~CUnit();
};