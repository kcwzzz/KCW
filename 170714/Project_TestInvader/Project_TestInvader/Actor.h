#pragma once
//#include "Character.h"
//#include "ActorBullet.h"

class CActorBullet

class CActor : public CCharacter
{
protected:
	CActorBullet *tpActorBullet[10];

public:
	void Setup(); //������ X,Y ��ǥ
	void MoveWithInput(char tKey); //����
	void Move(CActor *tpActor);
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
};

