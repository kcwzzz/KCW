// Project_Hero_is_1D_SE.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h >
#include <time.h>

using namespace std;

class CCharacter
{
protected:
	float mHP;
	float mAP;

public:
	void SetHP(float tHP);
	float GetHP();

	void SetAP(float tAP);
	float GetAP();	
};

class CHero : public CCharacter
{
private:
	int mX = 0;

public:
	void SetX(int tX);
	int  GetX();
	void DoMoveFuction(char tMoveDir); //이동 함수
};

class CSlime : public CCharacter
{
public:
	int DoRollDice(char tRollDice);
	void DoBattleSlime(int tDiceNumber, CHero *tHero);
};

class CKingSlime : public CCharacter
{
public:
	int DoRSPGame(int tHero_RSP);
	void DoBattleKingSlime(int tRSP_Result, CHero *tHero);
};

void EventMoveHero(int tAttrib, CHero *tpHero, CSlime *tpSlime, CKingSlime *tpKingSlime);

int main()
{
	srand((unsigned int)time(NULL));

	int tWorld[5] = { 0,0,1,0,2 };

	CHero *tpHero=NULL;
	tpHero = new CHero;
	tpHero->SetX(0);
	tpHero->SetHP(200);
	tpHero->SetAP(50);

	CSlime  *tpSlime=NULL;
	tpSlime = new CSlime;
	tpSlime->SetHP(100);
	tpSlime->SetAP(10);

	CKingSlime *tpKingSlime=NULL;
	tpKingSlime = new CKingSlime;
	tpKingSlime->SetHP(200);
	tpKingSlime->SetAP(20);
	
	//오프닝
	cout << "================================================================================" << endl;
	cout << "================================================================================" << endl;
	cout << "===================================용사는 1차원=================================" << endl;
	cout << "================================================================================" << endl;
	cout << "================================================================================" << endl;
	cout << endl;


	char tGameStart = 0;
	cout << " >> 게임을 시작하시겠습니까?(y/n)";
	cin >> tGameStart;
	cout << endl;

	//메인 게임 루프
	while ('y' == tGameStart)
	{
		while (1)
		{
			//////////////////맵 이동 기능/////////////////////////////
			char tMoveDir = 'd';
			cout << " >> 이동하시겠습니까??(왼쪽 : a, 오른쪽 : d) : ";
			cin >> tMoveDir;
			cout << endl;

			tpHero->DoMoveFuction(tMoveDir);
			
			/////////////////매칭 및 전투 기능/////////////////////////
			//맵 배열의 숫자 
			//0 : 이벤트 없음
			//1 : 슬라임 이벤트  - 주사위
			//2 : 킹 슬라임 이벤트 - 가위바위보

			int tAttrib = tWorld[tpHero->GetX()];
			
			EventMoveHero(tAttrib, tpHero, tpSlime, tpKingSlime); //이벤트 함수

			if (0 >= tpHero->GetHP())
			{
				break;
			}
			else if (0 >= tpKingSlime->GetHP())
			{
				break;
			}
		}
		if (0 >= tpHero->GetHP())
		{
			cout << "GAME OVER" << endl << endl;
			break;
		}
		else if (0 >= tpKingSlime->GetHP())
		{
			cout << "보스를 물리쳤다. 세상이 평화로워졌다." << endl << endl;
			break;
		}
	}

	//게임 종료
	cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;
	cout << "===========================용사는 1차원 종료합니다==========================" << endl;
	cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;

	//동적할당 삭제.
	/*
	if (NULL != tKingSlime)
	{
	delete tKingSlime;
	tKingSlime = NULL;
	}

	if (NULL != tSlime)
	{
	delete tSlime;
	tSlime = NULL;
	}

	if (NULL != tHero)
	{
	delete tHero;
	tHero = NULL;
	}
	*/

	return 0;
}


void CCharacter::SetHP(float tHP)
{
	mHP = tHP;
}
float CCharacter::GetHP()
{
	return mHP;
}
void EventMoveHero(int tAttrib, CHero *tHero, CSlime *tSlime, CKingSlime *tKingSlime)
{
	//맵 배열의 숫자 
	//0 : 이벤트 없음
	//1 : 슬라임 이벤트  - 주사위
	//2 : 킹 슬라임 이벤트 - 가위바위보

	switch (tAttrib)
	{

	case 0: //아무도 없어서 이벤트 없음.
	{
		cout << "      용사는 " << tHero->GetX() << "타일에 있습니다." << endl;
		cout << "      아무도 없습니다. " << endl << endl;
		break; // case0을 브레이크
	}

	case 1:  // 슬라임 조우 및 주사위 이벤트
	{
		cout << "      용사는 " << tHero->GetX() << "타일에 있습니다." << endl;

		if (tSlime->GetHP() <= 0)
		{
			cout << "      슬라임과 만났다..... 움직임이 없다..... 이미 시체인 것 같다." << endl << endl;
		}

		else
		{
			cout << "      슬라임과 만났습니다. 전투를 시작합니다." << endl << endl;

			char tRollDice = 'r';

			cout << "================================================================================" << endl;
			cout << "================================슬라임과의 전투=================================" << endl;
			cout << "================================================================================" << endl;
			cout << endl;

			while (1)
			{
				//int tActivity_Hero = 0;
				int tDiceNumber = 0;

				cout << "\t [[용사]] \t\t\t\t [[슬라임]]" << endl;
				cout << "\t 공격력 : " << tHero->GetAP() << "\t\t\t\t 공격력 : " << tSlime->GetAP() << endl;
				cout << "\t   체력 : " << tHero->GetHP() << "\t\t\t\t   체력 : " << tSlime->GetHP() << endl << endl;

				cout << "  >> [ r ] 버튼을 눌러 주사위를 던져주세요 : ";
				cin >> tRollDice;
				cout << endl;

				//주사위 돌리기
				tDiceNumber = tSlime->DoRollDice(tRollDice);

				//슬라임 배틀 
				//일반 값으로 하면 Call by value로 처리하기 때문에 포인터나 레퍼런스로 해야함.
				tSlime->DoBattleSlime(tDiceNumber, tHero);



				if (0 >= tHero->GetHP())
				{
					cout << "      용사의 죽음 " << endl;
					break;
				}

				else if (0 >= tSlime->GetHP())
				{
					cout << "      용사는 슬라임을 물리쳤다." << endl << endl;
					break;
				}
			}
		}

		break;// case1을 브레이크
	}

	// 킹 슬라임 조우 및 가위바위보 이벤트
	case 2:
	{
		cout << "      용사는 " << tHero->GetX() << "타일에 있습니다." << endl;
		cout << "      킹 슬라임과 만났습니다. 전투를 시작합니다. " << endl << endl;

		cout << "================================================================================" << endl;
		cout << "===============================킹슬라임과의 전투================================" << endl;
		cout << "================================================================================" << endl;
		cout << endl;

		int tHero_RSP = 0;

		while (1)
		{
			cout << "\t [[용사]] \t\t\t\t [[킹 슬라임]]" << endl;
			cout << "\t 공격력 : " << tHero->GetAP() << "\t\t\t\t 공격력 : " << tKingSlime->GetAP() << endl;
			cout << "\t   체력 : " << tHero->GetHP() << "\t\t\t\t   체력 : " << tKingSlime->GetHP() << endl << endl;

			cout << "  >> 가위바위보 게임을 합니다. [0 : 가위, 1 : 바위. 2 : 보]";
			cin >> tHero_RSP;

			int tRSP_Result = 0;
			tRSP_Result = tKingSlime->DoRSPGame(tHero_RSP);
			tKingSlime->DoBattleKingSlime(tRSP_Result, tHero);

			if (0 >= tHero->GetHP())
			{
				cout << "      용사의 죽음 " << endl;
				break;
			}

			else if (0 >= tKingSlime->GetHP())
			{
				cout << "      용사는 킹 슬라임을 물리쳤다." << endl << endl;
				break;
			}
		}
		break;// case2를 브레이크
	}
	}
}

void CCharacter::SetAP(float tAP)
{
	mAP = tAP;
}
float CCharacter::GetAP()
{
	return mAP;
}

void CHero::SetX(int tX)
{
	mX = tX;
}
int CHero::GetX()
{

	return mX;
}
void CHero::DoMoveFuction(char tMoveDir)

{
	// 좌로 이동 기능
	if ('a' == tMoveDir)
	{
		if (mX > 0)
		{
			mX = mX - 1;
			//	tHero.GetX() = tHero.GetX() - 1;
			cout << "      <<-- 왼쪽으로 이동합니다." << endl << endl;
			//cout << tSlime.GetHP() << endl;
		}
		else
		{
			cout << "      더 이상 왼쪽으로 이동할 수 없습니다." << endl << endl;
		}
	}
	// 우로 이동 기능

	else if ('d' == tMoveDir)
	{
		if (mX < 4)
		{
			mX = mX + 1;
			//tHero.GetX() = tHero.GetX() + 1;
			cout << "      -->> 오른쪽으로 이동합니다." << endl << endl;
			//cout << tSlime.GetHP() << endl;

		}
		else
		{
			cout << "      더 이상 오른쪽으로 이동할 수 없습니다." << endl << endl;
		}
	}
	// 잘못된 입력
	else
	{
		cout << "      잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl << endl;
	}

	return;
}

int CSlime::DoRollDice(char tRollDice)
{
	if ('r' == tRollDice)
	{
		//주사위 값을 얻음.
		int tDiceNumber = 0;
		tDiceNumber = rand() % 6 + 1;
		cout << "      주사위 값은 " << tDiceNumber << "입니다." << endl << endl;
		return tDiceNumber;
	}
}
void CSlime::DoBattleSlime(int tDiceNumber, CHero *tHero)
{
	switch (tDiceNumber)
	{
	case 1:
	case 2:
	case 3:
	{
		cout << "      슬라임의 공격!!" << endl;
		cout << "      용사가 " << mAP << "의 피해를 입었습니다." << endl;
		tHero->SetHP(tHero->GetHP() - mAP);
		//tHero.GetHP() = tHero.GetHP() - tSlime.GetAP();
		cout << "      용사의 체력이 " << tHero->GetHP() << "만큼 남았습니다. " << endl << endl;
		break;
	}
	case 4:
	case 5:
	case 6:
	{
		cout << "      용사의 공격!!" << endl;
		cout << "      슬라임이 " << tHero->GetAP() << "의 피해를 입었습니다." << endl;
		mHP = mHP - tHero->GetAP();
		//tSlime.GetHP() = tSlime.GetHP() - tHero.GetAP();

		cout << "      슬라임의 체력이 " << mHP << "만큼 남았습니다. " << endl << endl;

		break;
	}
	}
}

int CKingSlime::DoRSPGame(int tHero_RSP)
{
	//결과값은 해당 숫자를 리턴한다.
	// 0이면 무승부
	// 1이면 용사의 패배
	// 2이면 용사의 승리

	int tKingSlime_RSP = rand() % 3;

	if (0 == tHero_RSP) // 용사가 가위일 때
	{
		switch (tKingSlime_RSP)
		{
		case 0://킹 슬라임이 가위
		{
			cout << "      용사 : 가위" << endl;
			cout << "      킹 슬라임 : 가위" << endl;
			cout << "      [무승부]입니다." << endl << endl;
			return 0;

			break;
		}

		case 1://킹 슬라임이 바위
		{
			cout << "      용사 : 가위" << endl;
			cout << "      킹 슬라임 : 바위" << endl;
			cout << "      용사의 [패배]." << endl << endl;
			return 1;
			break;
		}

		case 2://킹 슬라임이 보
		{
			cout << "      용사 : 가위" << endl;
			cout << "      킹 슬라임 : 보" << endl;
			cout << "      용사의 [승리]." << endl << endl;
			return 2;

			break;
		}
		}
	}

	else if (1 == tHero_RSP)
	{
		switch (tKingSlime_RSP)
		{
		case 0:
		{
			cout << "      용사 : 바위" << endl;
			cout << "      킹 슬라임 : 가위" << endl;
			cout << "      용사의 [승리]." << endl << endl;
			return 2;
			break;
		}

		case 1:
		{
			cout << "      용사 : 바위" << endl;
			cout << "      킹 슬라임 : 바위" << endl;
			cout << "      [무승부]입니다." << endl << endl;
			return 0;
			break;
		}

		case 2:
		{
			cout << "      용사 : 바위" << endl;
			cout << "      킹 슬라임 : 보" << endl;
			cout << "      용사의 [패배]." << endl << endl;
			return 1;

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
			cout << "      용사 : 보" << endl;
			cout << "      킹 슬라임 : 가위" << endl;
			cout << "      용사의 [패배]." << endl << endl;
			return 1;

			break;
		}

		case 1:
		{
			cout << "      용사 : 보" << endl;
			cout << "      킹 슬라임 : 바위" << endl;
			cout << "      용사의 [승리]." << endl << endl;
			return 2;
			break;
		}

		case 2:
		{
			cout << "      용사 : 보" << endl;
			cout << "      킹 슬라임 : 보" << endl;
			cout << "      [무승부]입니다." << endl << endl;
			return 0;
			break;
		}
		}
	}
}
void CKingSlime::DoBattleKingSlime(int tRSP_Result, CHero *tHero)
{
	switch (tRSP_Result)
	{
	case 0://가위바위보 결과가 무승부
	{
		break;
	}

	case 1://가위바위보 결과가 패배
	{
		tHero->SetHP(tHero->GetHP() - mAP);

		cout << "      킹 슬라임의 공격!!" << endl;
		cout << "      용사가 " << mAP << "의 피해를 입었습니다." << endl;
		cout << "      용사의 체력이 " << tHero->GetHP() << "만큼 남았습니다. " << endl << endl;

		break;
	}

	case 2://가위바위보 결과가 승리
	{
		mHP = mHP - tHero->GetAP();

		cout << "      용사의 공격!!" << endl;
		cout << "      슬라임이 " << tHero->GetAP() << "의 피해를 입었습니다." << endl;
		cout << "      슬라임의 체력이 " << mHP << "만큼 남았습니다. " << endl << endl;

		break;
	}
	}

	return;
}

//2. 용사의 위치별 이벤트 발생(0 : 아무일 없음. 1: 슬라임 전투(주사위) 2:킹슬라임 전투(가위바위보)