// 170706_Project_Hero1D_FSM_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
////ryu 상태기계 형태로 바꾸어볼것( switch구문 이용 )ALIVE, WEAK, DEAD

#include "stdafx.h"
#include <iostream>

#include <vector>
#include <time.h>

using namespace std;

enum STATE { ALIVE = 0, WEAK = 1, DEAD = 2 };

class CUnit
{
private:
	STATE mState = STATE::ALIVE;

protected:
	float mHP = 0.0f;
	float mAP = 0.0f;
	
	//상태값은 virtual로 영웅과 슬라임에게 넘길 수 있도록 다형성 어쩌구..
	virtual void tAlive();
	virtual void tWeak();
	virtual void tDead();

public:
	CUnit();
	virtual ~CUnit();

	void SetHP(float tHP);
	float GetHP();

	void SetAP(float tAP);
	float GetAP();

	virtual void DoDamaged(int tAP);

	//체력을 받아 상태값을 내보냄
	STATE CStatus(float mHP);
	//상태값을 받아 출력
	void SetState(STATE mState);

};
class CHero :public CUnit
{
private:
	int mX = 0;

protected :
	virtual void tAlive();
	virtual void tWeak();
	virtual void tDead();

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

protected:
	virtual void tAlive();
	virtual void tWeak();
	virtual void tDead();

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
	//int tWorld[5] = { 0,0,1,0,2 };

	vector<int> tWorld;

	tWorld.resize(5);
	tWorld[2] = 1;
	tWorld[4] = 2;

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
				if (tHero.GetX() > 0)
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
				if (tHero.GetX() < 4)
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

						//Hero와 Slime의 상태를 선언, 초기화 값으로는 ALIVE상태로 세팅
						STATE tHeroState = STATE::ALIVE;
						STATE tSlimeState = STATE::ALIVE;

						//Slime의 HP로 CStatus 상태를 출력하고, 출력 받은 상태 값으로 상태를 표시합니다.  
						if (tSlime.GetHP() <= 0)
						{
							tSlimeState = tSlime.CStatus(tSlime.GetHP());
							tSlime.SetState(tSlimeState);

							break;
						}
						else
						{
							tSlimeState = tSlime.CStatus(tSlime.GetHP());
							tSlime.SetState(tSlimeState);
						}

						//Hero의 HP로 CStatus 상태를 출력하고, 출력 받은 상태 값으로 상태를 표시합니다.
						if (tHero.GetHP() <= 0)
						{
							tHeroState = tHero.CStatus(tHero.GetHP());
							tHero.SetState(tHeroState);

							break;
						}
						else
						{
							tHeroState = tHero.CStatus(tHero.GetHP());
							tHero.SetState(tHeroState);
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

STATE CUnit::CStatus(float mHP)
{
	if (mHP >= 50)
	{
		return STATE::ALIVE;
	}
	else if (mHP > 0)
	{
		return STATE::WEAK;
	}
	else
	{
		return STATE::DEAD;
	}
}
void CUnit::SetState(STATE mState)
{
	switch (mState)
	{
	case ALIVE:
	{
		tAlive();
		break;
	}

	case WEAK:
	{
		tWeak();
		break;
	}
	case DEAD:
	{
		tDead();
		break;
	}
	}
}

void CUnit::tAlive()
{
	cout << "아직 쌩쌩해요" << endl;
}
void CUnit::tWeak()
{
	cout << "약해졌다." << endl;
}
void CUnit::tDead()
{
	cout << "죽었다" << endl;
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

void CHero::tAlive()
{
	cout << "용사의 체력이 많아요. 아직 쌩쌩해요" << endl;
}
void CHero::tWeak()
{
	cout << "용사가 많이 약해졌어요. 곧죽겠어요." << endl;
}
void CHero::tDead()
{
	cout << "용사가 죽었다.슬라임도 못잡는게 좁밥인가보다." << endl;
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

void CSlime::tAlive()
{
	cout << "슬라임은 아직 쌩쌩해요" << endl;
}
void CSlime::tWeak()
{
	cout << "슬라임이 약해졌어요. 생각해보면 슬라임은 원래 약해요." << endl;
}
void CSlime::tDead()
{
	cout << "슬라임이 죽었다. X를 눌러 JOY를 표하세요" << endl;
}

CSlimeBoss::CSlimeBoss()
{

}
CSlimeBoss::~CSlimeBoss()
{

}

