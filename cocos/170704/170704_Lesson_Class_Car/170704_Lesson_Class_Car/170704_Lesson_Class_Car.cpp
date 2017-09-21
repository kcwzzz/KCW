// 170704_Lesson_Class_Car.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.

//Exam1 : 구조체를 이용한 자동차의 가속,감속, 연료감소에 대한 내용

#include "stdafx.h"
#include <iostream>

using namespace std;

#define ID_LEN		20		//ID 길이
#define MAX_SPD		200		// 최대 속도
#define FUEL_STEP	2		// 연료 감소량
#define ACC_STEP	10		// 가속 단위
#define BRK_STEP	10		// 감속 단위

//exam 01
struct Car
{
	char gamerID[ID_LEN];		// 소유자 ID
	int fuelGauge;				// 연료량
	int curSpeed;				// 현재속도

};

void ShowCarState(const Car &car);
void Accel(Car &car);
void Break(Car &car);

int main()

{
	cout << "EXAM : " << endl;

	Car run99 = { "run99", 100, 180 };
	ShowCarState(run99);
	Accel(run99);
	Accel(run99);
	Accel(run99);
	Accel(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);

    return 0;
}

void ShowCarState(const Car &car)
{
	cout << "소유자 ID : " << car.gamerID << endl;
	cout << "연료량    : " << car.fuelGauge << endl;
	cout << "현재 속도 : " << car.curSpeed << endl << endl;

}

void Accel(Car &car)
{
	if (car.fuelGauge <= 0)
	{ 
		return;
	}
	else
	{
		car.fuelGauge -= FUEL_STEP;
	}

	if (car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		ShowCarState(car);
		return;
	}

	car.curSpeed += ACC_STEP;
	ShowCarState(car);
}

void Break(Car &car)
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}
	car.curSpeed -= BRK_STEP;
	ShowCarState(car);
}