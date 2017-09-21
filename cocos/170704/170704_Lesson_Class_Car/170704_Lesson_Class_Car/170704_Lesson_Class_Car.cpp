// 170704_Lesson_Class_Car.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.

//Exam1 : ����ü�� �̿��� �ڵ����� ����,����, ���ᰨ�ҿ� ���� ����

#include "stdafx.h"
#include <iostream>

using namespace std;

#define ID_LEN		20		//ID ����
#define MAX_SPD		200		// �ִ� �ӵ�
#define FUEL_STEP	2		// ���� ���ҷ�
#define ACC_STEP	10		// ���� ����
#define BRK_STEP	10		// ���� ����

//exam 01
struct Car
{
	char gamerID[ID_LEN];		// ������ ID
	int fuelGauge;				// ���ᷮ
	int curSpeed;				// ����ӵ�

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
	cout << "������ ID : " << car.gamerID << endl;
	cout << "���ᷮ    : " << car.fuelGauge << endl;
	cout << "���� �ӵ� : " << car.curSpeed << endl << endl;

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