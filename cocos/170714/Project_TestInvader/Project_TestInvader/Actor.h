#pragma once
#include "Character.h"

class CActorBullet;
class CEnemyBullet;

class CActor : public CCharacter
{
protected:
	CActorBullet *tActorBullet[10];

public:
	CActor();
	~CActor();
	void Setup(); //������ X,Y ��ǥ
	void MoveWithInput(char tKey); //����
	void Move(CActor *tpActor);
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	float ActorBulletX(int tBulletNum);
	float ActorBulletY(int tBulletNum);	
};