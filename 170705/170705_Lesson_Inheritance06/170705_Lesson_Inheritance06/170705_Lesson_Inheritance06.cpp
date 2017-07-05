// 170705_Lesson_Inheritance06.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//다형성이 기초된다. 같은 메시지에 대해서 다른 행동을 한다.
// Food6에서는 그냥 출력
// Fruit6에 대해서는 100을 더해서 출력
// 이 예제는 조금 애매함.

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