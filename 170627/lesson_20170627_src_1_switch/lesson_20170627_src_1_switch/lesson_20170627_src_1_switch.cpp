// lesson_20170627_src_1_switch.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	float tA = 3;
	float tB = 2;
	float tResult = 0;
	int tSelectOperator = 1;

	cout << "input tA : ";
	cin >> tA;

	cout << "input tB : ";
	cin >> tB;


	cout << endl<<  "�����ڸ� �Է����ּ���. ���ϱ�(1), ����(2), ���ϱ�(3), ������(4)";
	cin >> tSelectOperator;

	//Break�� �Է����� ������, Break�� ���� ������ �� �����ϴϴ�.
	//���� switch �������� break�� ���� ������, ������ ��� ����մϴ�.
	//�������� ������ �ۼ��ڰ� ������ ������ϰ�, ���α׷��� ������ �Ǵ����� ����.
	switch (tSelectOperator)
	{
	case 1:
	{
		tResult = tA + tB;
		cout << "Addictaive : " << tResult << endl;
	}
	break;

	case 2:
	{
		tResult = tA - tB;
		cout << "Subtract : " << tResult << endl;

	}
	break;

	case 3:
	{
		tResult = tA*tB;
		cout << "Multiply : " << tResult << endl;

	}
	break;

	case 4:
	{
		tResult = tA / tB;
		cout << "Divide : " << tResult << endl;
	}
	break;

	default:
	{
		cout << "�߸��� �����ڸ� �Է��Ͽ����ϴ�." << endl;
	}
	break;
	}

    return 0;
}

