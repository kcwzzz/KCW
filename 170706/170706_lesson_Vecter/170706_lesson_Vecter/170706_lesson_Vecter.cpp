// 170706_lesson_Vecter.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//Example1_1

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VecInt;

int main()
{
	VecInt tVector;
	
	tVector.reserve(64);

	tVector.resize(5);

	tVector[0] = 12;

//	cout << tVector.size << endl;
	
	int ti = 0;
	for (ti = 0; ti < 10000 ; ti++)
	{
		tVector.push_back(ti);
		cout << tVector[ti] << endl;
	}

	return 0;
}

/*Example1
#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> v1;
	// int형을 저장하는 vector 오브젝트 생성
	// 처음 생성하면 길이는 0임.


	v1.push_back(10);
	v1.push_back(11);



	cout << "요소의 개수 : " << v1.size() << endl;
	cout << "v1[0] : " << v1[0] << endl;
	cout << "v1[1] : " << v1[1] << endl;


	return 0;
}

*/


/*// 170706_lesson_Vecter.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//Example1_1

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> VecInt; //VecInt를 정의

int main()
{
	VecInt tVector;

	tVector.reserve(64); //메모리 예약, 확보, 속도가 조금 더 빨라짐.

	tVector.resize(5); // 배열의 크기를 5개로 만들어 둠. 0으로 초기화
	tVector[0] = 12;

	cout << tVector.size() << endl;

	tVector.push_back(10);
	tVector.push_back(11);
	// 2개를 추가

	cout << tVector.size() << endl;
	//배열이 2개 추가되어서 7개가 됨.

	int ti = 0;
	for (ti = 0; ti < tVector.size(); ti++)
	{
		cout << tVector[ti] << endl;
	}
	}*/