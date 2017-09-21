// Project_Hero_is_1D_SE.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	void DoMoveFuction(char tMoveDir); //�̵� �Լ�
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
	
	//������
	cout << "================================================================================" << endl;
	cout << "================================================================================" << endl;
	cout << "===================================���� 1����=================================" << endl;
	cout << "================================================================================" << endl;
	cout << "================================================================================" << endl;
	cout << endl;


	char tGameStart = 0;
	cout << " >> ������ �����Ͻðڽ��ϱ�?(y/n)";
	cin >> tGameStart;
	cout << endl;

	//���� ���� ����
	while ('y' == tGameStart)
	{
		while (1)
		{
			//////////////////�� �̵� ���/////////////////////////////
			char tMoveDir = 'd';
			cout << " >> �̵��Ͻðڽ��ϱ�??(���� : a, ������ : d) : ";
			cin >> tMoveDir;
			cout << endl;

			tpHero->DoMoveFuction(tMoveDir);
			
			/////////////////��Ī �� ���� ���/////////////////////////
			//�� �迭�� ���� 
			//0 : �̺�Ʈ ����
			//1 : ������ �̺�Ʈ  - �ֻ���
			//2 : ŷ ������ �̺�Ʈ - ����������

			int tAttrib = tWorld[tpHero->GetX()];
			
			EventMoveHero(tAttrib, tpHero, tpSlime, tpKingSlime); //�̺�Ʈ �Լ�

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
			cout << "������ �����ƴ�. ������ ��ȭ�ο�����." << endl << endl;
			break;
		}
	}

	//���� ����
	cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;
	cout << "===========================���� 1���� �����մϴ�==========================" << endl;
	cout << "============================================================================" << endl;
	cout << "============================================================================" << endl;

	//�����Ҵ� ����.
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
	//�� �迭�� ���� 
	//0 : �̺�Ʈ ����
	//1 : ������ �̺�Ʈ  - �ֻ���
	//2 : ŷ ������ �̺�Ʈ - ����������

	switch (tAttrib)
	{

	case 0: //�ƹ��� ��� �̺�Ʈ ����.
	{
		cout << "      ���� " << tHero->GetX() << "Ÿ�Ͽ� �ֽ��ϴ�." << endl;
		cout << "      �ƹ��� �����ϴ�. " << endl << endl;
		break; // case0�� �극��ũ
	}

	case 1:  // ������ ���� �� �ֻ��� �̺�Ʈ
	{
		cout << "      ���� " << tHero->GetX() << "Ÿ�Ͽ� �ֽ��ϴ�." << endl;

		if (tSlime->GetHP() <= 0)
		{
			cout << "      �����Ӱ� ������..... �������� ����..... �̹� ��ü�� �� ����." << endl << endl;
		}

		else
		{
			cout << "      �����Ӱ� �������ϴ�. ������ �����մϴ�." << endl << endl;

			char tRollDice = 'r';

			cout << "================================================================================" << endl;
			cout << "================================�����Ӱ��� ����=================================" << endl;
			cout << "================================================================================" << endl;
			cout << endl;

			while (1)
			{
				//int tActivity_Hero = 0;
				int tDiceNumber = 0;

				cout << "\t [[���]] \t\t\t\t [[������]]" << endl;
				cout << "\t ���ݷ� : " << tHero->GetAP() << "\t\t\t\t ���ݷ� : " << tSlime->GetAP() << endl;
				cout << "\t   ü�� : " << tHero->GetHP() << "\t\t\t\t   ü�� : " << tSlime->GetHP() << endl << endl;

				cout << "  >> [ r ] ��ư�� ���� �ֻ����� �����ּ��� : ";
				cin >> tRollDice;
				cout << endl;

				//�ֻ��� ������
				tDiceNumber = tSlime->DoRollDice(tRollDice);

				//������ ��Ʋ 
				//�Ϲ� ������ �ϸ� Call by value�� ó���ϱ� ������ �����ͳ� ���۷����� �ؾ���.
				tSlime->DoBattleSlime(tDiceNumber, tHero);



				if (0 >= tHero->GetHP())
				{
					cout << "      ����� ���� " << endl;
					break;
				}

				else if (0 >= tSlime->GetHP())
				{
					cout << "      ���� �������� �����ƴ�." << endl << endl;
					break;
				}
			}
		}

		break;// case1�� �극��ũ
	}

	// ŷ ������ ���� �� ���������� �̺�Ʈ
	case 2:
	{
		cout << "      ���� " << tHero->GetX() << "Ÿ�Ͽ� �ֽ��ϴ�." << endl;
		cout << "      ŷ �����Ӱ� �������ϴ�. ������ �����մϴ�. " << endl << endl;

		cout << "================================================================================" << endl;
		cout << "===============================ŷ�����Ӱ��� ����================================" << endl;
		cout << "================================================================================" << endl;
		cout << endl;

		int tHero_RSP = 0;

		while (1)
		{
			cout << "\t [[���]] \t\t\t\t [[ŷ ������]]" << endl;
			cout << "\t ���ݷ� : " << tHero->GetAP() << "\t\t\t\t ���ݷ� : " << tKingSlime->GetAP() << endl;
			cout << "\t   ü�� : " << tHero->GetHP() << "\t\t\t\t   ü�� : " << tKingSlime->GetHP() << endl << endl;

			cout << "  >> ���������� ������ �մϴ�. [0 : ����, 1 : ����. 2 : ��]";
			cin >> tHero_RSP;

			int tRSP_Result = 0;
			tRSP_Result = tKingSlime->DoRSPGame(tHero_RSP);
			tKingSlime->DoBattleKingSlime(tRSP_Result, tHero);

			if (0 >= tHero->GetHP())
			{
				cout << "      ����� ���� " << endl;
				break;
			}

			else if (0 >= tKingSlime->GetHP())
			{
				cout << "      ���� ŷ �������� �����ƴ�." << endl << endl;
				break;
			}
		}
		break;// case2�� �극��ũ
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
	// �·� �̵� ���
	if ('a' == tMoveDir)
	{
		if (mX > 0)
		{
			mX = mX - 1;
			//	tHero.GetX() = tHero.GetX() - 1;
			cout << "      <<-- �������� �̵��մϴ�." << endl << endl;
			//cout << tSlime.GetHP() << endl;
		}
		else
		{
			cout << "      �� �̻� �������� �̵��� �� �����ϴ�." << endl << endl;
		}
	}
	// ��� �̵� ���

	else if ('d' == tMoveDir)
	{
		if (mX < 4)
		{
			mX = mX + 1;
			//tHero.GetX() = tHero.GetX() + 1;
			cout << "      -->> ���������� �̵��մϴ�." << endl << endl;
			//cout << tSlime.GetHP() << endl;

		}
		else
		{
			cout << "      �� �̻� ���������� �̵��� �� �����ϴ�." << endl << endl;
		}
	}
	// �߸��� �Է�
	else
	{
		cout << "      �߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl << endl;
	}

	return;
}

int CSlime::DoRollDice(char tRollDice)
{
	if ('r' == tRollDice)
	{
		//�ֻ��� ���� ����.
		int tDiceNumber = 0;
		tDiceNumber = rand() % 6 + 1;
		cout << "      �ֻ��� ���� " << tDiceNumber << "�Դϴ�." << endl << endl;
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
		cout << "      �������� ����!!" << endl;
		cout << "      ��簡 " << mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
		tHero->SetHP(tHero->GetHP() - mAP);
		//tHero.GetHP() = tHero.GetHP() - tSlime.GetAP();
		cout << "      ����� ü���� " << tHero->GetHP() << "��ŭ ���ҽ��ϴ�. " << endl << endl;
		break;
	}
	case 4:
	case 5:
	case 6:
	{
		cout << "      ����� ����!!" << endl;
		cout << "      �������� " << tHero->GetAP() << "�� ���ظ� �Ծ����ϴ�." << endl;
		mHP = mHP - tHero->GetAP();
		//tSlime.GetHP() = tSlime.GetHP() - tHero.GetAP();

		cout << "      �������� ü���� " << mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

		break;
	}
	}
}

int CKingSlime::DoRSPGame(int tHero_RSP)
{
	//������� �ش� ���ڸ� �����Ѵ�.
	// 0�̸� ���º�
	// 1�̸� ����� �й�
	// 2�̸� ����� �¸�

	int tKingSlime_RSP = rand() % 3;

	if (0 == tHero_RSP) // ��簡 ������ ��
	{
		switch (tKingSlime_RSP)
		{
		case 0://ŷ �������� ����
		{
			cout << "      ��� : ����" << endl;
			cout << "      ŷ ������ : ����" << endl;
			cout << "      [���º�]�Դϴ�." << endl << endl;
			return 0;

			break;
		}

		case 1://ŷ �������� ����
		{
			cout << "      ��� : ����" << endl;
			cout << "      ŷ ������ : ����" << endl;
			cout << "      ����� [�й�]." << endl << endl;
			return 1;
			break;
		}

		case 2://ŷ �������� ��
		{
			cout << "      ��� : ����" << endl;
			cout << "      ŷ ������ : ��" << endl;
			cout << "      ����� [�¸�]." << endl << endl;
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
			cout << "      ��� : ����" << endl;
			cout << "      ŷ ������ : ����" << endl;
			cout << "      ����� [�¸�]." << endl << endl;
			return 2;
			break;
		}

		case 1:
		{
			cout << "      ��� : ����" << endl;
			cout << "      ŷ ������ : ����" << endl;
			cout << "      [���º�]�Դϴ�." << endl << endl;
			return 0;
			break;
		}

		case 2:
		{
			cout << "      ��� : ����" << endl;
			cout << "      ŷ ������ : ��" << endl;
			cout << "      ����� [�й�]." << endl << endl;
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
			cout << "      ��� : ��" << endl;
			cout << "      ŷ ������ : ����" << endl;
			cout << "      ����� [�й�]." << endl << endl;
			return 1;

			break;
		}

		case 1:
		{
			cout << "      ��� : ��" << endl;
			cout << "      ŷ ������ : ����" << endl;
			cout << "      ����� [�¸�]." << endl << endl;
			return 2;
			break;
		}

		case 2:
		{
			cout << "      ��� : ��" << endl;
			cout << "      ŷ ������ : ��" << endl;
			cout << "      [���º�]�Դϴ�." << endl << endl;
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
	case 0://���������� ����� ���º�
	{
		break;
	}

	case 1://���������� ����� �й�
	{
		tHero->SetHP(tHero->GetHP() - mAP);

		cout << "      ŷ �������� ����!!" << endl;
		cout << "      ��簡 " << mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
		cout << "      ����� ü���� " << tHero->GetHP() << "��ŭ ���ҽ��ϴ�. " << endl << endl;

		break;
	}

	case 2://���������� ����� �¸�
	{
		mHP = mHP - tHero->GetAP();

		cout << "      ����� ����!!" << endl;
		cout << "      �������� " << tHero->GetAP() << "�� ���ظ� �Ծ����ϴ�." << endl;
		cout << "      �������� ü���� " << mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

		break;
	}
	}

	return;
}

//2. ����� ��ġ�� �̺�Ʈ �߻�(0 : �ƹ��� ����. 1: ������ ����(�ֻ���) 2:ŷ������ ����(����������)