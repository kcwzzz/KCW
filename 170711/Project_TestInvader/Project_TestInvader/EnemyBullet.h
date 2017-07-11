#pragma once
class CEnemy;

class CEnemyBullet
{

protected :
	int mFire = 0;
	int mX = 0;
	int mY = 0;
	bool tIsLife = false;

public :
	void Setup(); //액터의 X,Y 좌표
	void Fire(CEnemy *tpEnemy );
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
};

