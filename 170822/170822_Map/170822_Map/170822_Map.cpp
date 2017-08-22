// 170822_Map.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

#include <map>
#include <string>
#include <algorithm>

using namespace std;


/*
�밳 ��������Ʈ��( balanced binary tree )�� ���� �����ȴ�.
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
	//first( Ű )�� �����Ұ��� ���ǵǾ� �ִ�.
	bool operator()(pair<const F, S> tElement)
	{
		return tElement.second == second;
	}


};




typedef map<int, string> CRyuMap;
//map�� ���ǵ� iterator��� Ÿ��
typedef CRyuMap::iterator CRyuMapItor;

//map�� ���ǵ� value_type�̶�� Ÿ��
typedef CRyuMap::value_type IsValueType;


int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "STL map\n";


	CRyuMap tMap;
	CRyuMapItor tItor;

	//���ҵ��� map�����̳ʿ� ������ ���� insert����Լ��� ����Ѵ�. value_typeŸ���� ������ �־�� �Ѵ�.
	//value_type�� �ʿ��� ������
	//map�����̳ʴ� �ϳ��� �ݺ��ڷ� �� ���� �׸� �����ؾ� �ϱ� �����̴�.
	tMap.insert(IsValueType(100, "One Hundred"));
	tMap.insert(IsValueType(3, "Three"));
	tMap.insert(IsValueType(150, "One Hundred Fifty"));
	tMap.insert(IsValueType(99, "Ninety nine"));

	//�ߺ��� Ű���� ������.
	tMap.insert(IsValueType(99, "rrrrrr"));


	//���԰� ���ÿ� �ڵ����� �����Ѵ�.

	for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
	{
		cout << "key: " << (*tItor).first << ", ";
		cout << "value: " << (*tItor).second;
		cout << endl;
	}





	cout << tMap[3].c_str() << endl;

	//�迭ó�� ǥ���Ͽ� ���ҿ� �����ϴ� ǥ���� ���.
	//Ű���� ���� ���� ������ ���� ���� �ƴ϶�, ���ο� ���Ҹ� �����. �׷��Ƿ� �ݵ�� ��������.
	cout << "tMap[4].c_str(): " << tMap[4].c_str() << endl;

	//����, �� ������ �̿��Ͽ� ���ο� ���Ҹ� ������ ���� �ִ�.
	tMap[123] = "OneHundred Twenty Three";

	for (tItor = tMap.begin(); tItor != tMap.end(); ++tItor)
	{
		cout << "key: " << (*tItor).first << ", ";
		cout << "value: " << (*tItor).second;
		cout << endl;
	}







	//�� ������ Ű�� �˻�������� �ϹǷ�
	//��������Ʈ���� �˻��ӵ��� ������.
	//�׷��Ƿ� �˻� �ӵ��� O(log n)�̴�.
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








	//�� ������ Ű�� �˻�������� ���� �ʰ�
	//���� �˻�������� ��� �ִ�.
	//�׷��Ƿ� ������ ��� ���Ҹ� ������ �ϸ�
	//�׷��Ƿ� �˻� �ӵ��� O(n)�̴�.

	//tItor = find_if(tMap.begin(), tMap.end(), CValueEqual<int, string>(99));
	//CValueEqual<int, string>("Ninety nine") �� �κ��� ������ ()������ �����ε��� �����Ǿ���.
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



	//�� ������ Ű�� �˻�������� ���� �ʰ�
	//���� �˻�������� ��� �ִ�.
	//�׷��Ƿ� ������ ��� ���Ҹ� ������ �ϸ�
	//�׷��Ƿ� �˻� �ӵ��� O(n)�̴�.
	for (tItor = tMap.begin(); tItor != tMap.end();)
	{
		if ("Three" == tItor->second)
		{
			//map�� erase�� �ٸ� �����̳ʿʹ� �ٸ��� �����Ѵ�.
			//map�� erase�� ���ϰ����� �ݺ����� ���� ��ġ�� ����Ű�� �ʴ´�.
			//�׷��Ƿ� ��ȸ���ȿ��� ������ ���Ÿ� ���� �ش� ������ ����Ϸ���, ������ ���� ó���ؾ� �Ѵ�.
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