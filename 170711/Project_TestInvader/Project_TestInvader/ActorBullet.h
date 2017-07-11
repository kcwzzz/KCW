#pragma once
class CActor;

class CActorBullet
{

protected:
	int mX = 0;
	int mY = 0;
	bool mIsLife = false;

public:
	void Setup(); //액터의 X,Y 좌표
	void Fire(char tKey, CActor *tpActor); //조정
	void ReadyToFire(CActor *tpActor);
	void Move(); //조정
	void Clean(char *tpPixel); // 그래픽 클리어
	void Display(char *tpPixel); // 그래픽 표시
	void SetIsLife(bool tIsLife);

};

