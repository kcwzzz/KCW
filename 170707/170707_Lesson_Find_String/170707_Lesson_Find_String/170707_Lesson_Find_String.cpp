// 170707_Lesson_Find_String.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include<string>

using namespace std;

int main()
{
	string srcString = "ABCDEFG ȫ�浿 HIJKLMN �浿 OPQRSTU �� VWXYZ";

	cout << "ã�� ���ڿ� �Է� : ";

	string findString;

	getline(cin, findString);
	cout << findString << endl;

	int cnt = 0;
	string::size_type findOffeset = 0;
	while (1)
	{
		findOffeset = srcString.find(findString, findOffeset);
		//���ڰ� ������ scrString ���� find�� ã�´�.
		//

		if (string::npos == findOffeset)
		{
			break;
		}
		cnt++;
		findOffeset++;
	}
	cout << "���ڿ� ( " << findString << " ) �� ���� : " << cnt << endl;
		
		
		return 0;
}

