#include "stdafx.h"
#include "Actor.h"

#include <iostream>

using namespace std;

CActor::CActor()
{
}


CActor::~CActor()
{
}

void CActor::DoIdle()
{
	cout << "CActor :: DoIdle" << endl;
}

void CActor::DoAttack()
{
	cout << "CActor :: Do ATTACK" << endl;

}