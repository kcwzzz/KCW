#include "stdafx.h"
#include "Character.h"
#include "Define.h"
//#include "Enemy.h"
//#include "EnemyBoss.h"


CCharacter::CCharacter()
{
}


CCharacter::~CCharacter()
{
}

void CCharacter::Setup()
{
	
}

void CCharacter::Clean(char *tpPixel)
{
	*(tpPixel + mY*WIDTH + mX) = 0;
}

void CCharacter::MoveWithInput()
{

}

void CCharacter::Display(char *tpPixel)
{

}

int CCharacter::GetX()
{
	return mX;
}
int CCharacter::GetY()
{
	return mY;
}