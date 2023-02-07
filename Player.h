#pragma once
#include "Creature.h"
class Player : virtual public Creature {
public:
	Player(int atk, int def, int hp, int minDamage, int maxDamage);
	~Player();

	//�������� ������ �� 50% �� ����. HP (�� ����� 3� ��� �� ����)
	bool Cure();
private:
	//������� ���������� ���������� �������
	int m_cureCounter;
};

