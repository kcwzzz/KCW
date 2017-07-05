// 170705_Lesson_inheritance07.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Food7
{
public:
	virtual void print(int n) = 0;//순수 가상 함수
};

class Fruit7 : public Food7
{
public : 
	void print(int n); // 순수 가상함수의 재정의(Overriding)
};

class Fish7 : public Food7
{
public:
	void print(int n);
};

int main()
{
	Fruit7 myFruit;
	myFruit.print(5);

	Fish7 myFish;
	myFish.print(5);

    return 0;
}

void Fruit7::print(int n)
{
	cout << (n + 100) << endl;
}

void Fish7::print(int n)
{
	cout << (n + 200) << endl;
}

