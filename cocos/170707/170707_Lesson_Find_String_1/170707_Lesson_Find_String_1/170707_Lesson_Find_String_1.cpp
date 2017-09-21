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

	cout << "�ٲ� ���ڿ� �Է� : ";
	string replaceString;
	getline(cin, replaceString);

	cout << "���� ���ڿ� : " << srcString << endl;

	string::size_type Offset = 0; 

	while (1)
	{
		Offset = srcString.find(findString, Offset);
		//���ڰ� ������ scrString ���� find�� ã�´�.
		//

		if (string::npos == Offset)
		{
			break;
		}
		else
		{
			srcString.replace(Offset, findString.length(), replaceString);
			//cout << Offset << endl;
		}
	}
	
	cout << "�ٲ� ���ڿ� : " <<srcString <<  endl;


	return 0;
}

//�������ڿ��� �ٲ﹮�ڿ��� ���̴� ���ƾ��Ѵ�.
/*
1. ���ڿ��� ã�Ƽ� findString�� ���� (ex. '��'�� ã��)
2. �ٲ� ���ڿ��� ã�Ƽ� ReplaceString�� ����(ex. '��'�� �ٲܰ���)
3. string::npos�� string::find()�� ã�� ���ڿ��� �ִ��� �������� �˷��ش�. ������ 1 ������ 0
4. 
*/

