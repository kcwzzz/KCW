// 170706_lesson_Vecter.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	// int���� �����ϴ� vector ������Ʈ ����
	// ó�� �����ϸ� ���̴� 0��.


	v1.push_back(10);
	v1.push_back(11);



	cout << "����� ���� : " << v1.size() << endl;
	cout << "v1[0] : " << v1[0] << endl;
	cout << "v1[1] : " << v1[1] << endl;


	return 0;
}

*/


/*// 170706_lesson_Vecter.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//Example1_1

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> VecInt; //VecInt�� ����

int main()
{
	VecInt tVector;

	tVector.reserve(64); //�޸� ����, Ȯ��, �ӵ��� ���� �� ������.

	tVector.resize(5); // �迭�� ũ�⸦ 5���� ����� ��. 0���� �ʱ�ȭ
	tVector[0] = 12;

	cout << tVector.size() << endl;

	tVector.push_back(10);
	tVector.push_back(11);
	// 2���� �߰�

	cout << tVector.size() << endl;
	//�迭�� 2�� �߰��Ǿ 7���� ��.

	int ti = 0;
	for (ti = 0; ti < tVector.size(); ti++)
	{
		cout << tVector[ti] << endl;
	}
	}*/