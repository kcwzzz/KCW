// 170704_lesson_Cpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

//namespace를 만들어주고 그 안의 함수와 값을 불러와서 사용한다.

namespace my1
{
	void SimpleFunc()
	{
		std::cout << "BestCom이 정의한 함수" <<std ::endl;

	}
}
namespace my2
{
	void SimpleFunc()
	{
		std::cout << "ProgCom이 정의한 함수" << std ::endl;

	}
}

namespace my2
{
	void SimpleFunc_1()
	{
		std::cout << "ProgCom_1이 정의한 함수" << std::endl;

	}
}

int main()
{
	my1::SimpleFunc();
	my2::SimpleFunc();
	my2::SimpleFunc_1();

    return 0;
}

