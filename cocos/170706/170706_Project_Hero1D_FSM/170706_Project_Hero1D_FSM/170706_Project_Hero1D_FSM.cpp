#include "stdafx.h"

#include <iostream>
#include <vector>
#include <time.h>

class CUnit
{
	//private:
	//public:
protected:
	float mHP = 0.0f;
	float mAP = 0.0f;


public:
	CUnit();
	virtual ~CUnit();

	//private:
	//protected:
public:
	void SetHP(float tHP);
	float GetHP();

	void SetAP(float tAP);
	float GetAP();


	//step0
	//void DoDamaged(int tAP);

	//step1
	virtual void DoDamaged(int tAP);
};

class CHero :public CUnit
{
private:
	int mX = 0;

public:
	CHero();
	~CHero();

	void SetX(int tX);
	int GetX();

	void MoveX(int tVelocityX);


	void DoDamaged(int tAP) override;

};

class CSlime :public CUnit
{

public:
	CSlime();
	~CSlime();

	void DoDamaged(int tAP) override;
};

class CSlimeBoss :public CSlime
{

public:
	CSlimeBoss();
	~CSlimeBoss();

};

void DecideWhoDamaged(int tDiceNumber, CHero *tpHero, CSlime *tpSlime);

int main(int argc, const char * argv[]) {

	srand((unsigned int)time(NULL));

	//ryu stl의 vector로 바꿀 것
	int tWorld[5] = { 0,0,1,0,2 };

	vector<int> VecInt;


	CHero tHero;
	//tHero.mX    = 0;
	tHero.SetX(0);
	//tHero.mHP   = 100.0f;
	//tHero.mAP   = 10.0f;
	tHero.SetHP(100.0f);
	tHero.SetAP(10.0f);

	CSlime tSlime;
	//tSlime.mHP  = 100.0f;
	//tSlime.mAP  = 10.0;
	tSlime.SetHP(100.0f);
	tSlime.SetAP(10.0f);


	CSlimeBoss tSlimeBoss;
	//tSlimeBoss.mHP = 200.0f;
	//tSlimeBoss.mAP = 20.0;
	tSlimeBoss.SetHP(100.0f);
	tSlimeBoss.SetAP(10.0f);



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
				//if( tHero.mX > 0 )
				if (tHero.GetX()>0)
				{
					//tHero.mX = tHero.mX - 1;
					//tHero.SetX( tHero.GetX() - 1 );
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
				//if( tHero.mX < 4 )
				if (tHero.GetX()<4)
				{
					//tHero.mX = tHero.mX + 1;
					//tHero.SetX( tHero.GetX() + 1 );
					tHero.MoveX(+1);

					std::cout << "-->move right" << std::endl;
				}
				else
				{
					std::cout << "$$you can not move any more." << std::endl;
				}

			}

			//int tAttrib = tWorld[ tHero.mX ];
			int tAttrib = tWorld[tHero.GetX()];
			switch (tAttrib)
			{
			case 0:
			{
				//std::cout<<"No one here."<<"(You are on "<<tHero.mX<<" Tile)"<<std::endl;
				std::cout << "No one here." << "(You are on " << tHero.GetX() << " Tile)" << std::endl;
			}
			break;
			case 1:
			{
				//if slime's HP is not zero.

				//std::cout<<"Slime is here."<<"(You are on "<<tHero.mX<<" Tile)"<<std::endl;
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
						//std::cout<<"Hero.HP: "<<tHero.mHP<<std::endl;
						//std::cout<<"Slime.HP: "<<tSlime.mHP<<std::endl;
						std::cout << "Hero.HP: " << tHero.GetHP() << std::endl;
						std::cout << "Slime.HP: " << tSlime.GetHP() << std::endl;
						std::cout << "--------" << std::endl;

						//ryu 상태기계 형태로 바꾸어볼것( switch구문 이용 )ALIVE, WEAK, DEAD
						//decide win or lose
						//if( tSlime.mHP <= 0 )
						if (tSlime.GetHP() <= 0)
						{
							std::cout << "Slime is dead." << std::endl;

							break;
						}

						//if( tHero.mHP <= 0 )
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
				//std::cout<<"Boss Slime is here."<<"(You are on "<<tHero.mX<<" Tile)"<<std::endl;
				std::cout << "Boss Slime is here." << "(You are on " << tHero.GetX() << " Tile)" << std::endl;


				//happen the combat with boss of slimes
			}
			break;
			}



			//if( tHero.mHP <= 0 )
			if (tHero.GetHP() <= 0)
			{
				//tHero.mHP = 100.0f;
				tHero.SetHP(100.0f);

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
		//tpHero->mHP = tpHero->mHP - tpSlime->mAP;
		//tpHero->SetHP( tpHero->GetHP() - tpSlime->GetAP() );
		tpHero->DoDamaged(tpSlime->GetAP());

		std::cout << "You are damaged." << std::endl;
	}
	break;
	case 4:
	case 5:
	case 6:
	{
		//DoSlimeDamaged(tpHero, tpSlime);
		//tpSlime->mHP = tpSlime->mHP - tpHero->mAP;
		//tpSlime->SetHP( tpSlime->GetHP() - tpHero->GetAP() );
		tpSlime->DoDamaged(tpHero->GetAP());

		std::cout << "Slime is damaged." << std::endl;
	}
	break;
	}
}




CUnit::CUnit()
{

}
CUnit::~CUnit()
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

void CUnit::DoDamaged(int tAP)
{
	mHP = mHP - tAP;
}



CHero::CHero()
{

}
CHero::~CHero()
{

}

void CHero::SetX(int tX)
{
	mX = tX;
}
int CHero::GetX()
{
	return mX;
}
void CHero::MoveX(int tVelocityX)
{
	mX = mX + tVelocityX;
}

void CHero::DoDamaged(int tAP)
{
	int tFortune = rand() % 6 + 1;

	if (tFortune >= 4)
	{
		mHP = mHP - tAP;
	}
}




CSlime::CSlime()
{

}
CSlime::~CSlime()
{

}

void CSlime::DoDamaged(int tAP)
{
	CUnit::DoDamaged(tAP);
}


CSlimeBoss::CSlimeBoss()
{

}
CSlimeBoss::~CSlimeBoss()
{

}

