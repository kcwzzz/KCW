// 170703_Lesson_LoadSave_File.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

	//플레이 관련 데이터를 설정했다고 가정.
	tScore = 1;
	tX = 240.0f;
	tY = 160.0f;

	// 이진 모드로 파일 저장 SaceToFile
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

	//이진 모드로 파일 열어 메모리로 로드 LoadFromFile
	fopen_s(&tpFile, "playinfo.sav", "rb");

	fread(&tTestScore, sizeof(int), 1, tpFile);
	fread(&tTestX, sizeof(int), 1, tpFile);
	fread(&tTestY, sizeof(int), 1, tpFile);

	cout << tTestScore << endl;
	cout << tTestX << endl;
	cout << tTestY << endl;

    return 0;
}

