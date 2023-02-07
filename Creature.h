#pragma once

#include <exception>
#include <iostream>
#include <stdlib.h>

class Creature {
public:
	~Creature();
	//Атака
	int Attack(Creature& enemy);
	//Проверка на смерть
	bool IsDead(); //переименовать в is crossing the Styx
	//Получить атаку
	int GetAttack();
	//Получить защиту
	int GetDefence();
	//Получить здоровье
	int GetHP();
	//Получить мин. урон
	int GetMinDamage();
	//Получить макс. урон
	int GetMaxDamage();

protected:
	Creature(int atk, int def, int hp, int minDamage, int maxDamage);	
	//Очки атаки
	int m_atk;
	//Очки защиты
	int m_def;
	//Очки здоровья
	int m_HP;
	//Максимальное здоровье
	int m_maxHP;
	//Минимальный урон
	int m_minDamage;
	//Максимальный урон
	int m_maxDamage;
};