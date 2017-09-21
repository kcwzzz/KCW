#pragma once
class Cmanager
{
	static Cmanager *mpInstance;
public:
	Cmanager();
	~Cmanager();

	static Cmanager *GetInstance();
	//static	void ReleaseInstance();

	void Display();
};

