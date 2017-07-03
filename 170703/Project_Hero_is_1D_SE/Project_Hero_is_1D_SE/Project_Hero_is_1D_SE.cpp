// Project_Hero_is_1D_SE.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h >
#include <time.h>

using namespace std;

struct SCharacter
{
	int mX = 0;
	float mHP = 0;
	float mAP = 0;
};

void DoMoveFuction(char tMoveDir, SCharacter *tpHero);
void EventMoveHero(int tAttrib, SCharacter *tpHero, SCharacter *tpSlime, SCharacter *tpKingSlime);
void DoBattleSlime(char tRollDice, SCharacter *tpHero, SCharacter *tpSlime);
void DoBattleKingSlime(int tHero_RSP, SCharacter *tpHero, SCharacter *tpKingSlime);

int main()
{
	srand((unsigned int)time(NULL));

	int tWorld[5] = { 0,0,1,0,2 };

	SCharacter *tpHero = NULL;
	tpHero = new SCharacter();
	tpHero->mX = 0;
	tpHero->mHP = 200;
	tpHero->mAP = 90;

	SCharacter *tpSlime = NULL;
	tpSlime = new SCharacter();
	tpSlime->mX = 2;
	tpSlime->mHP = 100;
	tpSlime->mAP = 10;

	SCharacter *tpKingSlime;
	tpKingSlime = new SCharacter();

	tpKingSlime->mX = 4;
	tpKingSlime->mHP = 200;
	tpKingSlime->mAP = 20;

	//오프닝
	cout << "========================================" << endl;
	cout << "==============용사는 1차원==============" << endl;
	cout << "========================================" << endl;
	cout << endl;


	char tGameStart = 0;
	cout << "게임을 시작하시겠습니까?(y/n)";
	cin >> tGameStart;

	//게임 루프
	while ('y' == tGameStart)
	{
		while (1)
		{
			//////////////////맵 이동 기능/////////////////////////////
			char tMoveDir = 'd';
			cout << "이동하시겠습니까??(왼쪽 : a, 오른쪽 : d) : ";
			cin >> tMoveDir;
			
			DoMoveFuction(tMoveDir, tpHero); //이동 함수

			/////////////////매칭 및 전투 기능/////////////////////////
			//맵 배열의 숫자 
			//0 : 이벤트 없음
			//1 : 슬라임 이벤트  - 주사위
			//2 : 킹 슬라임 이벤트 - 가위바위보
			
			int tAttrib = tWorld[tpHero->mX];

			EventMoveHero(tAttrib, tpHero, tpSlime, tpKingSlime); //이벤트 함수

			if (0 >= tpHero->mHP)
			{
				break;
			}

			else if (0 >= tpKingSlime->mHP)
			{
				break;
			}
		}

		if (0 >= tpHero->mHP)
		{
			cout << "GAME OVER" << endl << endl;
			break;
		}

		else if (0 >= tpKingSlime->mHP)
		{
			cout << "보스를 물리쳤다. 세상이 평화로워졌다." << endl << endl;
			break;
		}
	}

	//게임 종료
	cout << "용사는 1차원을 종료합니다." << endl << endl;

	//
	if (NULL != tpKingSlime)
	{
		delete tpKingSlime;
		tpKingSlime = NULL;
	}

	if (NULL != tpSlime)
	{
		delete tpSlime;
		tpSlime = NULL;
	}

	if (NULL != tpHero)
	{
		delete tpHero;
		tpHero = NULL;
	}

	return 0;
}

//버그 1 : 슬라임을 물리치고 앞으로 갔다 돌아와서 만나면 슬라임의 체력이 0인 상태

//1. 맵 이동 함수 
void DoMoveFuction(char tMoveDir, SCharacter *tpHero)
{
	// 좌로 이동 기능
	if ('a' == tMoveDir)
	{
		if (tpHero->mX > 0)
		{
			tpHero->mX = tpHero->mX - 1;
			cout << "<<-- 왼쪽으로 이동합니다." << endl;
		}
		else
		{
			cout << "더 이상 왼쪽으로 이동할 수 없습니다." << endl;
		}
	}
	// 우로 이동 기능

	else if ('d' == tMoveDir)
	{
		if (tpHero->mX < 4)
		{
			tpHero->mX = tpHero->mX + 1;
			cout << "-->> 오른쪽으로 이동합니다." << endl;

		}
		else
		{
			cout << "더 이상 오른쪽으로 이동할 수 없습니다." << endl;
		}
	}
	// 잘못된 입력
	else
	{
		cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
	}

	return;
}

//2. 용사의 위치별 이벤트 발생(0 : 아무일 없음. 1: 슬라임 전투(주사위) 2:킹슬라임 전투(가위바위보)
void EventMoveHero(int tAttrib, SCharacter *tpHero, SCharacter *tpSlime, SCharacter *tpKingSlime)
{
	//맵 배열의 숫자 
	//0 : 이벤트 없음
	//1 : 슬라임 이벤트  - 주사위
	//2 : 킹 슬라임 이벤트 - 가위바위보
	
	switch (tAttrib)
	{
	
	case 0: //아무도 없어서 이벤트 없음.
	{
		cout << "용사는 " << tpHero->mX << "타일에 있습니다." << endl;
		cout << "아무도 없습니다. " << endl;
		break; // case0을 브레이크
	}


	case 1:  // 슬라임 조우 및 주사위 이벤트
	{
		cout << "용사는 " << tpHero->mX << "타일에 있습니다." << endl;
		cout << "슬라임과 만났습니다. 전투를 시작합니다." << endl;

		char tRollDice = 'r';

		while (1)
		{
			cout << "[ r ] 버튼을 눌러 주사위를 던져주세요 : ";
			cin >> tRollDice;
			cout << endl;

			DoBattleSlime(tRollDice, tpHero, tpSlime); //슬라임 전투 진행(주사위)

			if (0 >= tpHero->mHP)
			{
				cout << "용사의 죽음 " << endl;
				break;
			}

			else if (0 >= tpSlime->mHP)
			{
				cout << "용사는 슬라임을 물리쳤다." << endl << endl;
				break;
			}
		}

		break;// case1을 브레이크
	}

	// 킹 슬라임 조우 및 가위바위보 이벤트
	case 2:
	{
		cout << "용사는 " << tpHero->mX << "타일에 있습니다." << endl;
		cout << "킹 슬라임과 만났습니다. 전투를 시작합니다. " << endl << endl;

		int tHero_RSP = 0;

		while (1)
		{
			cout << "가위바위보 게임을 합니다. [0 : 가위, 1 : 바위. 2 : 보]";
			cin >> tHero_RSP;

			DoBattleKingSlime(tHero_RSP, tpHero, tpKingSlime);

			if (0 >= tpHero->mHP)
			{
				cout << "용사의 죽음 " << endl;
				break;
			}

			else if (0 >= tpKingSlime->mHP)
			{
				cout << "용사는 킹 슬라임을 물리쳤다." << endl << endl;
				break;
			}
		}
		break;// case2를 브레이크
	}
	}

}

//3. 슬라임 전투(주사위)
void DoBattleSlime(char tRollDice, SCharacter *tpHero, SCharacter *tpSlime)
{
	if ('r' == tRollDice)
	{
		//주사위 값을 얻음.
		int tDiceNumber = rand() % 6 + 1;

		switch (tDiceNumber)
		{
		case 1:
		case 2:
		case 3:
		{
			cout << "슬라임의 공격!!" << endl;
			cout << "용사가 " << tpSlime->mAP << "의 피해를 입었습니다." << endl;
			tpHero->mHP = tpHero->mHP - tpSlime->mAP;
			cout << "용사의 체력이 " << tpHero->mHP << "만큼 남았습니다. " << endl << endl;
			break;
		}
		case 4:
		case 5:
		case 6:
		{
			cout << "용사의 공격!!" << endl;
			cout << "슬라임이 " << tpHero->mAP << "의 피해를 입었습니다." << endl;
			tpSlime->mHP = tpSlime->mHP - tpHero->mAP;

			cout << "슬라임의 체력이 " << tpSlime->mHP << "만큼 남았습니다. " << endl << endl;

			break;
		}
		}
	}

}

//4. 킹 슬라임 전투(가위바위보)
void DoBattleKingSlime(int tHero_RSP, SCharacter *tpHero, SCharacter *tpKingSlime)
{
	int tKingSlime_RSP = rand() % 3;

	if (tHero_RSP = 0) // 용사가 가위일 때
	{
		switch (tKingSlime_RSP)
		{
		case 0://킹 슬라임이 가위
		{
			cout << "용사 : 가위" << endl;
			cout << "킹 슬라임 : 가위" << endl;
			cout << "무승부입니다." << endl << endl;
			break;
		}

		case 1://킹 슬라임이 바위
		{
			cout << "용사 : 가위" << endl;
			cout << "킹 슬라임 : 바위" << endl;
			cout << "용사의 패배." << endl << endl;

			tpHero->mHP = tpHero->mHP - tpKingSlime->mAP;

			cout << "킹 슬라임의 공격!!" << endl;
			cout << "용사가 " << tpKingSlime->mAP << "의 피해를 입었습니다." << endl;
			cout << "용사의 체력이 " << tpHero->mHP << "만큼 남았습니다. " << endl << endl;

			break;
		}

		case 2://킹 슬라임이 보
		{
			cout << "용사 : 가위" << endl;
			cout << "킹 슬라임 : 보" << endl;
			cout << "용사의 승리." << endl << endl;

			tpKingSlime->mHP = tpKingSlime->mHP - tpHero->mAP;

			cout << "용사의 공격!!" << endl;
			cout << "슬라임이 " << tpHero->mAP << "의 피해를 입었습니다." << endl;
			cout << "슬라임의 체력이 " << tpKingSlime->mHP << "만큼 남았습니다. " << endl << endl;

			break;
		}
		}
	}

	else if (tHero_RSP = 1)
	{
		switch (tKingSlime_RSP)
		{
		case 0:
		{
			cout << "용사 : 바위" << endl;
			cout << "킹 슬라임 : 가위" << endl;
			cout << "용사의 승리." << endl << endl;

			tpKingSlime->mHP = tpKingSlime->mHP - tpHero->mAP;

			cout << "용사의 공격!!" << endl;
			cout << "슬라임이 " << tpHero->mAP << "의 피해를 입었습니다." << endl;
			cout << "슬라임의 체력이 " << tpKingSlime->mHP << "만큼 남았습니다. " << endl << endl;

			break;
		}

		case 1:
		{
			cout << "용사 : 바위" << endl;
			cout << "킹 슬라임 : 바위" << endl;
			cout << "무승부입니다." << endl << endl;
			break;
		}

		case 2:
		{
			cout << "용사 : 바위" << endl;
			cout << "킹 슬라임 : 보" << endl;
			cout << "용사의 패배." << endl << endl;


			tpHero->mHP = tpHero->mHP - tpKingSlime->mAP;

			cout << "킹 슬라임의 공격!!" << endl;
			cout << "용사가 " << tpKingSlime->mAP << "의 피해를 입었습니다." << endl;
			cout << "용사의 체력이 " << tpHero->mHP << "만큼 남았습니다. " << endl << endl;

			break;
		}
		}

	}

	else
	{
		switch (tHero_RSP)
		{
		case 0:
		{
			cout << "용사 : 보" << endl;
			cout << "킹 슬라임 : 가위" << endl;
			cout << "용사의 패배." << endl << endl;


			tpHero->mHP = tpHero->mHP - tpKingSlime->mAP;

			cout << "킹 슬라임의 공격!!" << endl;
			cout << "용사가 " << tpKingSlime->mAP << "의 피해를 입었습니다." << endl;
			cout << "용사의 체력이 " << tpHero->mHP << "만큼 남았습니다. " << endl << endl;

			break;
		}

		case 1:
		{
			cout << "용사 : 보" << endl;
			cout << "킹 슬라임 : 바위" << endl;
			cout << "용사의 승리." << endl << endl;

			tpKingSlime->mHP = tpKingSlime->mHP - tpHero->mAP;

			cout << "용사의 공격!!" << endl;
			cout << "슬라임이 " << tpHero->mAP << "의 피해를 입었습니다." << endl;
			cout << "슬라임의 체력이 " << tpKingSlime->mHP << "만큼 남았습니다. " << endl << endl;
			break;
		}

		case 2:
		{
			cout << "용사 : 보" << endl;
			cout << "킹 슬라임 : 보" << endl;
			cout << "무승부입니다." << endl << endl;
			break;
		}
		}
	}

	return;
}