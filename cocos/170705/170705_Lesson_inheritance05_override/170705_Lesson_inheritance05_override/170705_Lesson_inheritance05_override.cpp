// 170705_Lesson_inheritance05_override.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Food5
{
public :
	void print(int n1);
};

class Fruit5 : public Food5
{
public:
	void print(int n2);

};

int main()
{
	Fruit5 myFruit;

	myFruit.print(10);
	myFruit.Food5::print(10);

    return 0;
}

void Food5 ::print(int n1)
{
	cout << "Food5 : " << n1 << endl;
}

void Fruit5 ::print(int n2)
{
	//Food5::print(n2);		// ���Ⱑ ȣ��Ǹ� ����߰��� �ȴ�.�翬�Ѱ���
	cout << "Fruit5 : " << n2 + 100 << endl;
}
