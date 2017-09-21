
/*
created by pokpoongryu

*/
#include "stdafx.h"
#include <iostream>
#include <time.h>

class CUnit
{
protected:
	float mHP = 0.0f;
	float mAP = 0.0f;

public:
	CUnit();
	virtual ~CUnit(); // virtual 을 해줘서 동적할당시 

	void SetHP(float tHP);
	float GetHP();

	void SetAP(float tAP);
	float GetAP();

};
class CHero : public CUnit
{

private:
	int mX = 0;

public:
	CHero();
	virtual ~CHero();

	void SetX(int tX); // CHero의 변수를 수정하는 함수
	int GetX();// CHero의 변수를 불러오는 함수

	void MoveX(int tVelocityX);
};

class CSlime : public CUnit
{

public:
	CSlime();
	virtual ~CSlime();
};

class CSlimeBoss : public CSlime
{
public:
	CSlimeBoss();
	virtual ~CSlimeBoss();
};

void DecideWhoDamaged(int tDiceNumber, CHero *tpHero, CSlime *tpSlime);

int main(int argc, const char * argv[]) {

	srand((unsigned int)time(NULL));

	int tWorld[5] = { 0,0,1,0,2 };

	CHero tHero;
	tHero.SetX(0);
	tHero.SetHP(100);
	tHero.SetAP(10);

	CSlime tSlime;
	tSlime.SetHP(100.0);
	tSlime.SetAP(10);


	CSlimeBoss tSlimeBoss;
	tSlimeBoss.SetHP(200);
	tSlimeBoss.SetAP(20);



	std::cout << "=================" << std::endl;
	std::cout << "HERO on 1Dimesion" << std::endl;
	std::cout << "=================" << std::endl;

	std::cout << "Welcome to 1D World" << std::endl;
	std::cout << "You are a greate brave. You must defeat against slimes." << std::endl;
	std::cout << "Good Luck!" << std::endl;




	char tIsContinue = 'y';
	char tMoveDir = 'd';


	while ('y' == tIsContinue)
	{
		while (1)
		{
			//input
			std::cout << "Move?(a/d) :";
			std::cin >> tMoveDir;

			if ('a' == tMoveDir)
			{
				//move, clipping
				if (tHero.GetX() > 0)
				{
					//tHero.mX = tHero.mX-1
					//tHero.SetX(tHero.GetX() - 1);

					tHero.MoveX(-1);

					std::cout << "<--move left" << std::endl;
				}
				else
				{
					std::cout << "$$you can not move any more." << std::endl;
				}



			}
			else if ('d' == tMoveDir)
			{
				//move, clipping
				if (tHero.GetX() < 4)
				{
					tHero.SetX(tHero.GetX() + 1);
					//GetX()로 CHero의 멤버변수의 값을 불러오고
					//SetX(int tx)로 CHero의 멤버변수의 값을 변경

					std::cout << "-->move right" << std::endl;
				}
				else
				{
					std::cout << "$$you can not move any more." << std::endl;
				}

			}

			int tAttrib = tWorld[tHero.GetX()];
			switch (tAttrib)
			{
			case 0:
			{
				std::cout << "No one here." << "(You are on " << tHero.GetX() << " Tile)" << std::endl;
			}
			break;
			case 1:
			{
				//if slime's HP is not zero.

				std::cout << "Slime is here." << "(You are on " << tHero.GetX() << " Tile)" << std::endl;


				//happen the combat with slime
				char tIsRollDice = 'r';
				while (1)
				{
					std::cout << "Roll a Dice of Fate!!(r) :";
					std::cin >> tIsRollDice;

					if ('r' == tIsRollDice)
					{
						//roll dice
						int tDiceNumber = rand() % 6 + 1;

						//decide who is damaged.
						DecideWhoDamaged(tDiceNumber, &tHero, &tSlime);

						std::cout << "--------" << std::endl;
						std::cout << "Hero.HP: " << tHero.GetHP() << std::endl;
						std::cout << "Slime.HP: " << tSlime.GetHP() << std::endl;
						std::cout << "--------" << std::endl;


						//decide win or lose
						if (tSlime.GetHP() <= 0)
						{
							std::cout << "Slime is dead." << std::endl;

							break;
						}

						if (tHero.GetHP() <= 0)
						{
							std::cout << "You are dead." << std::endl;

							break;
						}
					}
				}
			}
			break;
			case 2:
			{
				std::cout << "Boss Slime is here." << "(You are on " << tHero.GetX() << " Tile)" << std::endl;


				//happen the combat with boss of slimes
			}
			break;
			}



			if (tHero.GetHP() <= 0)
			{
				tHero.SetHP(100);

				std::cout << "Your HP is recovered." << std::endl;

				break;
			}


			std::cout << std::endl;

		}




		std::cout << "Continue?(y/n) :";
		std::cin >> tIsContinue;

		if ('n' == tIsContinue)
		{
			break;
		}
	}


	std::cout << "GOOD BYE! HERO. See u again." << std::endl;


	return 0;
}

//decide who is damaged.
void DecideWhoDamaged(int tDiceNumber, CHero *tpHero, CSlime *tpSlime)
{
	switch (tDiceNumber)
	{
	case 1:
	case 2:
	case 3:
	{
		//DoHeroDamaged(tpHero, tpSlime);
		tpHero->SetHP(tpHero->GetHP() - tpSlime->GetAP());

		//tpHero->mHP = tpHero->mHP - tpSlime->mAP;

		std::cout << "You are damaged." << std::endl;
	}
	break;
	case 4:
	case 5:
	case 6:
	{
		//DoSlimeDamaged(tpHero, tpSlime);
		tpSlime->SetHP(tpSlime->GetHP() - tpHero->GetAP());



		//tpSlime->mHP = tpSlime->mHP - tpHero->mAP;

		std::cout << "Slime is damaged." << std::endl;
	}
	break;
	}
}

CUnit::CUnit()
{

}
CUnit ::~CUnit()
{

}

void CUnit::SetHP(float tHP)
{
	mHP = tHP;
}
float CUnit::GetHP()
{
	return mHP;
}
void CUnit::SetAP(float tAP)
{
	mAP = tAP;
}
float CUnit::GetAP()
{
	return mAP;
}

CHero::CHero()
{
}
CHero ::~CHero()
{
}
void CHero::SetX(int tX)
{
	mX = tX; // CHero의 매개변수인 mX를 변경하는 함수
}
int CHero::GetX()
{
	return mX; // CHero의 매개변수를 불러오는 함수
}
void CHero::MoveX(int tVelocityX)
{
	//	SetX(GetX() + tVelocityX ); class내부인데 굳이 이럴 필요 있나
	mX = mX + tVelocityX;
}
CSlime::CSlime()
{
}
CSlime :: ~CSlime()
{
}
CSlimeBoss::CSlimeBoss()
{

}
CSlimeBoss ::~CSlimeBoss()
{

}

