// 170704_Lesson_Class_struct.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

class Car
{
//private:
private:
	char gameID[ID_LEN]; // 소유자 ID
	int fuelGauge; // 연료량
	int curSpeed; // guswo threh

public:
	void InitMembers(char *ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
	//public : 어디서든 접근 가능
	//protected : 상속관계에 놓여있을 때, 파생 클래스에서 접근 허용
};

int main()
{
	cout << "EXAM02 : " << endl;

	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	//Car 타입의 함수를 통해서만 멤버변수에 접근이 가능하다. 

	/*
	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	*/
	return 0;
}

void Car ::ShowCarState()
{
	cout << "소유자 ID  : " << gameID << endl;
	cout << "연료량 :   : " << fuelGauge << "%" << endl;
	cout << "현재속도  : " << curSpeed << "km/s" << endl << endl;
}

void Car ::Accel()
{
	if (fuelGauge <= 0)
	{
		return;
	}

	else
	{
		fuelGauge -= FUEL_STEP;
	}

	if (curSpeed + ACC_STEP >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
		return;
	}
	
	curSpeed += ACC_STEP;
}

void Car ::Break()
{
	if (curSpeed < BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= BRK_STEP;
}

void Car::InitMembers(char *ID, int fuel)
{
	strcpy(gameID, ID);
	//strcpy : 문자열 카피 함수
	//ID를 gameID에 복사
	fuelGauge = fuel;
	curSpeed = 0;
}