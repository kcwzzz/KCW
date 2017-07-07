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

	cout << "바꿀 문자열 입력 : ";
	string replaceString;
	getline(cin, replaceString);

	cout << "원본 문자열 : " << srcString << endl;

	string::size_type Offset = 0; 

	while (1)
	{
		Offset = srcString.find(findString, Offset);
		//문자가 나열된 scrString 에서 find로 찾는다.
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
	
	cout << "바뀐 문자열 : " <<srcString <<  endl;


	return 0;
}

//원본문자열과 바뀐문자열의 길이는 같아야한다.
/*
1. 문자열을 찾아서 findString에 저장 (ex. '동'을 찾음)
2. 바꿀 문자열을 찾아서 ReplaceString에 저장(ex. '꿀'로 바꿀거임)
3. string::npos는 string::find()로 찾은 문자열이 있는지 없는지를 알려준다. 있으면 1 없으면 0
4. 
*/

