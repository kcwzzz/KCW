// lesson_20170626_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
//������� : �Լ��� �̸��� ��õǾ�����.
#include <iostream>
using namespace std;

int main()
{
	//�������� : ������ �� �����ǰ� �ش� ������ ���� scope(���⿡�� main�Լ�)�� ���� �� �����
	//int : ����. �ش� �޸𸮸� ������ ������ �ٷ�ڴ� ����
	int tA = 0;
	int tB = 0;
	int tResult = 0;
	
	tA = 2;
	tB = 3;
	
	tResult = tA + tB;

	cout << tResult << endl;

	//���� ���(�����)
	
	//Ű����(�Է���ġ)���� ���� �޾Ƽ� tInput�� ����.
	int tInput = 0;

	//ǥ�� �Է�(Ű����)
	cin >> tInput;
		
    return 0;
}

