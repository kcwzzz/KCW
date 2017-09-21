// 170706_Lesson_template_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// template04

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>

class Rectangle
{
public :
	Rectangle(T n1, T n2, T n3, T n4)
	{
		left = n1;
		top = n2;
		width = n3;
		height = n4;

	}
	T GetRight()
	{
		return left + width;
	}

	T GetBottom()
	{
		return top + height
	}

	T left, top, width, height;
};

int main()
{
	Rectangle<int> rect1(50, 50, 100, 100);
	cout << rect1.GetRight() << endl;

	Rectangle<double> rect2(50.5, 50.5, 100.1, 100.1);
	cout << rect2.GetRight() << endl;
	   return 0;
}




/*

// 170706_Lesson_template_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//Template01

#include "stdafx.h"
#include <iostream>
using namespace std;

int GetMax(int a, int b)
{
	int buf = 0;
	if (a > b)
	{
		buf = a;
	}
	else
	{
		buf = b;
	}
	return buf;
}

double GetMax(double a, double b)
{
	double buf = 0;
	if (a > b)
	{
		buf = a;
	}
	else
	{
		buf = b;
	}
	return buf;
}

int main()
{

	int n1 = 1, n2 = 3, ret1;
	double r1 = 1.5, r2 = 3.5, ret2;

	ret1 = GetMax(n1, n2);
	ret2 = GetMax(r1, r2);

	cout << "test1 : " << endl;
	cout << ret1 << endl;
	cout << ret2 << endl;

	return 0;
}*/

/*

// 170706_Lesson_template_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// template02

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
T GetMax(T a, T b)
{
	T buf;

	if (a > b)
	{
		buf = a;
	}
	else
		buf = b;

	return buf;
}

int main()
{
	int n1 = 1, n2 = 3, ret1;
	double r1 = 1.5, r2 = 3.5, ret2;

	ret1 = GetMax(n1, n2);
	ret2 = GetMax(r1, r2);

	cout << "test1 : " << endl;
	cout << ret1 << endl;
	cout << ret2 << endl;

	return 0;
}*/

/*
// 170706_Lesson_template_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// template03

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T1, class T2>
T2 GetMax(T1 a, T1 b)
{
	T2 buf;

	if (a > b)
	{
		buf = (T2)a;
	}
	else
		buf = (T2)b;

	return buf;
}

int main()
{
	int n1 = 1, n2 = 31;
	double r1 = 1.5, r2 = 3.5;
	double ret1, ret2;

	ret1 = GetMax<int, double>(n1, n2);
	ret2 = GetMax<double, int>(r1, r2);
	cout << sizeof(ret1) << endl;
	cout << sizeof(ret2) << endl;

	//ret1 = GetMax<int, double>(n1, n2);
	//ret2 = GetMax<double, int>(r1, r2);

	cout << "test1 : " << endl;
	cout << ret1 << endl;
	cout << ret2 << endl;

	return 0;
}
*/