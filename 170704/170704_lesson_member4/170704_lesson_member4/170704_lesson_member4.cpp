// 170704_lesson_member4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class OrangeBox4
{
public:
	OrangeBox4(); 
	~OrangeBox4();
	// ������ �Ҹ��� : �Լ�ó�� �۵�
	// ������ �Ҹ��ڴ� ������� �ʾƵ� �����Ϸ��� �����.
};


int main()
{
	OrangeBox4 obox;
	cout << "������ �Ҹ��� ���̸� ������" << endl;

	return 0;
}

OrangeBox4 ::OrangeBox4()
{
	cout << "������Ʈ ������ " << endl;
}

OrangeBox4 :: ~OrangeBox4()
{
	cout << "������Ʈ �Ҹ��" << endl;
}