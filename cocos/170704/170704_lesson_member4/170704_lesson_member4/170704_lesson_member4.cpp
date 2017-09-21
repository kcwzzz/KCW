// 170704_lesson_member4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class OrangeBox4
{
public:
	OrangeBox4(); 
	~OrangeBox4();
	// 생성자 소멸자 : 함수처럼 작동
	// 생성자 소멸자는 명시하지 않아도 컴파일러가 만든다.
};


int main()
{
	OrangeBox4 obox;
	cout << "생성자 소멸자 사이를 끼어들기" << endl;

	return 0;
}

OrangeBox4 ::OrangeBox4()
{
	cout << "오브젝트 생성됨 " << endl;
}

OrangeBox4 :: ~OrangeBox4()
{
	cout << "오브젝트 소멸됨" << endl;
}