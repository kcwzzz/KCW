#pragma once
#include "Bullet.h"

class CActor;

class CActorBullet : public CBullet
{

protected:

public:
	void Setup(); //������ X,Y ��ǥ
	void ReadyToFire(CActor *tpActor);
	void Move(CActor *tpActor); //����
	void Display(char *tpPixel); // �׷��� ǥ��
};

