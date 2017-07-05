// 170705_lesson_Inheritance04.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//Exam4.inheritance04

#include "stdafx.h"
#include <iostream>

using namespace std;

class Food4 //부모클래스
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
	Food4 *pFood[2] = {NULL, NULL}; //Food4 타입의 포인터 배열을 2개 만듬 // Food4 class는 부모클래스
	//cout << pFood[0] << endl;
	//cout << pFood[1] << endl;
	
	Fruit4 myFruit;					//Fruit4 타입의 myFuit을 생성

	Snack4 mySnack;					//Snack4 타입의 mySnack을 생성


	pFood[0] = &myFruit;			//pFood[0]에는 myFruit의 주소를 넣어줌
	pFood[1] = &mySnack;			//pFood[1]에는 mySnack의 주소를 넣어줌

	for (int i = 0; i <= 1; i++)	// 뭔가 어렵다...

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