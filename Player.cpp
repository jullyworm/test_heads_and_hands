#include "Player.h"

Player::Player(int atk, int def, int hp, int minDamage, int maxDamage) : Creature(atk, def, hp, minDamage, maxDamage), m_cureCounter(3) {
};

Player::~Player() {
};

bool Player::Cure() {
	if (m_cureCounter == 0) return false;
	--m_cureCounter;	
	if (m_HP > 0.5 * m_maxHP) m_HP = m_maxHP;
	else m_HP += round(0.5 * m_maxHP);
	return true;
}
