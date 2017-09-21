// Ex_project_call_marvelhero.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int tInput = 0;
	int ti = 0;

	while (1)
	{
		cout << " 어떤 마블 히어로를 부르겠습니까? 1. 캡틴아메리카, 2. 아이언맨, 9 종료 : ";
		cin >> tInput;


		if (1 == tInput)
		{
			for (ti = 0; ti < 5; ti++)
			{
				cout << "Call Captain America!!" << endl;
			}
		}
		else if (2 == tInput)
		{
			for (int tj = 0; tj < 3; tj++)
			{
				cout << "Call Iron Man!!" << endl;

			}
		}

		else if (9 == tInput)
		{
			cout << "프로그램을 종료합니다. 정말 종료하시겠습니까(1: 예, 2: 아니요)" << endl;
			
			int t_char = 0;
			cin >> t_char;

			if (1 == t_char)
			{
				break;
			}

		}

		else
		{
			cout << " 다시 입력해주세요. 요녀석아 " << endl << endl;
		}
	}

	return 0;


}