// Ex_project_call_marvelhero.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		cout << " � ���� ����θ� �θ��ڽ��ϱ�? 1. ĸƾ�Ƹ޸�ī, 2. ���̾��, 9 ���� : ";
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
			cout << "���α׷��� �����մϴ�. ���� �����Ͻðڽ��ϱ�(1: ��, 2: �ƴϿ�)" << endl;
			
			int t_char = 0;
			cin >> t_char;

			if (1 == t_char)
			{
				break;
			}

		}

		else
		{
			cout << " �ٽ� �Է����ּ���. ��༮�� " << endl << endl;
		}
	}

	return 0;


}