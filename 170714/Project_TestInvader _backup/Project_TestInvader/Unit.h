#pragma once
class CUnit
{
protected:
	int mX = 0;
	int mY = 0;
	int mDirX = 0;
	int mDirY = 0;
	int mSpeedPower = 0;

public:
	CUnit();
	~CUnit();

	virtual void Setup(); //������ X,Y ��ǥ
	virtual void Clean(char *tpPixel); // �׷��� Ŭ����
	virtual void Display(char *tpPixel); // �׷��� ǥ��
};

