// 170705_Lesson_Inheritance06.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//�������� ���ʵȴ�. ���� �޽����� ���ؼ� �ٸ� �ൿ�� �Ѵ�.
// Food6������ �׳� ���
// Fruit6�� ���ؼ��� 100�� ���ؼ� ���
// �� ������ ���� �ָ���.

#include "stdafx.h"
#include <iostream>

using namespace std;

class Food6
{
public:
	virtual void print(int n);
};

class Fruit6 : public Food6
{
public : 
	void print(int n);

};

int main()
{
	Food6 *pFood;
	Fruit6 myFruit;
	pFood = &myFruit;
	pFood->print(100);
    return 0;
}

void Food6::print(int n)
{
	cout << "print : " << n << endl;
}

void Fruit6::print(int n)
{
	Food6::print(n + 100);
}