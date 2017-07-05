// 170705_lesson_Inheritance.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Food2
{
private:
	int price1;

protected:
	int price2;

public:
	int price3;

	Food2();//�õ���
};

class Fruit2 :public Food2
{
public:
	void print1()
	{
		//�θ� Ŭ������ private ��� ������ ������ �ȵȴ�.
		//cout << "price1 : " << price1 << endl;
	}

	void print2()
	{
		cout << "price2 : " << price2 << endl;
		//Ŭ���� ������ protected��� �������� ������ ����
		//������ main������ protected��� �������� ���� �Ұ�
	}

	void print3()
	{
		cout << "price3 : " << price3 << endl;
		//public�� ����������� ������ �����ϴ�.
	}
};

int main()
{
	Fruit2 myFruit;

	myFruit.print1();
	myFruit.print2();
	myFruit.print3();

	Food2 myFood;
	//int nP1 = myFood.price1;  // private�� price1���� ������ �ȵȴ�.
	//int nP2 = myFood.price2;  // protect�� price2�� Ŭ������ �ƴ� �������� ������ �ȵȴ�.
	int nP3 = myFood.price3;	// public�� price3�� ��� �������� ������ �����ϴ�.

	cout << "price2 : " << nP3 << endl;
	return 0;
}

Food2 ::Food2()
{
	price1 = 0;
	price2 = 0;
	price3 = 0;
}


/* Exam1 : Inheritance01
class Food1
{
public:
	void print1();
};

class Fruit1 : public Food1
{
public:
	void print2();

	//Fruit1�� Food1�� Ŭ������ ����Ѵ�.
	//����� Fruit1 Ŭ������
	//class Fruit1
	//	{
	//		public :
	//			void print1();
	//			void print2();
	//	} ���� �� �� ����
};

int main()
{
	Fruit1 myFruit;
	myFruit.print1();
	myFruit.print2();

	return 0;
}

void Food1::print1()
{
	cout << "�θ�Ŭ����(���Ŭ����) ����Ʈ : " << endl;
}

void Fruit1::print2()
{
	cout << "�ڽ� Ŭ����(�Ļ�Ŭ����) ����Ʈ : " << endl;
}
*/

