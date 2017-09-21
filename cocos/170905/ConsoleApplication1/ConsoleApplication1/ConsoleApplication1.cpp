// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int gCount = 0;

void binarySearch(int a[], int begin, int end, int key)
{
	int middle;
	gCount++;

	if (begin == end)
	{
		if (key == a[begin])
		{
			cout << gCount << "번째에 검색 성공!" << endl << endl;
		}
		else
		{
			cout << gCount << "번째에 검색 실패!" << endl << endl;
		
		}
		return;
	}

	middle = (begin + end) / 2;

	if (key == a[middle])
	{
		cout << gCount << "번째에 검색 성공!" << endl << endl;

	}
	else if (key < a[middle] && (middle - 1 >= begin))
	{
		binarySearch(a, begin, middle - 1, key);
	}
	else if (key > a[middle] && (middle + 1 <= end))
	{
		binarySearch(a, middle + 1, end, key);
	}
	else
	{
		cout << gCount << "번째에 검색 실패!" << endl << endl;
	}
}




int main()
{
	int a[] = { 1,2,8,9,11,19,29 };
	int key;
	int n = 7;

	gCount = 0;
	key = 29;
	cout << endl << key << " 를 검색하라! ->>";
	binarySearch(a, 0, n - 1, key);


	gCount = 0;
	key = 6;
	cout << endl << key << " 를 검색하라! ->>";
	binarySearch(a, 0, n - 1, key);

	gCount = 0;
	key = 2;
	cout << endl << key << " 를 검색하라! ->>";
	binarySearch(a, 0, n - 1, key);


    return 0;
}

