// 170703_Lesson_LoadSave_File.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{

	FILE *tpFile = NULL;

	int tScore = 0;
	float tX = 0;
	float tY = 0;

	//�÷��� ���� �����͸� �����ߴٰ� ����.
	tScore = 1;
	tX = 240.0f;
	tY = 160.0f;

	// ���� ���� ���� ���� SaceToFile
	fopen_s(&tpFile, "playinfo.sav", "wb");

	fwrite(&tScore, sizeof(int), 1, tpFile);
	fwrite(&tX, sizeof(float), 1, tpFile);
	fwrite(&tY, sizeof(float), 1, tpFile);

	cout << tScore << endl;
	cout << tX << endl;
	cout << tY << endl;
	cout << endl;

	fclose(tpFile);

	int tTestScore = 0;
	float tTestX = 0;
	float tTestY = 0;

	//���� ���� ���� ���� �޸𸮷� �ε� LoadFromFile
	fopen_s(&tpFile, "playinfo.sav", "rb");

	fread(&tTestScore, sizeof(int), 1, tpFile);
	fread(&tTestX, sizeof(int), 1, tpFile);
	fread(&tTestY, sizeof(int), 1, tpFile);

	cout << tTestScore << endl;
	cout << tTestX << endl;
	cout << tTestY << endl;

    return 0;
}

