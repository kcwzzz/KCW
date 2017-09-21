// 170704_lesson_member5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class OrangeBox5
{

private:
	int total;

public:
	OrangeBox5();
	OrangeBox5(int n);
	void GetTotal();
};

int main()
{
	OrangeBox5 obox1;
	obox1.GetTotal();

	OrangeBox5 obox2(10);
	obox2.GetTotal();

	OrangeBox5 *obox3 = new OrangeBox5();
	obox3->GetTotal();

	OrangeBox5 *obox4 = new OrangeBox5(10);
	obox4->GetTotal();

    return 0;
}

OrangeBox5::OrangeBox5()
{
	cout << "오브젝트 생성됨 51" << endl<<endl;
	total = 0;
}

OrangeBox5::OrangeBox5(int n)
{
	cout << "오브젝트 생성됨 52" << endl<<endl;
	total = n;
}
void OrangeBox5 ::GetTotal()// [class이름 :: 함수이름] 로 정의해야한다. ㅠㅠ
{
	cout << "total : " << total << endl<<endl;
}