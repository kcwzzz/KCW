// 170705_lesson_Inheritance04.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//Exam4.inheritance04

#include "stdafx.h"
#include <iostream>

using namespace std;

class Food4 //�θ�Ŭ����
{
private:
	int price;

public :
	void SetPrice(int myprice);
};

class Fruit4 : public Food4
{
public:
	void SetPrice2();
};

class Snack4 : public Food4
{
public : 
	void SetPrice2();
};

int main()
{
	Food4 *pFood[2] = {NULL, NULL}; //Food4 Ÿ���� ������ �迭�� 2�� ���� // Food4 class�� �θ�Ŭ����
	//cout << pFood[0] << endl;
	//cout << pFood[1] << endl;
	
	Fruit4 myFruit;					//Fruit4 Ÿ���� myFuit�� ����

	Snack4 mySnack;					//Snack4 Ÿ���� mySnack�� ����


	pFood[0] = &myFruit;			//pFood[0]���� myFruit�� �ּҸ� �־���
	pFood[1] = &mySnack;			//pFood[1]���� mySnack�� �ּҸ� �־���

	for (int i = 0; i <= 1; i++)	// ���� ��ƴ�...

	{
		pFood[i]->SetPrice(100);
	}
	
	return 0;
}

void Food4 :: SetPrice(int myprice)
{
	cout << "Food4 : " << myprice << endl;
	return;
}

void Fruit4 :: SetPrice2()
{
	cout << "Fruit4 : " << endl;
	return;
}

void Snack4::SetPrice2()
{
	cout << "Snack4 : " << endl;
	return;
}