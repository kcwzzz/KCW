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

	void Setup(); // �⺻ ��ġ ����
	void ReadyToFire(CActor *tpActor); //���� ����
	void Move(CEnemy *tpEnemy); //�Ѿ��� ������
	void Display(char *tpPixel);
	//void ReadyToFire(CActor *tpActor, CEnemy *tpEnemy);//�Ѿ��� ������
};