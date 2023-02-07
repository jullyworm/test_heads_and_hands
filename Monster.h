#pragma once
#include "Creature.h"
class Monster : virtual public Creature {
public:
	Monster(int atk, int def, int hp, int minDamage, int maxDamage);
	~Monster();
};

