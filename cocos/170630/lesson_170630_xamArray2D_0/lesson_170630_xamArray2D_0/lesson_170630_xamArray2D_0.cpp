// lesson_170630_xamArray2D_0.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


//����ü, �Լ��� �ڵ� ������ ������ �Ǿ ����
//��, ������ �����߿� ����ϴ� ���̰�, �ڵ�� �������Ͽ� �����ִ� ���̴�.

struct SRectangle
{
	int mLeft = 0;
	int mTop = 0;
	int mRight = 0;
	int mBottom = 0;

	int mArea = 0;
};

int main()
{
	int *tpA = NULL;
	tpA = new int();

	SRectangle *tpRectangle = NULL;
	tpRectangle = new SRectangle();

	if (NULL != tpRectangle)
	{
		delete tpRectangle;
		tpRectangle = NULL;
	}

	if (NULL != tpA)
	{
		delete tpA;
		tpA = NULL;
	}

    return 0;
}

