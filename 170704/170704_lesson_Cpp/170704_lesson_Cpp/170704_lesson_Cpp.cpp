// 170704_lesson_Cpp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

//namespace�� ������ְ� �� ���� �Լ��� ���� �ҷ��ͼ� ����Ѵ�.

namespace my1
{
	void SimpleFunc()
	{
		std::cout << "BestCom�� ������ �Լ�" <<std ::endl;

	}
}
namespace my2
{
	void SimpleFunc()
	{
		std::cout << "ProgCom�� ������ �Լ�" << std ::endl;

	}
}

namespace my2
{
	void SimpleFunc_1()
	{
		std::cout << "ProgCom_1�� ������ �Լ�" << std::endl;

	}
}

int main()
{
	my1::SimpleFunc();
	my2::SimpleFunc();
	my2::SimpleFunc_1();

    return 0;
}

