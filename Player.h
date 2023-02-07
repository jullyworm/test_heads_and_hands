#pragma once
#include "Creature.h"
class Player : virtual public Creature {
public:
	Player(int atk, int def, int hp, int minDamage, int maxDamage);
	~Player();

	//»сцел¤ет игрока на 50% от макс. HP (не более 3х раз за игру)
	bool Cure();
private:
	//—четчик количества оставшихс¤ лечений
	int m_cureCounter;
};

