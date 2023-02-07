#pragma once

#include <exception>
#include <iostream>
#include <stdlib.h>

class Creature {
public:
	~Creature();
	//�����
	int Attack(Creature& enemy);
	//�������� �� ������
	bool IsDead(); //������������� � is crossing the Styx
	//�������� �����
	int GetAttack();
	//�������� ������
	int GetDefence();
	//�������� ��������
	int GetHP();
	//�������� ���. ����
	int GetMinDamage();
	//�������� ����. ����
	int GetMaxDamage();

protected:
	Creature(int atk, int def, int hp, int minDamage, int maxDamage);	
	//���� �����
	int m_atk;
	//���� ������
	int m_def;
	//���� ��������
	int m_HP;
	//������������ ��������
	int m_maxHP;
	//����������� ����
	int m_minDamage;
	//������������ ����
	int m_maxDamage;
};