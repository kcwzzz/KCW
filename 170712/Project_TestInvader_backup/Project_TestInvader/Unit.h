#pragma once

class CUnit
{
protected:
	float mX = 0;
	float mY = 0;
	float mDirX = 0;
	float mDirY = 0;
	
public:
	virtual void Setup() = 0; //���� ���� �Լ�
	//virtual void Clean(char *tpPixel); // �׷��� Ŭ����
	//virtual void Display(char *tpPixel); // �׷��� ǥ��

	CUnit();
	virtual ~CUnit();

};