// Project_Hero_is_1D_SE.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	//������
	cout << "========================================" << endl;
	cout << "==============���� 1����==============" << endl;
	cout << "========================================" << endl;
	cout << endl;


	char tGameStart = 0;
	cout << "������ �����Ͻðڽ��ϱ�?(y/n)";
	cin >> tGameStart;

	//���� ����
	while ('y' == tGameStart)
	{
		while (1)
		{
			//////////////////�� �̵� ���/////////////////////////////
			char tMoveDir = 'd';
			cout << "�̵��Ͻðڽ��ϱ�??(���� : a, ������ : d) : ";
			cin >> tMoveDir;
			
			DoMoveFuction(tMoveDir, tpHero); //�̵� �Լ�

			/////////////////��Ī �� ���� ���/////////////////////////
			//�� �迭�� ���� 
			//0 : �̺�Ʈ ����
			//1 : ������ �̺�Ʈ  - �ֻ���
			//2 : ŷ ������ �̺�Ʈ - ����������
			
			int tAttrib = tWorld[tpHero->mX];

			EventMoveHero(tAttrib, tpHero, tpSlime, tpKingSlime); //�̺�Ʈ �Լ�

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
			cout << "������ �����ƴ�. ������ ��ȭ�ο�����." << endl << endl;
			break;
		}
	}

	//���� ����
	cout << "���� 1������ �����մϴ�." << endl << endl;

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

//���� 1 : �������� ����ġ�� ������ ���� ���ƿͼ� ������ �������� ü���� 0�� ����

//1. �� �̵� �Լ� 
void DoMoveFuction(char tMoveDir, SCharacter *tpHero)
{
	// �·� �̵� ���
	if ('a' == tMoveDir)
	{
		if (tpHero->mX > 0)
		{
			tpHero->mX = tpHero->mX - 1;
			cout << "<<-- �������� �̵��մϴ�." << endl;
		}
		else
		{
			cout << "�� �̻� �������� �̵��� �� �����ϴ�." << endl;
		}
	}
	// ��� �̵� ���

	else if ('d' == tMoveDir)
	{
		if (tpHero->mX < 4)
		{
			tpHero->mX = tpHero->mX + 1;
			cout << "-->> ���������� �̵��մϴ�." << endl;

		}
		else
		{
			cout << "�� �̻� ���������� �̵��� �� �����ϴ�." << endl;
		}
	}
	// �߸��� �Է�
	else
	{
		cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
	}

	return;
}

//2. ����� ��ġ�� �̺�Ʈ �߻�(0 : �ƹ��� ����. 1: ������ ����(�ֻ���) 2:ŷ������ ����(����������)
void EventMoveHero(int tAttrib, SCharacter *tpHero, SCharacter *tpSlime, SCharacter *tpKingSlime)
{
	//�� �迭�� ���� 
	//0 : �̺�Ʈ ����
	//1 : ������ �̺�Ʈ  - �ֻ���
	//2 : ŷ ������ �̺�Ʈ - ����������
	
	switch (tAttrib)
	{
	
	case 0: //�ƹ��� ��� �̺�Ʈ ����.
	{
		cout << "���� " << tpHero->mX << "Ÿ�Ͽ� �ֽ��ϴ�." << endl;
		cout << "�ƹ��� �����ϴ�. " << endl;
		break; // case0�� �극��ũ
	}


	case 1:  // ������ ���� �� �ֻ��� �̺�Ʈ
	{
		cout << "���� " << tpHero->mX << "Ÿ�Ͽ� �ֽ��ϴ�." << endl;
		cout << "�����Ӱ� �������ϴ�. ������ �����մϴ�." << endl;

		char tRollDice = 'r';

		while (1)
		{
			cout << "[ r ] ��ư�� ���� �ֻ����� �����ּ��� : ";
			cin >> tRollDice;
			cout << endl;

			DoBattleSlime(tRollDice, tpHero, tpSlime); //������ ���� ����(�ֻ���)

			if (0 >= tpHero->mHP)
			{
				cout << "����� ���� " << endl;
				break;
			}

			else if (0 >= tpSlime->mHP)
			{
				cout << "���� �������� �����ƴ�." << endl << endl;
				break;
			}
		}

		break;// case1�� �극��ũ
	}

	// ŷ ������ ���� �� ���������� �̺�Ʈ
	case 2:
	{
		cout << "���� " << tpHero->mX << "Ÿ�Ͽ� �ֽ��ϴ�." << endl;
		cout << "ŷ �����Ӱ� �������ϴ�. ������ �����մϴ�. " << endl << endl;

		int tHero_RSP = 0;

		while (1)
		{
			cout << "���������� ������ �մϴ�. [0 : ����, 1 : ����. 2 : ��]";
			cin >> tHero_RSP;

			DoBattleKingSlime(tHero_RSP, tpHero, tpKingSlime);

			if (0 >= tpHero->mHP)
			{
				cout << "����� ���� " << endl;
				break;
			}

			else if (0 >= tpKingSlime->mHP)
			{
				cout << "���� ŷ �������� �����ƴ�." << endl << endl;
				break;
			}
		}
		break;// case2�� �극��ũ
	}
	}

}

//3. ������ ����(�ֻ���)
void DoBattleSlime(char tRollDice, SCharacter *tpHero, SCharacter *tpSlime)
{
	if ('r' == tRollDice)
	{
		//�ֻ��� ���� ����.
		int tDiceNumber = rand() % 6 + 1;

		switch (tDiceNumber)
		{
		case 1:
		case 2:
		case 3:
		{
			cout << "�������� ����!!" << endl;
			cout << "��簡 " << tpSlime->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			tpHero->mHP = tpHero->mHP - tpSlime->mAP;
			cout << "����� ü���� " << tpHero->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;
			break;
		}
		case 4:
		case 5:
		case 6:
		{
			cout << "����� ����!!" << endl;
			cout << "�������� " << tpHero->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			tpSlime->mHP = tpSlime->mHP - tpHero->mAP;

			cout << "�������� ü���� " << tpSlime->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

			break;
		}
		}
	}

}

//4. ŷ ������ ����(����������)
void DoBattleKingSlime(int tHero_RSP, SCharacter *tpHero, SCharacter *tpKingSlime)
{
	int tKingSlime_RSP = rand() % 3;

	if (tHero_RSP = 0) // ��簡 ������ ��
	{
		switch (tKingSlime_RSP)
		{
		case 0://ŷ �������� ����
		{
			cout << "��� : ����" << endl;
			cout << "ŷ ������ : ����" << endl;
			cout << "���º��Դϴ�." << endl << endl;
			break;
		}

		case 1://ŷ �������� ����
		{
			cout << "��� : ����" << endl;
			cout << "ŷ ������ : ����" << endl;
			cout << "����� �й�." << endl << endl;

			tpHero->mHP = tpHero->mHP - tpKingSlime->mAP;

			cout << "ŷ �������� ����!!" << endl;
			cout << "��簡 " << tpKingSlime->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			cout << "����� ü���� " << tpHero->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

			break;
		}

		case 2://ŷ �������� ��
		{
			cout << "��� : ����" << endl;
			cout << "ŷ ������ : ��" << endl;
			cout << "����� �¸�." << endl << endl;

			tpKingSlime->mHP = tpKingSlime->mHP - tpHero->mAP;

			cout << "����� ����!!" << endl;
			cout << "�������� " << tpHero->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			cout << "�������� ü���� " << tpKingSlime->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

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
			cout << "��� : ����" << endl;
			cout << "ŷ ������ : ����" << endl;
			cout << "����� �¸�." << endl << endl;

			tpKingSlime->mHP = tpKingSlime->mHP - tpHero->mAP;

			cout << "����� ����!!" << endl;
			cout << "�������� " << tpHero->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			cout << "�������� ü���� " << tpKingSlime->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

			break;
		}

		case 1:
		{
			cout << "��� : ����" << endl;
			cout << "ŷ ������ : ����" << endl;
			cout << "���º��Դϴ�." << endl << endl;
			break;
		}

		case 2:
		{
			cout << "��� : ����" << endl;
			cout << "ŷ ������ : ��" << endl;
			cout << "����� �й�." << endl << endl;


			tpHero->mHP = tpHero->mHP - tpKingSlime->mAP;

			cout << "ŷ �������� ����!!" << endl;
			cout << "��簡 " << tpKingSlime->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			cout << "����� ü���� " << tpHero->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

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
			cout << "��� : ��" << endl;
			cout << "ŷ ������ : ����" << endl;
			cout << "����� �й�." << endl << endl;


			tpHero->mHP = tpHero->mHP - tpKingSlime->mAP;

			cout << "ŷ �������� ����!!" << endl;
			cout << "��簡 " << tpKingSlime->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			cout << "����� ü���� " << tpHero->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;

			break;
		}

		case 1:
		{
			cout << "��� : ��" << endl;
			cout << "ŷ ������ : ����" << endl;
			cout << "����� �¸�." << endl << endl;

			tpKingSlime->mHP = tpKingSlime->mHP - tpHero->mAP;

			cout << "����� ����!!" << endl;
			cout << "�������� " << tpHero->mAP << "�� ���ظ� �Ծ����ϴ�." << endl;
			cout << "�������� ü���� " << tpKingSlime->mHP << "��ŭ ���ҽ��ϴ�. " << endl << endl;
			break;
		}

		case 2:
		{
			cout << "��� : ��" << endl;
			cout << "ŷ ������ : ��" << endl;
			cout << "���º��Դϴ�." << endl << endl;
			break;
		}
		}
	}

	return;
}