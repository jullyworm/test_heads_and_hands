
#include "Creature.h"

Creature::Creature(int atk, int def, int hp, int minDamage, int maxDamage) {
	m_atk = atk;
	if (atk > 20) {
		std::cerr << "Неверное значение атаки, установлено максимально возможное"<< std::endl;
		m_atk = 20;
	}
	if (atk < 1) {
		std::cerr << "Неверное значение атаки, установлено минимально возможное" << std::endl;
		m_atk = 1;
	}

	m_def = def;
	if (def > 20) {
		std::cerr << "Неверное значение защиты, установлено максимально возможное" << std::endl;
		m_def = 20;
	}
	if (def < 1) {
		std::cerr << "Неверное значение защиты, установлено минимально возможное" << std::endl;
		m_def = 1;
	}

	m_HP = hp;
	m_maxHP = hp;
	if (hp <= 0) {
		std::cerr << "Отрицательное значение здоровья, установлено минимально возможное - 1" << std::endl;
		m_HP = 1;
		m_maxHP = 1;
	}

	m_minDamage = minDamage;
	m_maxDamage = maxDamage;
	if (minDamage > maxDamage) {
		m_minDamage = maxDamage;
		m_maxDamage = minDamage;
	}
	if (m_minDamage <= 0) {
		std::cerr << "Отрицательное значение мин. урона, установлено минимально возможное - 1" << std::endl;
		m_minDamage = 1;
	}
	if (m_maxDamage <= 0) {
		std::cerr << "Отрицательное значение макс. урона, установлено минимально возможное - 1" << std::endl;
		m_maxDamage = 1;
	}
}

Creature::~Creature() {}

int Creature::GetAttack() {
	return m_atk;
}

int Creature::GetDefence() {
	return m_def;
}

int Creature::GetHP() {
	return m_HP;
}

int Creature::GetMaxDamage() {
	return m_maxDamage;
}

int Creature::GetMinDamage() {
	return m_minDamage;
}

int Creature::Attack(Creature& enemy) {
	int modAtk = this->m_atk - enemy.m_def + 1;
	//ну один раз то выпадет
	if (rand() % 6 + 1 >= 5) {
		int damage = rand() % (this->m_maxDamage - this->m_minDamage + 1) + this->m_minDamage;
		enemy.m_HP -= damage;
		return damage;
	}
	else for (int i = 1; i < modAtk; ++i) {
		if (rand() % 6 + 1 >= 5) {
			int damage = rand() % (this->m_maxDamage - this->m_minDamage + 1) + this->m_minDamage;
			enemy.m_HP -= damage;
			return damage;
		}
	}
	return 0;
}

bool Creature::IsDead() {
	if (m_HP <= 0) return true;
	else return false;
}