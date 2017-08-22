// 170822_Map.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#include <map>
#include <string>
#include <algorithm>

using namespace std;


/*
대개 균형이진트리( balanced binary tree )를 통해 구현된다.
*/
template<class F, class S>
class CValueEqual
{
private:
	//F first;
	S second;

public:


	/*
	CValueEqual(const F& tF):first(tF)
	{}

	bool operator()(pair<const F, S> tElement)
	{
	return tElement.first == first;
	}
	*/


	CValueEqual(const S& tS) :second(tS)
	{}
	//first( 키 )는 수정불가로 정의되어 있다.
	bool operator()(pair<const F, S> tElement)
	{
		return tElement.second == second;
	}


};




typedef map<int, string> CRyuMap;
//map에 정의된 iterator라는 타입
typedef CRyuMap::iterator CRyuMapItor;

//map에 정의된 value_type이라는 타입
typedef CRyuMap::value_type IsValueType;


int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "STL map\n";


	CRyuMap tMap;
	CRyuMapItor tItor;

	//원소들을 map컨테이너에 삽입할 때는 insert멤버함수를 사용한다. value_type타입의 값들을 넣어야 한다.
	//value_type이 필요한 이유는
	//map컨테이너는 하나의 반복자로 두 개의 항목에 접근해야 하기 때문이다.
	tMap.insert(IsValueType(100, "One Hundred"));
	tMap.insert(IsValueType(3, "Three"));
	tMap.insert(IsValueType(150, "One Hundred Fifty"));
	tMap.insert(IsValueType(99, "Ninety nine"));

	//중복된 키값은 무시함.
	tMap.insert(IsValueType(99, "rrrrrr"));


	//삽입과 동시에 자동으로 정렬한다.

	for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
	{
		cout << "key: " << (*tItor).first << ", ";
		cout << "value: " << (*tItor).second;
		cout << endl;
	}





	cout << tMap[3].c_str() << endl;

	//배열처럼 표기하여 원소에 접근하는 표기의 경우.
	//키값이 없는 것은 에러를 내는 것이 아니라, 새로운 원소를 만든다. 그러므로 반드시 주의하자.
	cout << "tMap[4].c_str(): " << tMap[4].c_str() << endl;

	//물론, 이 성질을 이용하여 새로운 원소를 삽입할 수도 있다.
	tMap[123] = "OneHundred Twenty Three";

	for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
	{
		cout << "key: " << (*tItor).first << ", ";
		cout << "value: " << (*tItor).second;
		cout << endl;
	}







	//이 구문은 키를 검색대상으로 하므로
	//균형이진트리의 검색속도를 따른다.
	//그러므로 검색 속도는 O(log n)이다.
	tItor = tMap.find(123);
	if (tMap.end() != tItor)
	{
		tMap.erase(tItor);
	}


	for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
	{
		cout << "key: " << (*tItor).first << ", ";
		cout << "value: " << (*tItor).second;
		cout << endl;
	}








	//이 구문은 키를 검색대상으로 하지 않고
	//값을 검색대상으로 삼고 있다.
	//그러므로 일일히 모든 원소를 뒤져야 하며
	//그러므로 검색 속도는 O(n)이다.

	//tItor = find_if(tMap.begin(), tMap.end(), CValueEqual<int, string>(99));
	//CValueEqual<int, string>("Ninety nine") 이 부분의 동작은 ()연산자 오버로딩은 구현되었따.
	tItor = find_if(tMap.begin(), tMap.end(), CValueEqual<int, string>("Ninety nine"));

	if (tMap.end() != tItor)
	{
		tMap.erase(tItor);
	}

	cout << "====" << endl;
	for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
	{
		cout << "key: " << (*tItor).first << ", ";
		cout << "value: " << (*tItor).second;
		cout << endl;
	}



	//이 구문은 키를 검색대상으로 하지 않고
	//값을 검색대상으로 삼고 있다.
	//그러므로 일일히 모든 원소를 뒤져야 하며
	//그러므로 검색 속도는 O(n)이다.
	for (tItor = tMap.begin(); tItor != tMap.end();)
	{
		if ("Three" == tItor->second)
		{
			//map의 erase는 다른 컨테이너와는 다르게 동작한다.
			//map의 erase는 리턴값으로 반복자의 다음 위치를 가리키지 않는다.
			//그러므로 순회문안에서 안전한 제거를 위해 해당 구문을 사용하려면, 다음과 같이 처리해야 한다.
			//tItor = tMap.erase( tItor );
			tMap.erase(tItor++);
		}
		else
		{
			++tItor;
		}
	}




	for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
	{
		cout << "key: " << (*tItor).first << ", ";
		cout << "value: " << (*tItor).second;
		cout << endl;
	}


	return 0;
}