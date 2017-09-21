#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Actor.h"

class CActor;
class CEnemy;

class CActorBullet :public CBullet
{
protected:

	float mTargetX = 0;
	float mTargetY = 0;

public:

	void Setup(); // 기본 위치 세팅
	void ReadyToFire(CActor *tpActor); //시작 지점
	void Move(CEnemy *tpEnemy); //총알의 움직임
	void Display(char *tpPixel);
	//void ReadyToFire(CActor *tpActor, CEnemy *tpEnemy);//총알의 움직임
};