#pragma once
class CActor;

class CActorBullet
{

protected:
	int mX = 0;
	int mY = 0;
	bool mIsLife = false;

public:
	void Setup(); //������ X,Y ��ǥ
	void Fire(char tKey, CActor *tpActor); //����
	void ReadyToFire(CActor *tpActor);
	void Move(); //����
	void Clean(char *tpPixel); // �׷��� Ŭ����
	void Display(char *tpPixel); // �׷��� ǥ��
	void SetIsLife(bool tIsLife);

};

