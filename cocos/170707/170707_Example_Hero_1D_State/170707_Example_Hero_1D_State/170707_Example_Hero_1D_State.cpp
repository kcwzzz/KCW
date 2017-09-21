
/*
created by pokpoongryu


HERO on 1Dimension. cpp version

virtual
*/

#include <iostream>

#include <vector>
#include <string>

enum {
	ALIVE = 0,
	WEAK = 1,
	DEAD = 2
};

class CUnit
{
	//private:
	//public:
protected:
	float mHP = 0.0f;
	float mAP = 0.0f;


	std::string mName = "";

	int mState = ALIVE;


public:
	CUnit();
	virtual ~CUnit();

	//private:
	//protected:
public:

	void SetName(std::string tName);
	std::string GetName();

	void SetHP(float tHP);
	float GetHP();

	void SetAP(float tAP);
	float GetAP();

	void SetState(int tState);
	int GetState();

	void DoAni();


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


	//int tWorld[5] = {0,0,1,0,2};
	std::vector<int> tWorld;

	//tWorld.reserve(5);

	//step0
	//tWorld.resize(5);
	//tWorld[0] = 0;
	//tWorld[1] = 0;
	//tWorld[2] = 1;
	//tWorld[3] = 0;
	//tWorld[4] = 2;


	//step1
	tWorld.push_back(0);
	tWorld.push_back(0);
	tWorld.push_back(1);
	tWorld.push_back(0);
	tWorld.push_back(2);



	tWorld.push_back(0);
	tWorld.push_back(0);

	//int ti = 0;
	//for( ti = 0; ti<tWorld.size(); ti++ )
	//{
	//    std::cout<<"tWorld["<<ti<<"]: "<<tWorld[ti]<<std::endl;
	//}


	int ti = 0;
	for (std::vector<int>::iterator tItor = tWorld.begin();
		tItor != tWorld.end(); ++tItor)
	{
		std::cout << "tWorld[" << ti << "]: " << (*tItor) << std::endl;

		ti++;
	}


	CHero tHero;
	tHero.SetName("HeroRyu");
	tHero.SetX(0);
	tHero.SetHP(100.0f);
	tHero.SetAP(10.0f);
	tHero.SetState(ALIVE);

	CSlime tSlime;
	tSlime.SetName("SlimeNPC");
	tSlime.SetHP(100.0f);
	tSlime.SetAP(10.0f);
	tSlime.SetState(ALIVE);

	CSlimeBoss tSlimeBoss;
	tSlimeBoss.SetName("KigOfSlimeNPC");
	tSlimeBoss.SetHP(100.0f);
	tSlimeBoss.SetAP(10.0f);
	tSlimeBoss.SetState(ALIVE);


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


					std::cout << tHero.GetName() << "<--move left" << std::endl;
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
				//if( tHero.GetX()<4)
				if (tHero.GetX() < tWorld.size() - 1)
				{
					//tHero.mX = tHero.mX + 1;
					//tHero.SetX( tHero.GetX() + 1 );
					tHero.MoveX(+1);

					std::cout << tHero.GetName() << "-->move right" << std::endl;
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
				std::cout << "No one here." << "(" << tHero.GetName() << " are on " << tHero.GetX() << " Tile)" << std::endl;
			}
			break;
			case 1:
			{
				//if slime's HP is not zero.

				//std::cout<<"Slime is here."<<"(You are on "<<tHero.mX<<" Tile)"<<std::endl;
				std::cout << "Slime is here." << "(" << tHero.GetName() << " are on " << tHero.GetX() << " Tile)" << std::endl;

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
						std::cout << tHero.GetName() << ".HP: " << tHero.GetHP() << std::endl;
						std::cout << tSlime.GetName() << ".HP: " << tSlime.GetHP() << std::endl;
						std::cout << "--------" << std::endl;


						/*
						//decide win or lose
						//if( tSlime.mHP <= 0 )
						if (tSlime.GetHP() <= 0)
						{
							std::cout << tSlime.GetName() << " is dead." << std::endl;

							break;
						}

						//if( tHero.mHP <= 0 )
						if (tHero.GetHP() <= 0)
						{
							std::cout << tHero.GetName() << " are dead." << std::endl;

							break;
						}
						*/

						if (tSlime.GetHP() <= 0)
						{
							tSlime.SetState(DEAD);
						}
						else if (tSlime.GetHP() > 0 && tSlime.GetHP() < 50)
						{
							tSlime.SetState(WEAK);
						}

						tSlime.DoAni();
						tHero.DoAni();

						if (tHero.GetHP() <= 0)
						{
							tHero.SetState(DEAD);
						}
						else if (tHero.GetHP() > 0 && tHero.GetHP() < 50)
						{
							tHero.SetState(WEAK);
						}
					}
				}
			}
			break;
			case 2:
			{
				//std::cout<<"Boss Slime is here."<<"(You are on "<<tHero.mX<<" Tile)"<<std::endl;
				std::cout << "Boss Slime is here." << "(" << tHero.GetName() << " are on " << tHero.GetX() << " Tile)" << std::endl;


				//happen the combat with boss of slimes
			}
			break;
			}



			//if( tHero.mHP <= 0 )
			if (tHero.GetHP() <= 0)
			{
				//tHero.mHP = 100.0f;
				tHero.SetHP(100.0f);

				std::cout << tHero.GetName() << " HP is recovered." << std::endl;

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


	std::cout << "GOOD BYE! " << tHero.GetName() << ". See u again." << std::endl;


	tWorld.clear();

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

		std::cout << tpHero->GetName() << " are damaged." << std::endl;
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


void CUnit::SetName(std::string tName)
{
	mName = tName;
}
std::string CUnit::GetName()
{
	return mName;
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

void CUnit::SetState(int tState)
{
	mState = tState;
}
int CUnit::GetState()
{
	return mState;
}

void CUnit::DoAni()
{
	switch (mState)
	{
	case ALIVE:
	{
		std::cout << mState << " is alive." << std::endl;
		break;
	}

	case WEAK:
	{
		std::cout << mState << " is weak." << std::endl;
		break;
	}
	case DEAD:
	{
		std::cout << mState << " is dead." << std::endl;

	}
	}
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

