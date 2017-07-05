// 170705_Lesson_inheritance05_override.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	//Food5::print(n2);		// 여기가 호출되면 기능추가가 된다.당연한거지
	cout << "Fruit5 : " << n2 + 100 << endl;
}
