// 170707_Lesson_Find_String.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include<string>

using namespace std;

int main()
{
	string srcString = "ABCDEFG 홍길동 HIJKLMN 길동 OPQRSTU 동 VWXYZ";

	cout << "찾을 문자열 입력 : ";

	string findString;

	getline(cin, findString);
	cout << findString << endl;

	int cnt = 0;
	string::size_type findOffeset = 0;
	while (1)
	{
		findOffeset = srcString.find(findString, findOffeset);
		//문자가 나열된 scrString 에서 find로 찾는다.
		//

		if (string::npos == findOffeset)
		{
			break;
		}
		cnt++;
		findOffeset++;
	}
	cout << "문자열 ( " << findString << " ) 의 개수 : " << cnt << endl;
		
		
		return 0;
}

