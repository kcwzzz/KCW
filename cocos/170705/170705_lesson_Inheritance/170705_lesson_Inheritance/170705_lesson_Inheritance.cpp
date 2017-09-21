// 170705_lesson_Inheritance.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

	Food2();//시동자
};

class Fruit2 :public Food2
{
public:
	void print1()
	{
		//부모 클래스의 private 멤버 변수에 접근은 안된다.
		//cout << "price1 : " << price1 << endl;
	}

	void print2()
	{
		cout << "price2 : " << price2 << endl;
		//클래스 내에서 protected멤버 변수에는 접근이 가능
		//하지만 main에서는 protected멤버 변수에는 접근 불가
	}

	void print3()
	{
		cout << "price3 : " << price3 << endl;
		//public은 어느곳에서든 접근이 가능하다.
	}
};

int main()
{
	Fruit2 myFruit;

	myFruit.print1();
	myFruit.print2();
	myFruit.print3();

	Food2 myFood;
	//int nP1 = myFood.price1;  // private인 price1에는 접근이 안된다.
	//int nP2 = myFood.price2;  // protect인 price2는 클래스가 아닌 곳에서는 접근이 안된다.
	int nP3 = myFood.price3;	// public인 price3는 어느 곳에서든 접근이 가능하다.

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

	//Fruit1는 Food1의 클래스를 상속한다.
	//실재로 Fruit1 클래스는
	//class Fruit1
	//	{
	//		public :
	//			void print1();
	//			void print2();
	//	} 으로 볼 수 있음
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
	cout << "부모클래스(기반클래스) 프린트 : " << endl;
}

void Fruit1::print2()
{
	cout << "자식 클래스(파생클래스) 프린트 : " << endl;
}
*/

