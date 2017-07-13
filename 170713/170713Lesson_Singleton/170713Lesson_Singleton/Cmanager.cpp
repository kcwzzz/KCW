#include "stdafx.h"
#include "Cmanager.h"

#include <iostream>
using namespace std;

Cmanager *Cmanager::mpInstance = NULL;

Cmanager::Cmanager()
{
}


Cmanager::~Cmanager()
{
}

Cmanager *Cmanager::GetInstance()
{
	if (NULL == mpInstance)
	{
		mpInstance = new Cmanager();
		return mpInstance;
	}
	return mpInstance;
}

void Cmanager::Display()
{
	cout << "Cmanager :: Display" << endl;
}